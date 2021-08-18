#pragma once
#include <iostream>

using namespace std;

class mainGame
{
public:
	mainGame();
	~mainGame();

	//클래스 자기자신에서 공격 함수를 정의를 했는데
	void Attack();

	//함수명이 같은 Attack()이지만 함수 형태가 다른것을
	//오버로드 (함수 재정의) 라고 한다.
	void Attack(int mp);
};

