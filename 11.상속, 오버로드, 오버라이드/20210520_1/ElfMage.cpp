#include "ElfMage.h"



ElfMage::ElfMage()
{
	_hp = 75;
	_mp = 180;
	_ad = 5;
	_ap = 30;
	_speed = 2.5f;

	cout << "���������� ü�� : " << _hp << endl;
	cout << "���������� ���� : " << _mp << endl;
	cout << "���������� ���� : " << _ad << endl;
	cout << "���������� ���� : " << _ap << endl;
	cout << "���������� ������ : " << _speed << endl;
}


ElfMage::~ElfMage()
{
}
