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

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�


};

