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

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	
};

