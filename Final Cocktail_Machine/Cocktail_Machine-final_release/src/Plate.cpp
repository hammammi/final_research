// 
// 
// 

#if 1

#include "Plate.h"

int Plate::plate_x;
int Plate::plate_y;

//****************** private ������ �Լ� *******************//
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
    int dirPin = -1; // �ƹ��͵� �ƴ϶� �ǹ̿��� -1
    int stepPin = -1;

    if (xy == 0) { // x ����
        pinMode(7, OUTPUT);
        pinMode(6, OUTPUT);
        dirPin = 7;
        stepPin = 6;
    }
    else { // y����
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


//************* ������ �� �Ҹ��� �Լ� ****************//
Plate::Plate() {
    // ���彺ž�� �ɸ�� ����
    pinMode(PIN_ENDSTOP_X, INPUT);
    pinMode(PIN_ENDSTOP_Y, INPUT);
}


//****************** public ������ �Լ� ******************//

// ���״�� ���ǵ带 ��������.
void Plate::set_stepper_speed(long a_speed) {
    STEPPER_DELAY = a_speed;
}


void Plate::moveto(int px, int py) 
{
    // �����Ǵ� ���ͷ��� ��ǥ
    const int DISP_STIR_1_X = 3140;
    const int DISP_STIR_2_X = 2640;

    // ���ڷ� ��ǥ ��ǥ�� �ް� (px, py)
    // ���� ��ǥ�� �̹� ���ǵǾ� �ִ� ������

    //x��ǥ ������ �Ǻ�(����_ material x��ǥ �������ٶ� initial pos���� �ּ��� �� ū ��)
    if (px <= DISP_STIR_2_X) {
        // x����, y���� ���� ���̸� ����ϰ� �׸�ŭ �����δ�.
        // x ���� �̵�
        int x_diff = px - plate_x;
        move(x_diff, 0);
        plate_x += x_diff;

        // y ���� �̵�
        int y_diff = py - plate_y;
        move(y_diff, 1);
        plate_y += y_diff;

    }

    else { // �����ؾ� �� ����
        int ref_diff = 500;
        //x�� �̵� -> y�� �̵� -> x�� �̵�
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


// ȣ��Ǹ� (0,0)���� ���ư���, ��ǥ�� �ʱ�ȭ��.
void Plate::move_to_initial_position()
{
    // note: ����ġ ����� /(�����) �̷��� �Ǿ� ���� �� ���ʺ��� ���ʴ��,
    // ��ǲ ��, VCC, GND ������� �����Ѵ�.
	const int MOVE_STEP = -1;
    

    // y ������ �ʱ�ȭ
	while (digitalRead(53) == 0) {
		move(MOVE_STEP, 1);
	}
	// end of while (y)

    // x ������ �ʱ�ȭ
	while (digitalRead(52) == 0) {
		move(MOVE_STEP, 0);
	}
	// end of while (x)

    plate_x = 0;  plate_y = 0;
}


// ���� �ǳ��ָ鼭 ȣ���ϸ�, �������Ͱ� �ö󰡰� �ش� �ð���ŭ ��ٷȴٰ� �������Ͱ� ������.
void Plate::push_dispenser(int a_amount)
{
    // ���� �� �ʱ�ȭ, ������ Ÿ�� & 4�� ��� ���� �Ϸ�
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

    // �۵� �ڵ� (�ѹ� ���� �� ������ 30mL�� ����)
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