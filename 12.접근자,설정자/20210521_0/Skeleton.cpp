#include "Skeleton.h"

Skeleton::Skeleton()
{
	_hp = 100;
	_atk = 5;
}

Skeleton::Skeleton(int hp, int atk)
	: _hp(hp), _atk(atk) //��� �̴ϼȶ�����
{
	
}


Skeleton::~Skeleton()
{
}
