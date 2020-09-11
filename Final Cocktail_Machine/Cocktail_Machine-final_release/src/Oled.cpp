// 
// ���� �ʿ�
// 

#if 1

#include "Oled.h"
Oled::Oled() // ������
{
	idisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	idisplay.clearDisplay();
}


// *************** ���� ��� �Լ��� ****************//
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


    //Ĭ���� �̸� ���(�̸� �� �Ŵ� ���� �������� �ٹٲ�)
void Oled::display_right(char* msg)
{
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);

	char* result = strtok(msg, " ");
	//i �ʱ� ���̶� ������ ���� �ʿ�
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
	//i �ʱ� ���̶� ������ ���� �ʿ�
	int i = 30;
	while (result != NULL) {
		idisplay.setCursor(30, i); // display right �Լ����� ���⸸ �ٲ�
		idisplay.println(result);
		result = strtok(NULL, " ");
		i += 10;
	}
	idisplay.display();
}



// �ܰ� ���: ���ʿ� Ĭ���� �׸� (now / amount) ������ ������, ct_name �����ʿ� ǥ��
void Oled::display_progress(int now, int amount, char* ct_name)
{
	idisplay.clearDisplay(); //ó��

	// ���� ���� �� now�� ��ü �� amount ������ ���� �����ϸ�
	int how_much = (0 - 25) * now / amount + 30;

	// ���൵ �׸� ���� Ĭ���� �̸��� ǥ���� �ش�
	this->display_right(ct_name);

	// display_process�� ����; 5 (full) ~ 30 (empty)
	this->display_process(how_much);

	idisplay.display(); //������


}

// ******************* �⺻ �Լ� **********************//

void Oled::show() {
	idisplay.display();
}

void Oled::clear() {
	idisplay.clearDisplay();
	idisplay.display();
}


// ***************** private ������ �Լ� *******************//
    // ���ڷ� 5(full) ~ 30(empty) �� ����
void Oled::display_process(int i)
{
	// �� ���̾ƿ��� �׸��� �ڵ�
	idisplay.drawTriangle(5, 5, 55, 5, 30, 35, WHITE);
	idisplay.drawLine(30, 35, 30, 60, WHITE);
	idisplay.drawLine(15, 60, 45, 60, WHITE);

	// �ܰ踦 ǥ���ϱ� ���� ���
	int d1 = 1.2 * i - 1;
	int d2 = -1.2 * i + 63;
	idisplay.fillTriangle(i, d1, d2, d1, 30, 35, WHITE);
}
#endif