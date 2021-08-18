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
	Skeleton(int hp, int atk); //생성자 오버로드
	~Skeleton();

	//접근자
	int getSkeletonHP() { return _hp; }
	int getSkeletonAtk() { return _atk; }

	//설정자
	void setSkeletonHP(int hp) { _hp = hp; }


};

