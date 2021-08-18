#include "Elf.h"



Elf::Elf()
{
	_hp = 100;
	_mp = 60;
	_ad = 10;
	_ap = 10;
	_speed = 5.0f;

	output();
}


Elf::~Elf()
{
}

void Elf::output()
{
	cout << "기본엘프의 체력 : " << _hp << endl;
	cout << "기본엘프의 마력 : " << _mp << endl;
	cout << "기본엘프의 물공 : " << _ad << endl;
	cout << "기본엘프의 마공 : " << _ap << endl;
	cout << "기본엘프의 슷히드 : " << _speed << endl;

}
