#pragma once
#include "image.h"

class gameNode
{
private:
	image* _backBuffer;
	void setBackBuffer();

public:
	gameNode();
	virtual ~gameNode();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render(HDC hdc);	//그리기 함수

	//백버퍼 접근자
	image* getBackBuffer() { return _backBuffer; }


	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

};

