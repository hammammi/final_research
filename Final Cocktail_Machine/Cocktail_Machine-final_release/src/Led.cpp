// 
// ok
// 

#if 1

#include "Led.h"

// 생성자 함수: led 사용을 위해 초기화함
Led::Led(int a_numpixel, int a_pin) {
    numpixels = a_numpixel;
    PIN_LED = a_pin;
    strip = Adafruit_NeoPixel(numpixels, PIN_LED, NEO_GRB + NEO_KHZ800);
    strip.begin();
    strip.clear();
    if (a_numpixel == 256) brightness = 20;
    else brightness = 50;
    set_brightness(brightness);
    strip.show();
} // note: 코드 순서 바꾸지 말 것.


// 밝기 조정 함수
void Led::set_brightness(int x) {
    strip.setBrightness(x);
}

// 딜레이 조정 함수
void Led::set_delay(int d) {
    this->user_delay = d;
}

// 순차적으로 딜레이 간격에 따라 끄는 함수
void Led::off_gradually() {
    colorWipe(strip.Color(0, 0, 0), this->user_delay);
}

// 한꺼번에 끄는 함수
void Led::off() {
    strip.clear();
    strip.show();
}

//재료색 나타나는 함수
void Led::color(int* cock_color) 
{
    colorWipe(strip.Color(cock_color[0], cock_color[1], cock_color[2]), 0);
}


//random_color()는 rainbow나 rainbowCycle 중 하나로 결정
void Led::random_color(int t) 
{
    rainbow(t);
    //rainbowCycle(t);
}



// ============ private 지정자 함수 ===============

//모든 LED를 출력가능한 모든색으로 한번씩 보여주는 동작을 한번 시행
void Led::rainbow(int t) {
    int K = t % 3000;
    if (K < 1000)
    {
        for (int i = 0; i < numpixels; i++) {
            strip.setPixelColor(i, 255 - 255*K/1000, 255*K/1000,0);
			strip.show();        
		}
        //strip.show();
    }
    else if (K < 2000)
    {
        for (int i = 0; i < numpixels; i++) {
            strip.setPixelColor(i,0, 255 - 255 * (K-1000) / 1000, 255 * (K-1000) / 1000);
			strip.show();       
		}
        //strip.show();
    }
    else
    {
        for (int i = 0; i < numpixels; i++) {
            strip.setPixelColor(i, 255 * (K-2000) / 1000, 0, 255 - 255 * (K-2000) / 1000 );
			strip.show();
        }
        //strip.show();
    }   
}

//NeoPixel에 달린 LED를 각각 다른색으로 시작하여 다양한 색으로 5번 반복
void Led::rainbowCycle(int t) {
    for (int j = 0; j < 256 * 5; j++) {
        for (int i = 0; i < numpixels; i++) {
            strip.setPixelColor(i, Wheel(((i * 256 / numpixels) + j) & 255));
			strip.show();
        }
        //strip.show();
        delay(user_delay);
    }
}

void Led::colorWipe(uint32_t c, uint8_t wait) {
    for (uint16_t i = 0; i < numpixels; i++) {
        strip.setPixelColor(i, c);
        delay(wait);
		strip.show();
    }
    //strip.show(); // 얘 원래 for문 밖에 있었는데 꺼냄
}

uint32_t Led::Wheel(byte WheelPos) {
    if (WheelPos < 85) {
        return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    }
    else if (WheelPos < 170) {
        WheelPos -= 85;
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    else {
        WheelPos -= 170;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
}



#endif