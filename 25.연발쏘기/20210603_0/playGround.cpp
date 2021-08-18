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

	_player1 = RectMakeCenter(WINSIZEX / 2 - 350, WINSIZEY / 2, 100, 50);
	_player2 = RectMakeCenter(WINSIZEX / 2 + 350, WINSIZEY / 2, 100, 50);

	_backGauge =  RectMakeCenter(WINSIZEX / 2 + 250, 100, 400, 50);
	_frontGauge = RectMakeCenter(WINSIZEX / 2 + 250, 100, 400, 50);

	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet[i].isFire = false;
	}

	_r = 0;
	_g = 220;

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

	if (KEYMANAGER->isStayKeyDown('W'))
	{
		_player1.top -= 5;
		_player1.bottom -= 5;
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_player1.top += 5;
		_player1.bottom += 5;
	}

	if (KEYMANAGER->isOnceKeyDown('F')) bulletFire();

	bulletMove();

	collision();

}

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	Rectangle(backDC, _player1);
	Rectangle(backDC, _player2);

	Rectangle(backDC, _backGauge);

	HBRUSH brush = CreateSolidBrush(RGB(_r, _g, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(backDC, brush);
	Rectangle(backDC, _frontGauge);
	SelectObject(backDC, oldBrush);
	DeleteObject(brush);

	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		Ellipse(backDC, _bullet[i].rc);
	}
	

	//=============== �ؿ��� �ǵ������� ================
	this->getBackBuffer()->render(hdc, 0, 0);

}

void playGround::bulletFire()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (_bullet[i].isFire) continue;

		_bullet[i].x = _player1.right + 5;
		_bullet[i].y = (_player1.top + _player1.bottom) / 2;
		_bullet[i].isFire = true;

		break;
	}
}

void playGround::bulletMove()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		if (_bullet[i].x - 10 > WINSIZEX) _bullet[i].isFire = false;

		_bullet[i].x += 5;
		_bullet[i].rc = RectMakeCenter(_bullet[i].x, _bullet[i].y, 20, 20);
	}
}

void playGround::collision()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_player2, &_bullet[i].rc) && _bullet[i].isFire)
		{
			_bullet[i].isFire = false;

			_frontGauge.left += 20;

			if (_frontGauge.right - _frontGauge.left < 250)
			{
				_r = 240;
				_g = 240;
			}
			if (_frontGauge.right - _frontGauge.left < 100)
			{
				_r = 255;
				_g = 0;
			}
			if (_frontGauge.left >= _backGauge.right) _frontGauge.left = _backGauge.right;
			
			break;
		}
	}

}
