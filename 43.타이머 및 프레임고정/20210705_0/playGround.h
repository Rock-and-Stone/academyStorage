#pragma once
#include "gameNode.h"
#include "spaceShip.h"
#include "enemyManager.h"
#include "saveLoadTest.h"

class playGround : public gameNode
{
private:
	spaceShip* _ship;
	enemyManager* _em;
	saveLoadTest* _slt;

	int _fadeIn;
	int _fadeOut;
	bool _isFadeInOut;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();	//�׸��� �Լ�

	void collision();
};

