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

	_rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);
	_jumpPower = _gravity = 0;
	_isJump = false;

	_ground = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, 250, 50);

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

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_rc.left -= 5;
		_rc.right -= 5;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rc.left += 5;
		_rc.right += 5;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (!_isJump)
		{
			_isJump = true;
			_gravity = 0.15f;
			_jumpPower = 5.0f;
		}
	}

	if (_isJump)
	{
		_rc.top -= _jumpPower;
		_rc.bottom -= _jumpPower;

		_jumpPower -= _gravity;

		RECT temp;
		if (IntersectRect(&temp, &_ground, &_rc))
		{
			int height = temp.bottom - temp.top;

			_isJump = false;
			_gravity = _jumpPower = 0;
		}

	}

}

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	Rectangle(backDC, _rc);
	Rectangle(backDC, _ground);


	//=============== �ؿ��� �ǵ������� ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
