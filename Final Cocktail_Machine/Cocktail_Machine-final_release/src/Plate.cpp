// 
// 
// 

#if 1

#include "Plate.h"

int Plate::plate_x;
int Plate::plate_y;

//****************** private 지정자 함수 *******************//
void Plate::CCWmove(int steps, int dirPin, int stepPin)
{
    digitalWrite(dirPin, HIGH);
    for (int i = 0; i < steps; i++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(STEPPER_DELAY);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(STEPPER_DELAY);
    }
}


void Plate::CWmove(int steps, int dirPin, int stepPin)
{
    digitalWrite(dirPin, LOW);
    for (int i = 0; i < steps; i++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(STEPPER_DELAY);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(STEPPER_DELAY);
    }
}


void Plate::move(int steps, int xy)
{
    int dirPin = -1; // 아무것도 아니란 의미에서 -1
    int stepPin = -1;

    if (xy == 0) { // x 방향
        pinMode(7, OUTPUT);
        pinMode(6, OUTPUT);
        dirPin = 7;
        stepPin = 6;
    }
    else { // y방향
        pinMode(9, OUTPUT);
        pinMode(8, OUTPUT);
        dirPin = 9;
        stepPin = 8;
    }


    if (steps >= 0) {
        CWmove(steps, dirPin, stepPin);
    }
    else {
        CCWmove(abs(steps), dirPin, stepPin);
    }
}


//************* 생성자 및 소멸자 함수 ****************//
Plate::Plate() {
    // 엔드스탑의 핀모드 설정
    pinMode(PIN_ENDSTOP_X, INPUT);
    pinMode(PIN_ENDSTOP_Y, INPUT);
}


//****************** public 지정자 함수 ******************//

// 말그대로 스피드를 설정해줌.
void Plate::set_stepper_speed(long a_speed) {
    STEPPER_DELAY = a_speed;
}


void Plate::moveto(int px, int py) 
{
    // 문제되는 스터러의 좌표
    const int DISP_STIR_1_X = 3140;
    const int DISP_STIR_2_X = 2640;

    // 인자로 목표 좌표를 받고 (px, py)
    // 현재 좌표는 이미 정의되어 있는 것으로

    //x좌표 범위로 판별(주의_ material x좌표 설정해줄때 initial pos에서 멀수록 더 큰 값)
    if (px <= DISP_STIR_2_X) {
        // x방향, y방향 각각 차이를 계산하고 그만큼 움직인다.
        // x 방향 이동
        int x_diff = px - plate_x;
        move(x_diff, 0);
        plate_x += x_diff;

        // y 방향 이동
        int y_diff = py - plate_y;
        move(y_diff, 1);
        plate_y += y_diff;

    }

    else { // 주의해야 할 구간
        int ref_diff = 500;
        //x축 이동 -> y축 이동 -> x축 이동
        int x_diff = px - plate_x - ref_diff;
        move(x_diff, 0);
        plate_x += x_diff;

        int y_diff = py - plate_y;
        move(y_diff, 1);
        plate_y += y_diff;

        x_diff = ref_diff;
        move(x_diff, 0);
        plate_x += x_diff;
    }
}


// 호출되면 (0,0)으로 돌아가고, 좌표도 초기화됨.
void Plate::move_to_initial_position()
{
    // note: 스위치 모양이 /(우상향) 이렇게 되어 있을 때 왼쪽부터 차례대로,
    // 인풋 핀, VCC, GND 순서대로 연결한다.
	const int MOVE_STEP = -1;
    

    // y 방향의 초기화
	while (digitalRead(53) == 0) {
		move(MOVE_STEP, 1);
	}
	// end of while (y)

    // x 방향의 초기화
	while (digitalRead(52) == 0) {
		move(MOVE_STEP, 0);
	}
	// end of while (x)

    plate_x = 0;  plate_y = 0;
}


// 양을 건네주면서 호출하면, 액츄에이터가 올라가고 해당 시간만큼 기다렸다가 액츄에이터가 내려옴.
void Plate::push_dispenser(int a_amount)
{
    // 선언 및 초기화, 딜레이 타임 & 4개 상수 측정 완료
    Actuator a(22, 23);
    /*
    const int UP_TIME = 1000;
    const int HALF_UP_TIME = 1000;
    const int DOWN_TIME = 1000;
    const int FULL_WAIT_TIME = 0;
    const int HALF_WAIT_TIME = 0;*/
    
    const int UP_TIME = 5500;
    const int HALF_UP_TIME = 4200;
    const int HALF_DOWN_TIME = 4300;
    const int DOWN_TIME = 5600;
    const int FULL_WAIT_TIME = 0;
	const int HALF_WAIT_TIME = 0; 

    int num_full_push = a_amount / 30;
    int num_half_push = (a_amount % 30) / 15;

    // 작동 코드 (한번 실행 될 때마다 30mL씩 나옴)
    for (int i = 0; i < num_full_push; i++) {
        a.up();
        delay(UP_TIME);

        a.idle();
        delay(FULL_WAIT_TIME);

        a.down();
        delay(DOWN_TIME);

        a.idle();
    }

    if (num_half_push) {
        a.up();
        delay(HALF_UP_TIME);

        a.idle();
        delay(HALF_WAIT_TIME);

        a.down();
        delay(HALF_DOWN_TIME);

        a.idle();
    }

}


#endif