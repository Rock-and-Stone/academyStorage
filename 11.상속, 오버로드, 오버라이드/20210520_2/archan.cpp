#include "archan.h"

archan::archan()
{
	cout << "���� ������" << endl;
	_hp = 150;
	_mp = 100;
	_atk = 13;

	cout << "������ ü�� : " << _hp << endl;
	cout << "������ ���� : " << _mp << endl;
	cout << "������ ���ݷ� : " << _atk << endl;


}


archan::~archan()
{
}

void archan::Attack()
{
	cout << "������ �ĸ� ���" << endl;
}
