#include "ElfWorrior.h"



ElfWorrior::ElfWorrior()
{
	
	_hp = 150;
	_mp = 80;
	_ad = 23;
	_ap = 8;
	_speed = 6.0f;

	cout << "엘프전사의 체력 : " << _hp << endl;
	cout << "엘프전사의 마력 : " << _mp << endl;
	cout << "엘프전사의 물공 : " << _ad << endl;
	cout << "엘프전사의 마공 : " << _ap << endl;
	cout << "엘프전사의 슷히드 : " << _speed << endl;
	
}


ElfWorrior::~ElfWorrior()
{
}
