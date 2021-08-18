#pragma once
#include "gameNode.h"

#define BULLETMAX 20

struct tagBullet
{
	RECT rc;
	int x, y;
	bool isFire;
};


class playGround : public gameNode
{
private:
	RECT _player1;
	RECT _player2;

	tagBullet _bullet[BULLETMAX];

	RECT _backGauge;
	RECT _frontGauge;

	int _r, _g;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�

	//�Ѿ� �߻��ȣ
	void bulletFire();

	//�Ѿ� ������
	void bulletMove();

	//�浹 �Լ�
	void collision();
};

