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

	_rc = RectMakeCenter(WINSIZEX / 2 - 200, WINSIZEY / 2, 100, 100);
	_isCrash = false;
	_speed = 0;

	_r = RND->getInt(255);
	_g = RND->getInt(255);
	_b = RND->getInt(255);

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

	_speed = 5.0f;

	if (_rc.right > WINSIZEX - 50)
	{
		_isCrash = true;
		_r = RND->getInt(255);
		_g = RND->getInt(255);
		_b = RND->getInt(255);
	}
	if (_rc.left < 50)
	{
		_isCrash = false;
		_r = RND->getInt(255);
		_g = RND->getInt(255);
		_b = RND->getInt(255);
	}


	if (_isCrash == false)
	{
		_rc.left += _speed;
		_rc.right += _speed;
	}
	else
	{
		_rc.left -= _speed;
		_rc.right -= _speed;
	}
	


}

//여기다 그려줘라!!!
void playGround::render(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(_r, _g, _b));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
	Rectangle(hdc, _rc);
	SelectObject(hdc, oldBrush);
	DeleteObject(brush);
}
