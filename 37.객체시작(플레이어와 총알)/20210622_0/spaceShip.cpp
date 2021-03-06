#include "pch.h"
#include "spaceShip.h"


spaceShip::spaceShip()
{
}


spaceShip::~spaceShip()
{
}

HRESULT spaceShip::init()
{
	_ship = IMAGEMANAGER->addImage("?÷??̾?", "rocket.bmp", 52, 64, true, RGB(255, 0, 255));
	_ship->setX(WINSIZEX / 2);
	_ship->setY(WINSIZEY / 2 + 200);

	_missile = new missile;
	_missile->init(30, 400);

	_hellFire = new hellFire;
	_hellFire->init(3000, WINSIZEY);


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

	if (KEYMANAGER->isStayKeyDown('C'))
	{
		_hellFire->fire(_ship->getCenterX(), _ship->getY() - 15);
	}



	_missile->update();
	_hellFire->update();
}

void spaceShip::render()
{
	_ship->render(getMemDC(), _ship->getX(), _ship->getY());

	_missile->render();
	_hellFire->render();
}
