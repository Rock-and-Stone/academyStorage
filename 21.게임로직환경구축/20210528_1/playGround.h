#pragma once
#include "gameNode.h"

#define BALLMAX 15

struct tagBall
{
	RECT rc;
	int speed;
};

class playGround : public gameNode
{
private:
	float _speed;
	tagBall _ball[BALLMAX];
	RECT _player;

	bool _isStart;
	bool _isGameOver;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render(HDC hdc);	//그리기 함수
};

