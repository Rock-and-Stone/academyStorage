#pragma once
#include <iostream>

using namespace std;

class player
{
private:
	int _hp;
	int _atk;

public:
	player();
	~player();

	//private 영역에 접근을 가능하게 해주는게 접근자
	int getPlayerHP() { return _hp; }
	int getPlayerAtk() { return _atk; }
	
	//private 영역의 변수 또는 자료에 값을 넣어주는게 설정자
	void setPlayerHP(int hp) { _hp = hp; }


};

