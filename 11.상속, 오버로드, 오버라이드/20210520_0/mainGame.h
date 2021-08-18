#pragma once
#include <iostream>

using namespace std;

class mainGame
{
public:
	mainGame();
	~mainGame();

	//기본공격용 함수
	void Attack();

	//마력 공격용 함수 (소모될 마나)
	void Attack(int mp);
	

};

