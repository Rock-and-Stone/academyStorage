#pragma once
#include "gameNode.h"

#define PI 3.14156f

class playGround : public gameNode
{
private:
	//PI == 3.14 == 180도
	//1라디안 == 호의 길이랑 반지름이 일치하면 1라디안 
	//          57.3도 정도이다

	float _radian;
	float _degree;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render(HDC hdc);	//그리기 함수

	
};

