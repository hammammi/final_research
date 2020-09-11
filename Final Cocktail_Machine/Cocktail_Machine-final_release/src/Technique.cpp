// 
// ok
// 

#if 1

#include "Technique.h"


// ����:
void Technique::stir(int a_glass)
{
	Oled oled;
	oled.display_center("stirring");
	Actuator a(42, 43); // �ν��Ͻ� ����; ��ǰ�� �������� �� ��ȣ

	// �̵�: ������ �ؾ���
	Plate p;
	p.moveto(3065, 1800);
	a.down();//���� ��������
	p.move(-1050, 1); // 2.1 ~ 2.2 ��

	int actuator_time = 0;

	//�� ������ ���� ���� �ٸ���
	//�����ͺ��� 1,2,3,4
	switch (a_glass) {
	case 2:
		actuator_time = 8900;  break;
	case 3:
		actuator_time = 5900;  break;
	case 4:
		actuator_time = 2900;  break;
	}

	delay(actuator_time);
	a.idle();

	// ���� ON
	pinMode(48, OUTPUT);
	pinMode(49, OUTPUT);

	
	pinMode(11, OUTPUT);
	analogWrite(11, 60);
	digitalWrite(48, HIGH);  digitalWrite(49, LOW);
	delay(5000); // ���� �ð� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	digitalWrite(48, HIGH); digitalWrite(49, HIGH);
	delay(100); // �� ���� ��ٸ��� �ð� @@@@@@@@@@@@@@@@@@@@@
	a.up();
	delay(actuator_time + 3100);
	a.idle();

	oled.display_center("delivering");

	p.move(1050, 1);
	p.moveto(2500, 1800);

	// ����ڿ��� ����
	p.moveto(640, 0);
	p.move_to_initial_position();
}

// ����: LED ����� OLED ǥ�� ���� �ʿ�
void Technique::build() 
{
	Oled oled;

	oled.display_center("delivering");

	Plate p;
	p.moveto(640, 0);
	p.move_to_initial_position();// ����ڿ��� �ǳ� �� ������ ��ǥ

}

void Technique::f(Cocktail ct) 
{
	// ���� Ĭ���� �������� ���� ���, �� ���� ������ ����
	TechniqueMethod method = ct.get_technique();
	int glass = ct.get_glass_info(); // 1~4

	switch (method) {
	case TechniqueMethod::BUILD:
		build();
		break;
	case TechniqueMethod::STIR:
		stir(glass);
		break;
	}

}


void Technique::add_ice(int a_glass)  // ������ �ؾ���
{
		//char c = a_glass;//1~4
		switch (a_glass) {
		case 1:
			Serial2.write('0');
			break;
		case 2:
			Serial2.write('1');
			break;
		case 3:
			Serial2.write('2');
			break;
		case 4:
			Serial2.write('3');
			break;
	}
		delay(7000);

} // end of for(num)



#endif