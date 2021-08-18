#pragma once
#include "gameNode.h"

struct tagBox
{
	RECT rc;
	bool isJoker;
	bool isCheck;
};

class playGround : public gameNode
{
private:
	tagBox _box[5];
	

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render(HDC hdc);	//그리기 함수
};

