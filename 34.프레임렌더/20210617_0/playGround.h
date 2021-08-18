#pragma once
#include "gameNode.h"

enum PLAYERDIRECTION
{
	RIGHT_IDLE,
	LEFT_IDLE,
	RIGHT_RUN,
	LEFT_RUN
};

struct tagPlayer
{
	image* img;
	RECT rc;
	PLAYERDIRECTION direction;
	float x, y;
};


class playGround : public gameNode
{
private:
	image* _idle;
	image* _run;

	tagPlayer _player;

	int _count, _index;
	
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render(HDC hdc);	//그리기 함수


};

