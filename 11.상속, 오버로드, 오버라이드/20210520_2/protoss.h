#pragma once
#include <iostream>

using namespace std;

class protoss
{
protected:
	int _hp;	//ü��
	int _mp;	//����
	int _atk;	//���ݷ�

	//��Ư�Լ�
	void racePassive();

public:
	protoss();
	~protoss();

	virtual void Attack();
};

