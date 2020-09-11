// Oled.h
// 주의: Oled 인스턴스는 전역공간에 선언하지 말 것

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
	Adafruit_SSD1306 idisplay; // 그래픽 출력용 인스턴스
	void display_process(int i); // display_progress 함수 내장
	void display_right(char* msg); // display_progress 함수 내장

public:
	Oled(); // 생성자

	// 글자 출력 함수
	void display_preparing();
	void display_bluetooth();
	void display_complete();
	void display_center(char* msg); // 명령 받았을 때 칵테일 이름 표시용
	
	// 단계 출력 함수
	void display_progress(int now, int amount, char* ct_name);	

	// 기본 함수
	void clear();
	void show();
};

#endif


/*
레퍼런스 링크
https://github.com/adafruit/Adafruit_SSD1306
https://github.com/adafruit/Adafruit-GFX-Library
*/