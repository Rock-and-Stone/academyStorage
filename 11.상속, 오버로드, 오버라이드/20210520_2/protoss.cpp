#include "protoss.h"




protoss::protoss()
{
	_hp = 50;
	_mp = 0;
	_atk = 5;
}


protoss::~protoss()
{
}


void protoss::racePassive()
{
	cout << "차..차오른다 실드!!" << endl;
}

void protoss::Attack()
{
	cout << "프로토스의 기본 공격이다" << endl;
}
