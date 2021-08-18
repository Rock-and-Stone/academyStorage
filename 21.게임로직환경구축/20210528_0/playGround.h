#pragma once
#include "gameNode.h"

class playGround : public gameNode
{
private:
	RECT _rc;
	float _speed;
	bool _isCrash;

	int _r, _g, _b;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�
};

