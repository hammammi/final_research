// Led.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_NeoPixel.h>

class Led {
private:
	int numpixels;
	int brightness; //�׿��ȼ� ��� ���� 0(��ο�)-255(����)
	int PIN_LED;
	int user_delay;

	Adafruit_NeoPixel strip;

	void colorWipe(uint32_t c, uint8_t wait);
	uint32_t Wheel(byte WheelPos);
	void rainbow(int t);
	void rainbowCycle(int t);

public:
	Led(int a_numpixel, int a_pin);

	void set_delay(int d);
	void set_brightness(int x);
	void off_gradually(); // ���������� ������ ���ݿ� ���� ���� �Լ�
	void off(); // �Ѳ����� ���� �Լ�
	void color(int* cock_color);//����� ���� ��Ÿ���� �Լ�
	void random_color(int t); //�� �Լ��� �ǳ� �� �Ʒ��� �� �Լ� �� �ϳ��� ����
};


#endif

