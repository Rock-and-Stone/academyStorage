#pragma once
#include <iostream>

using namespace std;

class Skeleton
{
private:
	int _hp;
	int _atk;

public:
	Skeleton();
	Skeleton(int hp, int atk); //������ �����ε�
	~Skeleton();

	//������
	int getSkeletonHP() { return _hp; }
	int getSkeletonAtk() { return _atk; }

	//������
	void setSkeletonHP(int hp) { _hp = hp; }


};

