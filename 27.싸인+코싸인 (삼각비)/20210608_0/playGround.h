#pragma once
#include "gameNode.h"

#define PI 3.14156f

struct tagObj
{
	float x, y;
	float radius;
	float speed;
	float angle;
};

class playGround : public gameNode
{
private:
	tagObj _obj;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�

	
};

