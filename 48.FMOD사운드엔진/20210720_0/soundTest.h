#pragma once
#include "gameNode.h"

class soundTest : public gameNode
{
public:
	soundTest();
	~soundTest();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�
};

