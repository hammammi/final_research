// Cocktail.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


#include "Material.h"

//method들을 numbering
enum class TechniqueMethod {
    BUILD,
    STIR,
};


class Cocktail
{
private:
    String cocktail_name; // 칵테일 이름
  // {0, 0, 50, 60, 0, 0, 0, ...} 이런 식으로 필요한 재료와 양 정보를 저장함.
    int disp_material_amount[12];
    int pump_material_amount[9];
    TechniqueMethod method; // 기법
    int cocktail_rgb[3]; // 완성됐을 때 Led 색깔 정보
    int glass; // 잔 정보

public:
    // 이름은 "Martini" 이렇게 받고, 배열은 주소로 받음. 기법은 BUILD STIR 이렇게 써주면 됨.
	// glass는 잔 높이가 낮은것부터 1,2,3,4
    Cocktail(String name, int a_disp_mtrl[], int a_pump_mtrl[],
        TechniqueMethod a_method, int glass, int a_r, int a_g, int a_b);
    Cocktail(); // 배열 생성을 위한 기본 생성자 - 아무런 정보도 포함하지 않음

    String get_name() { return cocktail_name; }
    int* get_disp_recipe() { return disp_material_amount; }
    int* get_pump_recipe() { return pump_material_amount; }
    TechniqueMethod get_technique() { return method; }
    int* get_cocktail_color() { return cocktail_rgb; }
    int get_glass_info() { return glass; }


};


inline Cocktail::Cocktail(String name, int a_disp_mtrl[], int a_pump_mtrl[],
    TechniqueMethod a_method, int glass, int a_r, int a_g, int a_b)
{
    cocktail_name = name;

    for (int i = 0; i < 12; i++) { // 디스펜서 재료 종류와 양 정보 깊은복사
        disp_material_amount[i] = a_disp_mtrl[i];
    }

    for (int i = 0; i < 9; i++) { // 펌프 재료 종류와 양 정보 깊은복사
        pump_material_amount[i] = a_pump_mtrl[i];
    }

    this->glass = glass;

    cocktail_rgb[0] = a_r;
    cocktail_rgb[1] = a_g;
    cocktail_rgb[2] = a_b;

    method = a_method;
}


inline Cocktail::Cocktail() : Cocktail("", 0, 0, TechniqueMethod::BUILD, -1, -1, -1, -1) { }


#endif



