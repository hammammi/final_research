// Oled.h
// ����: Oled �ν��Ͻ��� ���������� �������� �� ��

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <SPI.h>

class Oled {
private:
	Adafruit_SSD1306 idisplay; // �׷��� ��¿� �ν��Ͻ�
	void display_process(int i); // display_progress �Լ� ����
	void display_right(char* msg); // display_progress �Լ� ����

public:
	Oled(); // ������

	// ���� ��� �Լ�
	void display_preparing();
	void display_bluetooth();
	void display_complete();
	void display_center(char* msg); // ��� �޾��� �� Ĭ���� �̸� ǥ�ÿ�
	
	// �ܰ� ��� �Լ�
	void display_progress(int now, int amount, char* ct_name);	

	// �⺻ �Լ�
	void clear();
	void show();
};

#endif


/*
���۷��� ��ũ
https://github.com/adafruit/Adafruit_SSD1306
https://github.com/adafruit/Adafruit-GFX-Library
*/