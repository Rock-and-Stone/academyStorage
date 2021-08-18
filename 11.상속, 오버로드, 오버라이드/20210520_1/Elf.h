#pragma once
#include <iostream>

using namespace std;

//모든 엘프들의 부모클래스
class Elf
{
protected:
	int _hp;
	int _mp;
	int _ad;	//물리데미지 attack Damage 
	int _ap;	//마법데미지 ability Power
	float _speed;

public:
	Elf();
	~Elf();

	void output();
};

