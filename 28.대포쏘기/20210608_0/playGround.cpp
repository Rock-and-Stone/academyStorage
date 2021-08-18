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

	_cannon.angle = PI / 2;
	_cannon.cannon = 100;		//포신 길이
	_cannon.radius = 100;
	_cannon.center.x = WINSIZEX / 2;
	_cannon.center.y = WINSIZEY;
	
	//기왕 하는 김에 총알도 하입시더~
	for (int i = 0; i < BULLETMAX; ++i)
	{
		_bullet[i].speed = 5;
		_bullet[i].radius = 20;
		_bullet[i].isFire = false;
		_bullet[i].gravity = 0;
	}
	
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
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _cannon.angle <= 3.04) _cannon.angle += 0.04f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _cannon.angle >= 0.10) _cannon.angle -= 0.04f;
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) bulletFire();

	_cannon.cannonEnd.x =  cosf(_cannon.angle) * _cannon.cannon + _cannon.center.x;
	_cannon.cannonEnd.y = -sinf(_cannon.angle) * _cannon.cannon + _cannon.center.y;
	
	bulletMove();
}

//여기다 그려줘라!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	EllipseMakeCenter(backDC, _cannon.center.x, _cannon.center.y,
		100, 100);
	LineMake(backDC, _cannon.center.x, _cannon.center.y,
					 _cannon.cannonEnd.x, _cannon.cannonEnd.y);
	
	//기왕지사 이렇게 된거 총알도 그려주자
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		EllipseMakeCenter(backDC, _bullet[i].x, _bullet[i].y, _bullet[i].radius * 2, _bullet[i].radius * 2);
	}

	//=============== 밑에도 건들지마라 ================
	this->getBackBuffer()->render(hdc, 0, 0);

}

void playGround::bulletFire()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (_bullet[i].isFire) continue;
		_bullet[i].isFire = true;
		_bullet[i].x = cosf(_cannon.angle) * (_cannon.cannon + 3) + _cannon.center.x;
		_bullet[i].y = -sinf(_cannon.angle) * (_cannon.cannon + 3) + _cannon.center.y;
		_bullet[i].angle = _cannon.angle;

		break;
	}

}

void playGround::bulletMove()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;

		_bullet[i].gravity += 0.04f;
		_bullet[i].x += cosf(_bullet[i].angle) * _bullet[i].speed;
		_bullet[i].y += -sinf(_bullet[i].angle) * _bullet[i].speed + _bullet[i].gravity;
	
		//화면 왼쪽으로 나감
		if (_bullet[i].x + _bullet[i].radius < 0)
		{
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
		}
		//화면 오른쪽
		if (_bullet[i].x - _bullet[i].radius > WINSIZEX)
		{
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
		}
		
		//화면 위쪽으로 나감
		if (_bullet[i].y + _bullet[i].radius < 0)
		{
			_bullet[i].isFire = false;
		}
		//화면 아래쪽
		if (_bullet[i].y - _bullet[i].radius > WINSIZEY)
		{
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
		}
	}
}
