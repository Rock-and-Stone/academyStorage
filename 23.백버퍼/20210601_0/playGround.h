#pragma once
#include "gameNode.h"

class playGround : public gameNode
{
private:
	RECT _rc;
	float _jumpPower, _gravity;
	bool _isJump;

	RECT _ground;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�
};

