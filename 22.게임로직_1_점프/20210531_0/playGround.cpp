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
	gameNode::init();

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	_rc = RectMakeCenter(_x, _y, 100, 100);
	

	_jumpPower = _gravity = 0;

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

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _x -= 5;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _x += 5;

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_jumpPower = 5.0f;
		_gravity = 0.08f;
	}

	
	_y -= _jumpPower;
	_jumpPower -= _gravity;


	_rc = RectMakeCenter(_x, _y, 100, 100);
}

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	Rectangle(hdc, _rc);
}
