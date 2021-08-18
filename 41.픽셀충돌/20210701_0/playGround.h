#pragma once
#include "gameNode.h"
#include "pixelCollision.h"

class playGround : public gameNode
{
private:
	pixelCollision* _pc;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();	//�׸��� �Լ�

	void collision();
};

