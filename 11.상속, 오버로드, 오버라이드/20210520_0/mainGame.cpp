#include "mainGame.h"



mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}

void mainGame::Attack()
{
	cout << "기본 공격이다" << endl;
}

void mainGame::Attack(int mp)
{
	cout << mp << " 마력을 소모해 공격한다" << endl;
}
