// Plate.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Actuator.h"


class Plate {
private:
    const int STEPS_PER_REVOLUTION = 200;
    int STEPPER_DELAY = 1000;
    
    const int PIN_ENDSTOP_X = 52;
    const int PIN_ENDSTOP_Y = 53;

    void CWmove(int steps, int dp, int sp);
    void CCWmove(int steps, int dp, int sp);

    static int plate_x;
    static int plate_y;

public:
    Plate();

	void move(int steps, int xy); // xy가 0이면 x방향, 1이면 y방향

    void moveto(int px, int py);

    void move_to_initial_position();
    void set_stepper_speed(long a_speed);
    void push_dispenser(int a_amount);
};

#endif


/* 스테퍼 레퍼런스:
https://github.com/arduino-libraries/Stepper
https://www.arduino.cc/en/reference/stepper
*/