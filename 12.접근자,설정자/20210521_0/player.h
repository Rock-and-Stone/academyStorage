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

	//private ������ ������ �����ϰ� ���ִ°� ������
	int getPlayerHP() { return _hp; }
	int getPlayerAtk() { return _atk; }
	
	//private ������ ���� �Ǵ� �ڷῡ ���� �־��ִ°� ������
	void setPlayerHP(int hp) { _hp = hp; }


};

