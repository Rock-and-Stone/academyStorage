#include "pch.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ���⿡�� �ض�!!!
HRESULT playGround::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("���", "background.bmp", WINSIZEX, WINSIZEY, true,
		RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bullet", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("enemy", "ufo.bmp", 0, 0, 530, 32, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("��", "��.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "��.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	//�����̽� �� �ν��Ͻ� ���� �� �ʱ�ȭ �Լ� ȣ��
	_ship = new spaceShip;
	_ship->init();

	_em = new enemyManager;
	_em->init();
	_em->setMinion();

	_ship->setEmMemoryAddressLink(_em);
	_em->setSpaceShipMemoryAddressLink(_ship);

	_slt = new saveLoadTest;

	_fadeOut = 255;
	_fadeIn = 0;
	_isFadeInOut = false;

	return S_OK;
}

//�޸� ������ ����� �ض�!!!!
void playGround::release()
{
	gameNode::release();


}

//����ó���� ����ٰ�!
void playGround::update()
{
	gameNode::update();

	_ship->update();
	_em->update();
	_slt->update();
	//collision();

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (!_isFadeInOut) _isFadeInOut = true;
	}

	if (_isFadeInOut)
	{
		_fadeIn++;
		_fadeOut--;

		if (_fadeIn > 254) _isFadeInOut = false;
	}

	TIMEMANAGER->getElapsedTime();


}

//����� �׷����!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	//IMAGEMANAGER->findImage("���")->render(getMemDC());
	IMAGEMANAGER->findImage("��")->alphaRender(getMemDC(), _fadeIn);
	IMAGEMANAGER->findImage("��")->alphaRender(getMemDC(), _fadeOut);



	//_ship->render();
	//_em->render();

	TIMEMANAGER->render(getMemDC());

	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);

}

