#include "pch.h"
#include "spaceShip.h"
#include "enemyManager.h"

spaceShip::spaceShip()
{
}


spaceShip::~spaceShip()
{
}

HRESULT spaceShip::init()
{
	_ship = IMAGEMANAGER->addImage("플레이어", "rocket.bmp", 52, 64, true, RGB(255, 0, 255));
	_ship->setX(WINSIZEX / 2);
	_ship->setY(WINSIZEY / 2 + 200);

	_missile = new missile;
	_missile->init(30, 400);

	_hellFire = new hellFire;
	_hellFire->init(30, WINSIZEY);

	_currentHP = _maxHP = 100;

	_hpBar = new progressBar;
	_hpBar->init(_ship->getX(), _ship->getY() - 20, 52, 10);
	_hpBar->setGauge(_currentHP, _maxHP);

	return S_OK;
}

void spaceShip::release()
{
}

void spaceShip::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _ship->getX() > 0)
	{
		_ship->setX(_ship->getX() - 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _ship->getX() + _ship->getWidth()< WINSIZEX)
	{
		_ship->setX(_ship->getX() + 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP) && _ship->getY() > 0)
	{
		_ship->setY(_ship->getY() - 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _ship->getY() + _ship->getHeight() < WINSIZEY)
	{
		_ship->setY(_ship->getY() + 5);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_missile->fire(_ship->getCenterX(), _ship->getY() - 15);
	}

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		_hellFire->fire(_ship->getCenterX(), _ship->getY() - 15);
	}

	_hpBar->setX(_ship->getX());
	_hpBar->setY(_ship->getY() - 20);
	_hpBar->setGauge(_currentHP, _maxHP);
	_hpBar->update();


	collision();

	_missile->update();
	_hellFire->update();
}

void spaceShip::render()
{
	_ship->render(getMemDC(), _ship->getX(), _ship->getY());

	_missile->render();
	_hellFire->render();
	_hpBar->render();
}

void spaceShip::collision()
{
	for (int i = 0; i < _em->getVMinion().size(); i++)
	{
		for (int j = 0; j < _hellFire->getVBullet().size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_hellFire->getVBullet()[j].rc, &
				_em->getVMinion()[i]->getRect()))
			{
				_em->removeMinion(i);
				_hellFire->removeMissile(j);
				break;
			}
		}
	}

}

void spaceShip::hitDamage(float damage)
{
	_currentHP -= damage;
}
