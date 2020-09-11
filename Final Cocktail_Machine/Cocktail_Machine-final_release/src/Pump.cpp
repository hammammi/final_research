// 
// ok
// 

#if 1

#include "Pump.h"


//*************************** private ������ �Լ��� +*****************//
void Pump::set_pin_num(int a_pump_num)
{
	switch (a_pump_num) {
	case 1:
		PIN_PUMP_1 = 30; break;
	case 2:
		PIN_PUMP_1 = 31; break;
	case 3:
		PIN_PUMP_1 = 32; break;
	case 4:
		PIN_PUMP_1 = 33; break;
	case 5:
		PIN_PUMP_1 = 34; break;
	case 6:
		PIN_PUMP_1 = 35; break;
	case 7:
		PIN_PUMP_1 = 36; break;
	case 8:
		PIN_PUMP_1 = 37; break;
	case 9:
		PIN_PUMP_1 = 38;  
		PIN_PUMP_2 = 39;  
		pinMode(PIN_PUMP_2, OUTPUT);
		break;
	}

	pinMode(PIN_PUMP_1, OUTPUT);
}


int Pump::cal_pump(int amount, int pump_num) 
{
	//�̰� �迭�Ⱦ��� �� 600���� ���൵ �ɰͰ���
	// ���� �󸶳� �� ��������?
	int pump_wait_time[9] = { 1000,1000,1000,1000,1000,1000,1000,1000,1000 }; // 9���� ���� ����, 
	int pump_ratio[9] = { 10,5,10,10,10,10,10,30,10 };
	
	int pump_time = pump_wait_time[pump_num - 1] + amount * pump_ratio[pump_num - 1]; //��->��
	return pump_time;
}


void Pump::start_pump(int pump_num) 
{
	this->set_pin_num(pump_num); // ���� ���� �ν��Ͻ��� �� ��ȣ ����

	if (pump_num != 9) {
		digitalWrite(PIN_PUMP_1, LOW);//LOW�� �۵�
	}
	else {
		digitalWrite(PIN_PUMP_1, HIGH);//���� ���� �޶�� ������, ���ϸ� 1,2 �ٲٱ�
		digitalWrite(PIN_PUMP_2, LOW);
	}
	
}


//******************************* public ������ �Լ� *****************************//


void Pump::stop_pump(int pump_num) 
{
	this->set_pin_num(pump_num); // ���� ���� �ν��Ͻ��� �� ��ȣ ����

	if (pump_num != 9) {
		digitalWrite(PIN_PUMP_1, HIGH); //HIGH�� ����
	}
	else { // (9���� ����)
		digitalWrite(PIN_PUMP_1, HIGH);
		digitalWrite(PIN_PUMP_2, HIGH);
	}
}


void Pump::work_pump(int pump_num, int amount) 
{
	start_pump(pump_num);
	delay(cal_pump(amount, pump_num)); //��ȯ �ð� �Է�
	stop_pump(pump_num);
}

#endif