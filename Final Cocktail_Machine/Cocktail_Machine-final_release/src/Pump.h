// Pump.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Pump {
private:
	int PIN_PUMP_1 = -1;  int PIN_PUMP_2 = -1; // -1은 미지정이라는 뜻

	void start_pump(int pump_num);
	int cal_pump(int amount, int pump_num);
	void set_pin_num(int a_pump_num); // pump_num을 인자로 받아서 내부에서 처리해줌
	
public:
	void work_pump(int pump_num, int amount);
	void stop_pump(int pump_num);
};


#endif