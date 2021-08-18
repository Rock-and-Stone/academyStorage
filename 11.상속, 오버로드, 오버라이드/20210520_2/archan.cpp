#include "archan.h"

archan::archan()
{
	cout << "나느 찝정관" << endl;
	_hp = 150;
	_mp = 100;
	_atk = 13;

	cout << "찝정관 체력 : " << _hp << endl;
	cout << "찝정관 마력 : " << _mp << endl;
	cout << "찝정관 공격력 : " << _atk << endl;


}


archan::~archan()
{
}

void archan::Attack()
{
	cout << "에너지 파를 쏜다" << endl;
}
