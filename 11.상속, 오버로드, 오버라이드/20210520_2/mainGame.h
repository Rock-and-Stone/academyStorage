#pragma once
#include <iostream>

using namespace std;

class mainGame
{
public:
	mainGame();
	~mainGame();

	//Ŭ���� �ڱ��ڽſ��� ���� �Լ��� ���Ǹ� �ߴµ�
	void Attack();

	//�Լ����� ���� Attack()������ �Լ� ���°� �ٸ�����
	//�����ε� (�Լ� ������) ��� �Ѵ�.
	void Attack(int mp);
};

