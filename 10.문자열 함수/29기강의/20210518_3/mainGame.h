#pragma once //라이브러리 등을 중복으로 걸어도 1번만 메모리에 잡는다
#include <iostream>

using namespace std;

class mainGame
{
public:
	mainGame();	//생성자 : 클래스가 생성될때 자동 실행 됨
	~mainGame();//소멸자 : 클래스가 종료될때 자동 실행 됨
};

