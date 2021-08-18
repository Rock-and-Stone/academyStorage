#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

//상호참조를 위한 전방선언
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

	//데미지를 주는 함수
	void hitDamage(float damage);

	image* getShipImage() { return _ship; }

	hellFire* getHellFire() { return _hellFire; }


	//설정자
	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }
};

