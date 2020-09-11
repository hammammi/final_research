// 
// ����Ʈ �� Ŭ�������� ���� �ٲ�, ������ �굵 ���� �ٲ����.
// 

#if 1

#include "Operation.h"
#include <stdint.h>

// global variable
DispenserMaterial disp_mtrl_arr[12];
PumpMaterial pump_mtrl_arr[9];
Cocktail cocktail_arr[18];


// *************************** ������ �Լ��� *************************

    // ���� �¾��ϱ� (������ ��ġ, Ĭ���� ������)
void Operation::preset_dispenser_materials()
{
	// dispenser_material_instance ����
	// DispenserMaterial(String aname, int a_num, double a_remain, int ar, int ag, int ab)
	// ���� ���������� pump_mtrl_arr �迭�� ���� ����
	DispenserMaterial dispmaterial_instance1("Vodka", 1, 750, 150, 75, 0);
	disp_mtrl_arr[0] = dispmaterial_instance1;

	DispenserMaterial dispmaterial_instance2("Gin", 2, 750, 80, 188, 223);
	disp_mtrl_arr[1] = dispmaterial_instance2;

	DispenserMaterial dispmaterial_instance3("WhiteRum", 3, 750, 250, 250, 250);
	disp_mtrl_arr[2] = dispmaterial_instance3;

	DispenserMaterial dispmaterial_instance4("Tequila", 4, 750, 150, 75, 0);
	disp_mtrl_arr[3] = dispmaterial_instance4;

	DispenserMaterial dispmaterial_instance5("Cointreau", 5, 750, 150, 75, 0);
	disp_mtrl_arr[4] = dispmaterial_instance5;

	DispenserMaterial dispmaterial_instance6("Smirnoff Green Apple", 6, 750, 129, 193, 71);
	disp_mtrl_arr[5] = dispmaterial_instance6;

	DispenserMaterial dispmaterial_instance7("Mojito", 7, 360, 130, 225, 120);
	disp_mtrl_arr[6] = dispmaterial_instance7;

	DispenserMaterial dispmaterial_instance8("Peach", 8, 750, 255, 102, 102);
	disp_mtrl_arr[7] = dispmaterial_instance8;

	DispenserMaterial dispmaterial_instance9("Blue Curacao", 9, 750, 60, 60, 210);
	disp_mtrl_arr[8] = dispmaterial_instance9;

	DispenserMaterial dispmaterial_instance10("Jack Daniel", 10, 500, 150, 75, 0);
	disp_mtrl_arr[9] = dispmaterial_instance10;

	DispenserMaterial dispmaterial_instance11("Lime", 11, 750, 129, 193, 71);
	disp_mtrl_arr[10] = dispmaterial_instance11;

	DispenserMaterial dispmaterial_instance12("Raspberry", 12, 750, 150, 75, 0);
	disp_mtrl_arr[11] = dispmaterial_instance12;

}

void Operation::preset_pump_materials()
{
	//pump_material_instance ����
	//PumpMaterial(String aname, int a_num, double a_remain, int ar, int ag, int ab)
	// ���� ���������� pump_mtrl_arr �迭�� ���� ����
	PumpMaterial pumpmaterial_instance1("Kkanari", 13, 750, 200, 165, 80);
	pump_mtrl_arr[0] = pumpmaterial_instance1;

	PumpMaterial pumpmaterial_instance2("Soybean sauce", 14, 750, 116, 94, 67);
	pump_mtrl_arr[1] = pumpmaterial_instance2;

	PumpMaterial pumpmaterial_instance3("Pinebud juice", 15, 750, 66, 105, 47);
	pump_mtrl_arr[2] = pumpmaterial_instance3;

	PumpMaterial pumpmaterial_instance4("Oyster sauce", 16, 750, 166, 144, 116);
	pump_mtrl_arr[3] = pumpmaterial_instance4;

	PumpMaterial pumpmaterial_instance5("Sweet Sour", 17, 750, 219, 156, 115);
	pump_mtrl_arr[4] = pumpmaterial_instance5;

	PumpMaterial pumpmaterial_instance6("Vinegar", 18, 750, 182, 119, 40);
	pump_mtrl_arr[5] = pumpmaterial_instance6;

	PumpMaterial pumpmaterial_instance7("Coke", 19, 750, 254, 0, 26);
	pump_mtrl_arr[6] = pumpmaterial_instance7;

	PumpMaterial pumpmaterial_instance8("Orange juice", 20, 750, 255, 165, 0);
	pump_mtrl_arr[7] = pumpmaterial_instance8;

	PumpMaterial pumpmaterial_instance9("Lemon juice", 21, 750, 255, 247, 0);
	pump_mtrl_arr[8] = pumpmaterial_instance9;


}

void Operation::preset_cocktail_recipes()
{
	//cocktail_instance ����
	// �̸��� "Martini" �̷��� �ް�, �迭�� �ּҷ� ����. ����� BUILD STIR �̷��� ���ָ� ��.
	//Cocktail(String name, int a_disp_mtrl[], int a_pump_mtrl[],   TechniqueMethod a_method, int glass, int a_r, int a_g, int a_b);
	//glass�� ���� �ͺ��� 1,2,3,4
	int disp_mtrl1[12] = { 0,0,45,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl1[9] = {0,0,20,0,0,0,0,0,0};
	Cocktail cocktail_instance1("Daiquiri", disp_mtrl1, pump_mtrl1, TechniqueMethod::STIR, 4, 200, 255, 150);//4
	cocktail_arr[0] = cocktail_instance1;

	int disp_mtrl2[12] = { 15,15,15,15,15,0,0,0,0,0,0,0 }; //@@@@@@@@@@@@@@@@@@@
	int pump_mtrl2[9] = { 0,0,0,0,20,0,60,0,30 };
	Cocktail cocktail_instance2("Longisland", disp_mtrl2, pump_mtrl2, TechniqueMethod::BUILD, 3, 115, 60, 60);//3
	cocktail_arr[1] = cocktail_instance2;

	int disp_mtrl3[12] = { 0,0,45,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl3[9] = { 15,0,15,0,0,0,0,0,0 };
	Cocktail cocktail_instance3("Bacardi", disp_mtrl3, pump_mtrl3, TechniqueMethod::STIR, 4, 255, 255, 255);//4
	cocktail_arr[2] = cocktail_instance3;

	int disp_mtrl4[12] = { 30,0,0,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl4[9] = { 30,0,0,0,0,30,0,0,0 };
	Cocktail cocktail_instance4("SeaBreeze", disp_mtrl4, pump_mtrl4, TechniqueMethod::BUILD, 2, 215, 60, 85);//2
	cocktail_arr[3] = cocktail_instance4;

	int disp_mtrl5[12] = { 0,0,0,0,0,45,0,0,0,0,0,0 };
	int pump_mtrl5[9] = { 0,0,0,0,60,0,0,0,0 };
	Cocktail cocktail_instance5("AppleMartini", disp_mtrl5, pump_mtrl5, TechniqueMethod::STIR, 4, 145, 220, 145);//4
	cocktail_arr[4] = cocktail_instance5;

	int disp_mtrl6[12] = { 30,0,0,0,15,0,0,0,0,0,0,15 };
	int pump_mtrl6[9] = { 0,0,0,0,0,0,0,0,0 };
	Cocktail cocktail_instance6("Cosmopolitan", disp_mtrl6, pump_mtrl6, TechniqueMethod::STIR, 4, 220, 145, 160);//4
	cocktail_arr[5] = cocktail_instance6;

	int disp_mtrl7[12] = { 0,0,0,30,0,0,0,0,0,0,0,0 };
	int pump_mtrl7[9] = { 15,0,0,0,90,0,0,0,0 };
	Cocktail cocktail_instance7("TequilaSunrise", disp_mtrl7, pump_mtrl7, TechniqueMethod::BUILD, 2, 255, 155, 55);//2
	cocktail_arr[6] = cocktail_instance7;

	int disp_mtrl8[12] = { 0,45,0,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl8[9] = { 0,15,0,0,0,0,15,0,0 };
	Cocktail cocktail_instance8("TomCollins", disp_mtrl8, pump_mtrl8, TechniqueMethod::STIR, 2, 210, 240, 200);//2
	cocktail_arr[7] = cocktail_instance8;

	int disp_mtrl9[12] = {0,0,15,0,0,0,0,0,0,0,45,0};
	int pump_mtrl9[9] = {0,0,30,0,0,0,30,0,0 };
	Cocktail cocktail_instance9("Mojito", disp_mtrl9, pump_mtrl9, TechniqueMethod::BUILD, 3, 185, 230, 170);//3
	cocktail_arr[8] = cocktail_instance9;

	int disp_mtrl10[12] = {30,0,0,0,0,0,0,0,0,0,0,0};
	int pump_mtrl10[9] = {0,0,0,0,0,120,0,0,0 };
	Cocktail cocktail_instance10("Salty Dog", disp_mtrl10, pump_mtrl10, TechniqueMethod::BUILD, 1, 230, 200, 170);//1
	cocktail_arr[9] = cocktail_instance10;

	int disp_mtrl11[12] = {30,0,0,0,0,0,0,0,0,0,0,0};
	int pump_mtrl11[9] = {0,0,0,0,0,0,0,120,0 };
	Cocktail cocktail_instance11("ScrewDriver", disp_mtrl11, pump_mtrl11, TechniqueMethod::STIR, 3, 255, 210, 1);//2
	cocktail_arr[10] = cocktail_instance11;

	int disp_mtrl12[12] = { 0,0,0,30,15,0,0,0,0,0,0,0 };
	int pump_mtrl12[9] = { 0,0,15,0,0,0,0,0,0 };
	Cocktail cocktail_instance12("Margarita", disp_mtrl12, pump_mtrl12, TechniqueMethod::STIR, 4, 205, 245, 200);//4
	cocktail_arr[11] = cocktail_instance12;

	int disp_mtrl13[12] = {0,0,0,0,0,0,0,30,0,0,0,0};
	int pump_mtrl13[9] = {30,0,0,60,0,0,0,0,0 };
	Cocktail cocktail_instance13("PeachCrush", disp_mtrl13, pump_mtrl13, TechniqueMethod::BUILD, 3, 255, 160, 160);//3
	cocktail_arr[12] = cocktail_instance13;

	int disp_mtrl14[12] = { 30,0,0,0,0,0,0,0,30,0,0,0 };
	int pump_mtrl14[9] = { 0,0,0,0,0,0,0,100,0 };
	Cocktail cocktail_instance14("Blue Romance", disp_mtrl14, pump_mtrl14, TechniqueMethod::STIR, 3, 0, 130, 190);//3
	cocktail_arr[13] = cocktail_instance14;

	int disp_mtrl15[12] = {0,0,0,0,0,0,0,0,0,0,0,15};
	int pump_mtrl15[9] = {0,0,0,0,0,45,45,0,0 };
	Cocktail cocktail_instance15("Jack Honey Mong", disp_mtrl15, pump_mtrl15, TechniqueMethod::BUILD, 1, 175, 95, 95);//1
	cocktail_arr[14] = cocktail_instance15;

	int disp_mtrl16[12] = { 0,0,0,0,0,0,15,0,0,60,0,0 };
	int pump_mtrl16[9] = { 0,0,0,0,0,0,0,0,0 };
	Cocktail cocktail_instance16("K-Cocktail", disp_mtrl16, pump_mtrl16, TechniqueMethod::BUILD, 2, 230, 210, 140);//2
	cocktail_arr[15] = cocktail_instance16;

	// ���⿡ �ޱ״��� Ĭ���� ������ �߰�(17��°)
}


// ************************* �ʱ�ȭ �Լ� *************************
// ���� ���¿� ��� ���� �ʱ�ȭ�� �Ͽ� ��밡���� ���·� ��������

void Operation::initialize() 
{
	// ���� �۵� ���� (1~8)
	Pump pump_instance;
	for (int i = 0; i < 9; i++) {
		pump_instance.stop_pump(i + 1);
	}

	// ���ͷ� ���� �극��ũ
	pinMode(48, OUTPUT);  digitalWrite(48, HIGH);
	pinMode(49, OUTPUT);  digitalWrite(49, HIGH);


	// ���ͷ� �������� �� ���� �ö󰡱�
	Actuator stir_act(42, 43);
	stir_act.up();
	// ���漭�� �������� �ʱ� ��ġ�� ��!
	Actuator disp_act(22, 23);
	disp_act.down();
	delay(5000);
	/* ���߿� �������� ��ġ �����ϰ� �Ǹ� �ּ� ���� ����
	disp_act.up();
	delay(2300);
	disp_act.idle();
	*/

	// �÷���Ʈ ��ġ (0,0)���� �ʱ�ȭ
	Plate p;
	p.move_to_initial_position();
}


// ********************** �۵��� ���� �Լ��� *********************

int Operation::select_make_recipe(String message)
{
	Serial.println(message);

	// �켱 message �� ���� & �� �ִ��� �˻�, ������ 18�� ��ȯ

	 // �־��� ���� -> �� ������ �迭 ����
	int disp_mtrl_amount[12] = { 0, };
	int pump_mtrl_amount[9] = { 0, };

	int i = 2; // message�� �ε���

	while (message[i] != '&') { // �޼����� ������ �˻�, ���̸� ��������
		String index = "";
		String amount = "";

		while (message[i] != '%') { // index ���� �޾ƿ���
			index += message[i];
			i++;
		} // end of internal while, %�� ������ ��������
		i++; // ������ index�� '%'�� ����Ű�� �����Ƿ� �Ʒ����� �ϳ� ����������.

		while (message[i] != '%' && message[i] != '&') { // amount ���� �޾ƿ���
			amount += message[i];
			i++;
		} // end of internal while, %�� ������ ��������

		// String �ڷ����� index�� amount�� int �ڷ������� �ٲ�
		int index_int = index.toInt();
		int amount_int = amount.toInt();

		// index�� 1~12�̸� disp mtrl, 13~21�̸� pump mtrl
		if (0 <= index_int && index_int <= 11) {
			disp_mtrl_amount[index_int - 1] = amount_int;
			Serial.print("dispenser material; ");
			Serial.print(index_int);
			Serial.print(" : ");
			Serial.println(amount_int);
		}
		else if (12 <= index_int && index_int <= 20) {
			pump_mtrl_amount[index_int - 13] = amount_int;
			Serial.print("pump material; ");
			Serial.print(index_int);
			Serial.print(" : ");
			Serial.println(amount_int);
		}

		if (message[i] == '&') break;
		i++;

	} // end of while: disp_mtrl_amount �� pump_mtrl_amount �迭 ���� �Ϸ�

	// Ĭ���� �ν��Ͻ� ����
	Cocktail my_cocktail("my_cocktail", disp_mtrl_amount, pump_mtrl_amount,
		TechniqueMethod::BUILD, 4, 121, 0, 214); // ������ ������ ��ũ�а� @@@@@@@@@@@@@@@@@@@@@2

	 // Ĭ���� �迭 18��° ����(index 17)�� �Ҵ�
	cocktail_arr[17] = my_cocktail;

	// ����
	return 17;
}

int Operation::bluetooth_connect() 
{
	Serial1.begin(9600);

	if (Serial1.available()) {
		String str = "";
		while (Serial1.available()) {
			char ch = Serial1.read();
			delay(100); // ���ۿ� ���� �����͸� �������� �����ϴ� ���� ��ٸ��� �ð�
			str.concat(ch);
		}

		//select_sample
		if (str.charAt(0) == '$') {
			String res = "";
			int i = 1;
			while (str.charAt(i) != '$') {
				char ch = str.charAt(i);
				res.concat(ch);
				i++;
			}
			return (res.toInt() - 1); // 0~16 (���� ������ 16�� + �ñ״��� 1�� = 17��)
		}

		//make_recipe
		else if (str.charAt(0) == '&') {
			return select_make_recipe(str); // 17 (������ ���ǽ� or ���� ������)
		}

		else
			return 18; // ������� ��ȣ�� �޾����� ��ȿ�� ���� �ƴ� (����)
	}

	return -1; // ������� ��ȣ�� ���� ���� -> main���� ���� �ݺ�
}


/*
// Ĭ������ ����� �Լ�
int Operation::make_cocktail(int result_index)
{
	// Ĭ���� �迭�� ����� ������ result_index�� ��������
	Cocktail ct = cocktail_arr[result_index];

	// ��Ʈ���� ���� �ν��Ͻ� ����;
	Oled oled;
	Plate plate;
	Pump pump_instance;

	// ����ϱ� ���� Ĭ���� �������� �̸� �������ش�.
	int* disp_recipe = ct.get_disp_recipe(); // ���� 12�� �迭
	int* pump_recipe = ct.get_pump_recipe(); // ���� 9�� �迭
	String ct_name = ct.get_name();
	char* name;
	name = ct_name.c_str();
	int* ct_color = ct.get_cocktail_color(); // ���� 3�� �迭
	TechniqueMethod method = ct.get_technique();

	// ����� ��, OLED�� Ĭ���� �̸��� ǥ���ϰ� Led�� Ĭ���� ���� �Һ��� ����
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

	// ��ü ���� �󸶳� �Ǵ��� üũ (oled ǥ�ÿ�)
	int total_amount = 0;
	int now_amount = 0;

	for (int i = 0; i < 12; i++) {
		total_amount += disp_recipe[i];
	}
	for (int i = 0; i < 9; i++) {
		total_amount += pump_recipe[i];
	} // total amount ��� �Ϸ�

	oled.display_center("ice");
	plate.moveto(190,1200);
	Technique t;
	t.add_ice(ct.get_glass_info());
	

	// �ܷ� üũ �ڵ带 ����� ��ü ���� ����ϴ� �ڵ带 ����. OLED�� ���൵�� ǥ���ϱ� ����
	// ���漭�� ����ϴ� ������ ����
	for (int i = 0; i < 12; i++) {
		if (disp_recipe[i]) { // ���� �ش� ����� �����ǰ� 0�̸� �� ���� ������
		   // ���� �ڵ��� ���� �ش� �������� �ν��Ͻ� ����
			DispenserMaterial material = disp_mtrl_arr[i];
			String mtrl_name = material.get_name();
			char* c_mtrl_name = mtrl_name.c_str();
			int* mtrl_color = material.get_rgb();

			// OLED ǥ��
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

			// Led ���� ��� ������ ������ �ٲٱ�

			// ��ǥ �����ϰ�, plate �����̱�
			plate.moveto(material.get_pos_x(), material.get_pos_y());
			delay(100);

			// ��ǥ�� �̵������� �������� �۵� (�ش� �������� �翡 �ش��ϴ� �ð���ŭ)
			plate.push_dispenser(disp_recipe[i]);

			delay(100);
		} // ��� �ϳ��� ������ ��������, �ٽ� �ٸ� ���� �� ������ �� ����
	}

	// ���漭 ���� ������ ����ϴ� ��� ���
	for (int i = 0; i < 9; i++) {
		if (pump_recipe[i]) { // ���� �ش� ����� �����ǰ� 0�̸� �� ���� ������
		   // ���� �ڵ��� ���� �ش� �������� �ν��Ͻ� ����
			PumpMaterial material = pump_mtrl_arr[i];
			String mtrl_name = material.get_name();
			char* c_mtrl_name = mtrl_name.c_str();

			// OLED ǥ��
			oled.display_progress(now_amount, total_amount, c_mtrl_name);
			now_amount += pump_recipe[i];

			int* mtrl_color = material.get_rgb();

			// OLED ǥ��
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

			// Led ���� ��� ������ ������ �ٲٱ�

			// ��ǥ �����ϰ�, plate �����̱�
			plate.moveto(material.get_pos_x(), material.get_pos_y());
			delay(100);

			// ��ǥ�� �̵������� !����! �۵� (�ش� �������� �翡 �ش��ϴ� �ð���ŭ)
			pump_instance.work_pump(i + 1, pump_recipe[i]); //1~9
			delay(100);
		} // ��� �ϳ��� ������ ��������, �ٽ� �ٸ� ���� �� ������ �� ����
	}

	oled.display_progress(now_amount, total_amount, name);
	delay(1000);;
	
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


	// ��ũ�� �ν��Ͻ����ٰ� ������ �������� method�� ������ �� ��� ����
	t.f(ct);
	// Ĭ���� �ϼ�!!
	oled.display_complete();    // OLED�� �Ϸ��ߴٰ� ǥ��
	// ********* ������ ���ۺ��� (��Ʈ����)
	rainbow(10);
	rainbow(10);
	rainbow(10);

	return 1; // ���� �ڵ� 1: Ĭ���� �ϼ�
}*/ 
// end of make_cocktail


void Operation::emergency_stop()
{
	Oled o;
	o.display_center("emergency stop!");

	exit(1); // ���� �ڵ� 1: ��ȿ�� ������� �Է� ��
}





#endif