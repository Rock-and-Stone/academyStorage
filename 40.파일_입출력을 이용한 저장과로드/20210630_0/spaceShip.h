#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

//UNSAFE ������ ���������� �����ϴ� ����
#pragma warning(disable:4996)

//��ȣ������ ���� ���漱��
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	hellFire* _hellFire;
	enemyManager* _em;
	progressBar* _hpBar;

	float _currentHP, _maxHP;

public:
	spaceShip();
	~spaceShip();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void collision();

	//�������� �ִ� �Լ�
	void hitDamage(float damage);

	image* getShipImage() { return _ship; }

	hellFire* getHellFire() { return _hellFire; }


	//������
	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }
};

