#pragma once
#include <iostream>

using namespace std;

//��� �������� �θ�Ŭ����
class Elf
{
protected:
	int _hp;
	int _mp;
	int _ad;	//���������� attack Damage 
	int _ap;	//���������� ability Power
	float _speed;

public:
	Elf();
	~Elf();

	void output();
};

