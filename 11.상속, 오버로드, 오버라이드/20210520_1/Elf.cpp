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
	cout << "�⺻������ ü�� : " << _hp << endl;
	cout << "�⺻������ ���� : " << _mp << endl;
	cout << "�⺻������ ���� : " << _ad << endl;
	cout << "�⺻������ ���� : " << _ap << endl;
	cout << "�⺻������ ������ : " << _speed << endl;

}
