// Technique.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Plate.h"
#include "Cocktail.h"
#include "Oled.h"
#include <Servo.h>


class Technique {
private:
	void build();
	void stir(int a_glass);

public:
	void f(Cocktail ct);
	void add_ice(int a_glass); 
	// num 은 피스톤을 움직이는 횟수, 이걸로 얼음 양 조절
	int glass;

};


#endif

