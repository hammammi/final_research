/*
operation.cpp�� �ۼ��߾��� ���� ������ �Լ� �޸�
*/

/*
vector<Cocktail> Operation::preset_cocktail()
{
	vector<Cocktail> lists;
	map<DispenserMaterial, double> disp_temp;
	map<PumpMaterial, double> pump_temp;


	// ���漭 ��� �Ʒ��� �߰��ϱ�;
	DispenserMaterial vodka("vodka", 30, 30, 750, 50, 50, 200);

	// ���� ��� �Ʒ��� �߰��ϱ�;
	PumpMaterial orange_juice("orange_juice", 500, 30, 450, 230, 120, 0);

	// Ĭ���� �ν��Ͻ� ����� (4�ٴ���); 
	// (�ٵ� �ȿ��ִ� �������� ����ǳ�?) - ???? (�׽�Ʈ �غ��� �ȵǸ� �����ͷ� �ؾߵ� �Ф�)
	// ���� enum���� ��ȣ �����ؼ� �����Ϳ��� ���°� �?
	disp_temp = { {vodka, 70}, };
	pump_temp = { {orange_juice, 50}, };
	Cocktail skrew_driver("skrew_driver", TechniqueMethod::BUILD, disp_temp, pump_temp);
	lists.push_back(skrew_driver);


	return lists;
}



// ���� ������ �Լ�; ok
array<Pump, 5> Operation::preset_pumps()
{
	array<Pump, 5> temp;

	// �� ������ �������� �Է��� �� ��.
	temp[0] = Pump(1, 2);
	temp[1] = Pump(3, 4);
	temp[2] = Pump(5, 6);
	temp[3] = Pump(7, 8);
	temp[4] = Pump(9, 10);

	return temp;
}


// LED STRIP ������ �Լ�;
void Operation::preset_ledstrip()
{

}

// OLED ������ �Լ�
void Operation::preset_oled()
{

}
*/