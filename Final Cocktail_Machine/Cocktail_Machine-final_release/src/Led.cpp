// 
// ok
// 

#if 1

#include "Led.h"

// ������ �Լ�: led ����� ���� �ʱ�ȭ��
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
} // note: �ڵ� ���� �ٲ��� �� ��.


// ��� ���� �Լ�
void Led::set_brightness(int x) {
    strip.setBrightness(x);
}

// ������ ���� �Լ�
void Led::set_delay(int d) {
    this->user_delay = d;
}

// ���������� ������ ���ݿ� ���� ���� �Լ�
void Led::off_gradually() {
    colorWipe(strip.Color(0, 0, 0), this->user_delay);
}

// �Ѳ����� ���� �Լ�
void Led::off() {
    strip.clear();
    strip.show();
}

//���� ��Ÿ���� �Լ�
void Led::color(int* cock_color) 
{
    colorWipe(strip.Color(cock_color[0], cock_color[1], cock_color[2]), 0);
}


//random_color()�� rainbow�� rainbowCycle �� �ϳ��� ����
void Led::random_color(int t) 
{
    rainbow(t);
    //rainbowCycle(t);
}



// ============ private ������ �Լ� ===============

//��� LED�� ��°����� �������� �ѹ��� �����ִ� ������ �ѹ� ����
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

//NeoPixel�� �޸� LED�� ���� �ٸ������� �����Ͽ� �پ��� ������ 5�� �ݺ�
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
    //strip.show(); // �� ���� for�� �ۿ� �־��µ� ����
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