#pragma once
#include "gameNode.h"
#include "knight.h"

class playGround : public gameNode
{
private:
	char* _str;
	int _power;
	

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	
};

