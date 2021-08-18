#pragma once
#include "gameNode.h"

#define BULLETMAX 20

struct tagBullet
{
	RECT rc;
	int x, y;
	bool isFire;
};


class playGround : public gameNode
{
private:
	RECT _player1;
	RECT _player2;

	tagBullet _bullet[BULLETMAX];

	RECT _backGauge;
	RECT _frontGauge;

	int _r, _g;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render(HDC hdc);	//그리기 함수

	//총알 발사신호
	void bulletFire();

	//총알 움직임
	void bulletMove();

	//충돌 함수
	void collision();
};

