// Material.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


// Note: 하드웨어 관련 코드 없음
class Material {
private:
	String name;
	int pos_x = 0, pos_y = 0;
	int remain;
	int rgb[3];
	void num_to_pos(int a_num);

public:
	Material(String aname, int a_num, int a_remain, int ar, int ag, int ab);

	String get_name() { return name; }
	int get_pos_x() { return pos_x; }
	int get_pos_y() { return pos_y; }
	int get_amount() { return remain; }
	void set_amount(int a_remain) { remain = a_remain; }
	int* get_rgb() { return rgb; }
};


// 생성자 함수
inline Material::Material(String aname, int a_num, int a_remain, int ar, int ag, int ab) {
	name = aname;
	this->num_to_pos(a_num);
	remain = a_remain;
	rgb[0] = ar;  rgb[1] = ag;  rgb[2] = ab;
}


// 생성할 때 번호를 지정해 주면 알아서 위치를 지정해줌.
inline void Material::num_to_pos(int a_num) {
	switch (a_num)
	{
	//**************disp_material**************//
	case 1:
		pos_x = 2170;  pos_y = 20;  break;
	case 2:
		pos_x = 1660;  pos_y = 20;  break;
	case 3:
		pos_x = 1150;  pos_y = 20;  break;
	case 4:
		pos_x = 640;  pos_y = 20;  break;	
	case 5:
		pos_x = 2680;  pos_y = 20;  break;
	case 6:
		pos_x = 3190;  pos_y = 1850;  break;
	case 7:
		pos_x = 3190;  pos_y = 20;  break;
	case 8:
		pos_x = 2654;  pos_y = 1850;  break;
	case 9:
		pos_x = 2148;  pos_y = 1850;  break;
	case 10:
		pos_x = 1642;  pos_y = 1850;  break;
	case 11:
		pos_x = 1136;  pos_y = 1850;  break;
	case 12:
		pos_x = 630;  pos_y = 1850;  break;
	//************pump_material*************//
	case 13:
		pos_x = 790;  pos_y = 1000;  break;
	case 14:
		pos_x = 1050;  pos_y = 1000;  break;
	case 15:
		pos_x = 1310;  pos_y = 1000;  break;
	case 16:
		pos_x = 1570;  pos_y = 1000;  break;
	case 17:
		pos_x = 1800;  pos_y = 1000;  break;
	case 18:
		pos_x = 2060;  pos_y = 1000;  break;
	case 19:
		pos_x = 2320;  pos_y = 1000;  break;
	case 20:
		pos_x = 2580;  pos_y = 1000;  break;
	case 21:
		pos_x = 560;  pos_y = 1000;  break;

	default:
		break;
	}
}



// ******************** 위의 Material을 상속받은 클래스 두 개 *********************
class DispenserMaterial :
	public Material
{
public:
	DispenserMaterial(String aname, int a_num, double a_remain, int ar, int ag, int ab)
		: Material(aname, a_num, a_remain, ar, ag, ab) { }
	DispenserMaterial() : DispenserMaterial("", -1, -1, -1, -1, -1) { } // 마테리얼 배열 생성을 위한 기본 생성자

};

class PumpMaterial :
	public Material
{
public:
	PumpMaterial(String aname, int a_num, double a_remain, int ar, int ag, int ab)
		: Material(aname, a_num, a_remain, ar, ag, ab) { }
	PumpMaterial() : PumpMaterial("", -1, -1, -1, -1, -1) { } // 마테리얼 배열 생성을 위한 기본 생성자

};


#endif
