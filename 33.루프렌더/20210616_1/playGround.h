#pragma once
#include "gameNode.h"


class playGround : public gameNode
{
private:
	image* _background;
	int _cameraX, _cameraY;
	int _loopX, _loopY;
	
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render(HDC hdc);	//그리기 함수


};

