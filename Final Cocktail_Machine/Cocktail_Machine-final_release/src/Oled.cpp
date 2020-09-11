// 
// 수정 필요
// 

#if 1

#include "Oled.h"
Oled::Oled() // 생성자
{
	idisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	idisplay.clearDisplay();
}


// *************** 글자 출력 함수들 ****************//
void Oled::display_preparing()
{
	idisplay.clearDisplay();
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	idisplay.setCursor(35, 25);
	idisplay.println("Preparing");
	idisplay.setCursor(25, 35);
	idisplay.println("Please wait...");
	idisplay.display();
}


void Oled::display_bluetooth() 
{
	idisplay.clearDisplay();
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	idisplay.setCursor(35, 25);
	idisplay.println("Bluetooth");
	idisplay.setCursor(25, 35);
	idisplay.println("is connected");
	idisplay.display();
}


void Oled::display_complete() 
{
	idisplay.clearDisplay();
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	idisplay.setCursor(35, 30);
	idisplay.println("Complete!");
	idisplay.display();
}


    //칵테일 이름 출력(이름 긴 거는 띄어쓰기 기준으로 줄바꿈)
void Oled::display_right(char* msg)
{
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);

	char* result = strtok(msg, " ");
	//i 초기 값이랑 증가값 조정 필요
	int i = 30;
	while (result != NULL) {
		idisplay.setCursor(60, i);
		idisplay.println(result);
		result = strtok(NULL, " ");
		i += 10;
	}
}


void Oled::display_center(char* msg) 
{
	idisplay.clearDisplay();
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);

	char* result = strtok(msg, " ");
	//i 초기 값이랑 증가값 조정 필요
	int i = 30;
	while (result != NULL) {
		idisplay.setCursor(30, i); // display right 함수에서 여기만 바꿈
		idisplay.println(result);
		result = strtok(NULL, " ");
		i += 10;
	}
	idisplay.display();
}



// 단계 출력: 왼쪽에 칵테일 그림 (now / amount) 비율로 차있음, ct_name 오른쪽에 표시
void Oled::display_progress(int now, int amount, char* ct_name)
{
	idisplay.clearDisplay(); //처음

	// 현재 따른 양 now와 전체 양 amount 비율에 따라 스케일링
	int how_much = (0 - 25) * now / amount + 30;

	// 진행도 그림 옆에 칵테일 이름을 표시해 준다
	this->display_right(ct_name);

	// display_process의 인자; 5 (full) ~ 30 (empty)
	this->display_process(how_much);

	idisplay.display(); //마지막


}

// ******************* 기본 함수 **********************//

void Oled::show() {
	idisplay.display();
}

void Oled::clear() {
	idisplay.clearDisplay();
	idisplay.display();
}


// ***************** private 지정자 함수 *******************//
    // 인자로 5(full) ~ 30(empty) 값 받음
void Oled::display_process(int i)
{
	// 잔 레이아웃을 그리는 코드
	idisplay.drawTriangle(5, 5, 55, 5, 30, 35, WHITE);
	idisplay.drawLine(30, 35, 30, 60, WHITE);
	idisplay.drawLine(15, 60, 45, 60, WHITE);

	// 단계를 표시하기 위해 계산
	int d1 = 1.2 * i - 1;
	int d2 = -1.2 * i + 63;
	idisplay.fillTriangle(i, d1, d2, d1, 30, 35, WHITE);
}
#endif