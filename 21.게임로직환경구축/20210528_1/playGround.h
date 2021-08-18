#pragma once
#include "gameNode.h"

#define BALLMAX 15

struct tagBall
{
	RECT rc;
	int speed;
};

class playGround : public gameNode
{
private:
	float _speed;
	tagBall _ball[BALLMAX];
	RECT _player;

	bool _isStart;
	bool _isGameOver;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�
};

