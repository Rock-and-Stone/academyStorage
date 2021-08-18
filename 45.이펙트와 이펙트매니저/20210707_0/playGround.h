#pragma once
#include "gameNode.h"
#include "aniTest.h"
#include "effectTest.h"

class playGround : public gameNode
{
private:
	aniTest* _at;
	effectTest* _et;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	
};

