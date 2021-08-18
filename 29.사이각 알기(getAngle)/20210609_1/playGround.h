#pragma once
#include "gameNode.h"

struct tagObj
{
	float x, y;
	float angle;
};

class playGround : public gameNode
{
private:
	tagObj _enemy;
	tagObj _player;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�

	

};

