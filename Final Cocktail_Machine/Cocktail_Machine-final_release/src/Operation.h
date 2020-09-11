// Operation.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SoftwareSerial.h>
#include "Oled.h"
#include "Led.h"
#include "Technique.h"
#include "Pump.h"


class Operation {
private:
	// bluetooth_connect 함수에 내장됨
	int select_make_recipe(String message);

public:
	// 프리셋 함수 (setup)
		// 정보 셋업하기 (재료들의 위치, 칵테일 레시피)
	void preset_dispenser_materials();
	void preset_pump_materials();
	void preset_cocktail_recipes();

	    // 초기화하기
	void initialize();

	// 작동 함수
	int bluetooth_connect();
	//int make_cocktail(int res_index);
	void emergency_stop();
};



#endif

