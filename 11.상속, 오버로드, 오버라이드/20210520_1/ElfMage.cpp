#include "ElfMage.h"



ElfMage::ElfMage()
{
	_hp = 75;
	_mp = 180;
	_ad = 5;
	_ap = 30;
	_speed = 2.5f;

	cout << "엘프법사의 체력 : " << _hp << endl;
	cout << "엘프법사의 마력 : " << _mp << endl;
	cout << "엘프법사의 물공 : " << _ad << endl;
	cout << "엘프법사의 마공 : " << _ap << endl;
	cout << "엘프법사의 슷히드 : " << _speed << endl;
}


ElfMage::~ElfMage()
{
}
