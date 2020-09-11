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
	// bluetooth_connect �Լ��� �����
	int select_make_recipe(String message);

public:
	// ������ �Լ� (setup)
		// ���� �¾��ϱ� (������ ��ġ, Ĭ���� ������)
	void preset_dispenser_materials();
	void preset_pump_materials();
	void preset_cocktail_recipes();

	    // �ʱ�ȭ�ϱ�
	void initialize();

	// �۵� �Լ�
	int bluetooth_connect();
	//int make_cocktail(int res_index);
	void emergency_stop();
};



#endif

