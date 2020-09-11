/*
 Name:      Project_Cocktail_Machine.ino
 Created:   2020-07-15 오전 2:20:54
 Author:   USER
*/


// ========= user-installed headers ==========


// ========= user-defined headers ============
#include "Operation.h"


// ============ global variables =============
Operation ctrl;

//new ver
extern DispenserMaterial disp_mtrl_arr[12];
extern PumpMaterial pump_mtrl_arr[9];
extern Cocktail cocktail_arr[18];

Adafruit_NeoPixel ledpanel = Adafruit_NeoPixel(256, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledstrip1 = Adafruit_NeoPixel(55, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledstrip2 = Adafruit_NeoPixel(55, 4, NEO_GRB + NEO_KHZ800);


// ===================== setup & loop =====================
void setup()
{
	Serial2.begin(9600);

	// LED 인스턴스 설정
	ledpanel.begin();
	ledstrip1.begin();
	ledstrip2.begin();

	ledpanel.clear();
	ledpanel.setBrightness(20);
	ledpanel.show();

	ledstrip1.clear();
	ledstrip1.setBrightness(50);
	ledstrip1.show();

	ledstrip2.clear();
	ledstrip2.setBrightness(50);
	ledstrip2.show();
	Oled oled;
	// oled 화면 전부 지우기
	oled.display_preparing();
	Serial.begin(9600);

	Serial.println("\n\n= start debugging...");

	ctrl.preset_dispenser_materials();
	ctrl.preset_pump_materials();
	ctrl.preset_cocktail_recipes();
	ctrl.initialize();

	

	oled.display_center("Welcome!");
	delay(1000);
}


void loop()
{
	Oled oled;
	int flag = 1;  // 1이면 명령 기다림, 0이면 명령 탈출
	int res_index = -1; // bluetooth_connect의 리턴 값

	// 루프 처음 들어오면 led 보라색으로 바꿈
	for (int i = 0; i < 256; i++) {
		ledpanel.setPixelColor(i, 121, 0, 214);
	}
	ledpanel.show();

	for (int i = 0; i < 55; i++) {
		ledstrip1.setPixelColor(i, 121, 0, 214);
	}
	ledstrip1.show();

	for (int i = 0; i < 55; i++) {
		ledstrip2.setPixelColor(i, 121, 0, 214);
	}
	ledstrip2.show();

	// waiting 띄우고 밑에 while 진입해서 명령 기다림
	oled.display_center("waiting");

	while (flag) { // flag 1: 명령 기다림 | flag 0: 명령 받아 while 탈출
		
		res_index = ctrl.bluetooth_connect();
		// res_index notation:
		// 0~15: 미리 정의해놓은 칵테일
		// 16: 시그니쳐
		// 17: 나만의 레시피 or 랜덤 레시피
		// 18: 에러 | -1: 응답없음
		if (res_index == 18) ctrl.emergency_stop();
		else if (res_index >= 0 && res_index <= 17) {
			flag = 0;
		}

		Serial.println(res_index);

	} // end of while

	for (int i = 0; i < 3; i++) {
		twinkle_led_gradually();
	}

	//칵테일 만들기(new ver)
	Cocktail ct = cocktail_arr[res_index];

	// 컨트롤을 위한 인스턴스 생성;
	Plate plate;
	Pump pump_instance;

	// 사용하기 쉽게 칵테일 정보들을 미리 선언해준다.
	int* disp_recipe = ct.get_disp_recipe(); // 원소 12개 배열
	int* pump_recipe = ct.get_pump_recipe(); // 원소 9개 배열
	String ct_name = ct.get_name();
	char* name;
	name = ct_name.c_str();
	int* ct_color = ct.get_cocktail_color(); // 원소 3개 배열
	TechniqueMethod method = ct.get_technique();

	// 만들기 전, OLED로 칵테일 이름을 표시하고 Led로 칵테일 고유 불빛을 비춤
	oled.display_center(name);

	for (int i = 0; i < 256; i++) {
		ledpanel.setPixelColor(i, ct_color[0], ct_color[1], ct_color[2]);
	}
	ledpanel.show();

	for (int i = 0; i < 55; i++) {
		ledstrip1.setPixelColor(i, ct_color[0], ct_color[1], ct_color[2]);
	}
	ledstrip1.show();

	for (int i = 0; i < 55; i++) {
		ledstrip2.setPixelColor(i, ct_color[0], ct_color[1], ct_color[2]);
	}
	ledstrip2.show();

	delay(3000);

	// 전체 양이 얼마나 되는지 체크 (oled 표시용)
	int total_amount = 0;
	int now_amount = 0;

	for (int i = 0; i < 12; i++) {
		total_amount += disp_recipe[i];
	}
	for (int i = 0; i < 9; i++) {
		total_amount += pump_recipe[i];
	} // total amount 계산 완료

	oled.display_center("ice");
	plate.moveto(180, 1200);
	Technique t;
	t.add_ice(ct.get_glass_info());
	

	// 잔량 체크 코드를 지우고 전체 양을 계산하는 코드를 넣음. OLED에 진행도를 표시하기 위함
	// 디스펜서를 사용하는 재료부터 시작
	for (int i = 0; i < 12; i++) {
		if (disp_recipe[i]) { // 만약 해당 재료의 레시피가 0이면 그 재료는 무시함
		   // 쉬운 코딩을 위해 해당 레시피의 인스턴스 선언
			DispenserMaterial material = disp_mtrl_arr[i];
			String mtrl_name = material.get_name();
			char* c_mtrl_name = mtrl_name.c_str();
			int* mtrl_color = material.get_rgb();

			// OLED 표시
			oled.display_progress(now_amount, total_amount, c_mtrl_name);
			now_amount += disp_recipe[i];

			for (int i = 0; i < 256; i++) {
				ledpanel.setPixelColor(i, mtrl_color[0], mtrl_color[1], mtrl_color[2]);
			}
			ledpanel.show();

			for (int i = 0; i < 55; i++) {
				ledstrip1.setPixelColor(i, mtrl_color[0], mtrl_color[1], mtrl_color[2]);
			}
			ledstrip1.show();

			for (int i = 0; i < 55; i++) {
				ledstrip2.setPixelColor(i, mtrl_color[0], mtrl_color[1], mtrl_color[2]);
			}
			ledstrip2.show();

			// Led 색깔 재료 고유의 색으로 바꾸기

			// 좌표 설정하고, plate 움직이기
			plate.moveto(material.get_pos_x(), material.get_pos_y());
			delay(100);

			// 좌표로 이동했으면 액츄에이터 작동 (해당 레시피의 양에 해당하는 시간만큼)
			plate.push_dispenser(disp_recipe[i]);

			delay(100);
		} // 재료 하나의 루프가 끝났으면, 다시 다른 재료로 이 루프를 또 실행
	}

	// 디스펜서 다음 펌프를 사용하는 재료 담기
	for (int i = 0; i < 9; i++) {
		if (pump_recipe[i]) { // 만약 해당 재료의 레시피가 0이면 그 재료는 무시함
		   // 쉬운 코딩을 위해 해당 레시피의 인스턴스 선언
			PumpMaterial material = pump_mtrl_arr[i];
			String mtrl_name = material.get_name();
			char* c_mtrl_name = mtrl_name.c_str();
			int* mtrl_color = material.get_rgb();

			// OLED 표시
			oled.display_progress(now_amount, total_amount, c_mtrl_name);
			now_amount += pump_recipe[i];

			// Led 색깔 재료 고유의 색으로 바꾸기
			for (int i = 0; i < 256; i++) {
				ledpanel.setPixelColor(i, mtrl_color[0], mtrl_color[1], mtrl_color[2]);
			}
			ledpanel.show();

			for (int i = 0; i < 55; i++) {
				ledstrip1.setPixelColor(i, mtrl_color[0], mtrl_color[1], mtrl_color[2]);
			}
			ledstrip1.show();

			for (int i = 0; i < 55; i++) {
				ledstrip2.setPixelColor(i, mtrl_color[0], mtrl_color[1], mtrl_color[2]);
			}
			ledstrip2.show();

			// 좌표 설정하고, plate 움직이기
			plate.moveto(material.get_pos_x(), material.get_pos_y());
			delay(100);

			// 좌표로 이동했으면 !펌프! 작동 (해당 레시피의 양에 해당하는 시간만큼)
			pump_instance.work_pump(i + 1, pump_recipe[i]); //1~9
			delay(100);
		} // 재료 하나의 루프가 끝났으면, 다시 다른 재료로 이 루프를 또 실행
	}

	oled.display_progress(now_amount, total_amount, name);
	delay(1000);;

	// 칵테일 고유색 설정하기
	for (int i = 0; i < 256; i++) {
		ledpanel.setPixelColor(i, ct_color[0], ct_color[1], ct_color[2]);
	}
	ledpanel.show();

	for (int i = 0; i < 55; i++) {
		ledstrip1.setPixelColor(i, ct_color[0], ct_color[1], ct_color[2]);
	}
	ledstrip1.show();

	for (int i = 0; i < 55; i++) {
		ledstrip2.setPixelColor(i, ct_color[0], ct_color[1], ct_color[2]);
	}
	ledstrip2.show();

	// 테크닉 인스턴스에다가 위에서 선언해준 method를 전달해 그 명령 수행
	t.f(ct);
	// 칵테일 완성!!
	oled.display_complete();    // OLED에 완료했다고 표시
	
	// 루프 처음 들어오면 led 황금색으로 바꿈
	for (int i = 0; i < 256; i++) {
		ledpanel.setPixelColor(i, 255, 215, 0);
	}
	ledpanel.show();

	for (int i = 0; i < 55; i++) {
		ledstrip1.setPixelColor(i, 255, 215, 0);
	}
	ledstrip1.show();

	for (int i = 0; i < 55; i++) {
		ledstrip2.setPixelColor(i, 255, 215, 0);
	}
	ledstrip2.show();

	delay(5000);

	// make_cocktail 끝!


} // end of loop



//***** 사용자 정의 함수 ******//
//********************** LED 빙글빙글을 위한 함수 ********************//
//모든 LED를 출력가능한 모든색으로 한번씩 보여주는 동작을 한번하는 함수
// @@@@@@@@@@@@@@@@@@@@@@@@@@@ 문제: 스트립이랑 매트릭스 소자 개수가 안 맞아서 일단 스트립만 했음.
/*
void rainbow(int wait) {
	uint16_t i, j;

	for (j = 0; j < 256; j++) {
		for (i = 0; i < 256; i++) {
			ledstrip1.setPixelColor(i, Wheel((i + j) & 255));
			ledstrip2.setPixelColor(i, Wheel((i + j) & 255));
			ledpanel.setPixelColor(i, Wheel((i + j) & 255));
		}
		ledstrip1.show();
		ledstrip2.show();
		ledpanel.show();
		delay(wait);
	}
}


//255가지의 색을 나타내는 함수
uint32_t Wheel(byte WheelPos) {
	if (WheelPos < 85) {
		return ledstrip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
	}
	else if (WheelPos < 170) {
		WheelPos -= 85;
		return ledstrip1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
	}
	else {
		WheelPos -= 170;
		return ledstrip1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
	}
}
*/
void twinkle_led_gradually() // 랜덤 색깔으로 한 번 깜빡임
{
	Serial.println(0);
	// 랜덤 색깔 뽑기
	int r_random = random(10);
	int g_random = random(10);
	int b_random = random(10);

	// 서서히 밝아지는 코드
	for (int i = 0; i < 25; i += 1) {
		// 색깔 설정해놓기
		for (int j = 0; j < 55; j++) {
			ledstrip1.setPixelColor(j, r_random * i, g_random * i, b_random * i);
			ledstrip2.setPixelColor(j, r_random * i, g_random * i, b_random * i);
		}
		for (int j = 0; j < 256; j++) {
			ledpanel.setPixelColor(j, r_random * i, g_random * i, b_random * i);
		}

		Serial.println(1);
		ledstrip1.show();
		ledstrip2.show();
		ledpanel.show();
	}

	// 서서히 어두워지는 코드
	for (int i = 25; i >= 0; i -= 1) {
		// 색깔 설정해놓기
		for (int j = 0; j < 55; j++) {
			ledstrip1.setPixelColor(j, r_random * i, g_random * i, b_random * i);
			ledstrip2.setPixelColor(j, r_random * i, g_random * i, b_random * i);
		}
		for (int j = 0; j < 256; j++) {
			ledpanel.setPixelColor(j, r_random * i, g_random * i, b_random * i);
		}

		Serial.println(1);
		ledstrip1.show();
		ledstrip2.show();
		ledpanel.show();
	}


	// 혹시 모를 int 값이 0이 아닐 경우가 있기 때문에 밝기 0으로 설정하는 코드
	ledstrip1.clear();
	ledstrip1.show();
	ledstrip2.clear();
	ledstrip2.show();
	ledpanel.clear();
	ledpanel.show();
}

void twinkle_led() {

	int r_random = random(256);
	int g_random = random(256);
	int b_random = random(256);


	for (int i = 0; i < 256; i++) {
		ledpanel.setPixelColor(i, r_random, g_random, b_random);
	}
	ledpanel.show();
	for (int i = 0; i < 55; i++) {
		ledstrip1.setPixelColor(i, r_random, g_random, b_random);
		ledstrip2.setPixelColor(i, r_random, g_random, b_random);
	}
	ledstrip2.show();
	ledstrip1.show();

	delay(200);

	ledpanel.clear();
	ledpanel.show();
	ledstrip1.clear();
	ledstrip1.show();
	ledstrip2.clear();
	ledstrip2.show();

	delay(200);
}