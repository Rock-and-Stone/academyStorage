#pragma once
#include <iostream>

using namespace std;

class protoss
{
protected:
	int _hp;	//체력
	int _mp;	//마력
	int _atk;	//공격력

	//종특함수
	void racePassive();

public:
	protoss();
	~protoss();

	virtual void Attack();
};

