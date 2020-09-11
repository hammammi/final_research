// 
// ok
// 

#if 1

#include "Technique.h"


// 스터:
void Technique::stir(int a_glass)
{
	Oled oled;
	oled.display_center("stirring");
	Actuator a(42, 43); // 인스턴스 생성; 거품기 액츄에이터 핀 번호

	// 이동: 여러번 해야함
	Plate p;
	p.moveto(3065, 1800);
	a.down();//먼저 내려오게
	p.move(-1050, 1); // 2.1 ~ 2.2 초

	int actuator_time = 0;

	//잔 종류에 따라 높이 다르게
	//낮은것부터 1,2,3,4
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

	// 모터 ON
	pinMode(48, OUTPUT);
	pinMode(49, OUTPUT);

	
	pinMode(11, OUTPUT);
	analogWrite(11, 60);
	digitalWrite(48, HIGH);  digitalWrite(49, LOW);
	delay(5000); // 젓는 시간 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	digitalWrite(48, HIGH); digitalWrite(49, HIGH);
	delay(100); // 다 젓고 기다리는 시간 @@@@@@@@@@@@@@@@@@@@@
	a.up();
	delay(actuator_time + 3100);
	a.idle();

	oled.display_center("delivering");

	p.move(1050, 1);
	p.moveto(2500, 1800);

	// 사용자에게 전달
	p.moveto(640, 0);
	p.move_to_initial_position();
}

// 빌드: LED 색깔과 OLED 표시 설정 필요
void Technique::build() 
{
	Oled oled;

	oled.display_center("delivering");

	Plate p;
	p.moveto(640, 0);
	p.move_to_initial_position();// 사용자에게 건네 줄 마지막 좌표

}

void Technique::f(Cocktail ct) 
{
	// 받은 칵테일 정보에서 주조 기법, 잔 종류 정보를 빼옴
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


void Technique::add_ice(int a_glass)  // 서보로 해야함
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