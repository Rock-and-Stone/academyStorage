#include "pch.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기에다 해라!!!
HRESULT playGround::init()
{
	gameNode::init();

	_rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);
	_jumpPower = _gravity = 0;
	_isJump = false;

	_ground = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, 250, 50);

	return S_OK;
}

//메모리 해제는 여기다 해라!!!!
void playGround::release()
{
	gameNode::release();


}

//연산처리는 여기다가!
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

//여기다 그려줘라!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	Rectangle(backDC, _rc);
	Rectangle(backDC, _ground);


	//=============== 밑에도 건들지마라 ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
