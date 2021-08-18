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

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�

	//����� ������
	image* getBackBuffer() { return _backBuffer; }


	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

};

