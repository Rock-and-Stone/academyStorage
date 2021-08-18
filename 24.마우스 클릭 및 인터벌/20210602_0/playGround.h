#pragma once
#include "gameNode.h"

struct tagBox
{
	RECT rc;
	bool isJoker;
	bool isCheck;
};

class playGround : public gameNode
{
private:
	tagBox _box[5];
	

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�
};

