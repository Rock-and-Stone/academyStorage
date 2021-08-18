#pragma once
#include "gameNode.h"

#define SNAKEBODY 100

struct tagSnake
{
	float x, y;
	float angle;
	float radius;
	float speed;
};


class playGround : public gameNode
{
private:
	tagSnake _snake[SNAKEBODY];
	
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render(HDC hdc);	//그리기 함수

	void snakeMove();
	

};

