#include "pch.h"
#include "pixelCollision.h"


pixelCollision::pixelCollision()
{
}


pixelCollision::~pixelCollision()
{
}

HRESULT pixelCollision::init()
{
	IMAGEMANAGER->addImage("????", "mountain.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	_ball = IMAGEMANAGER->addImage("ball", "ball.bmp", 60, 60, true, RGB(255, 0, 255));

	_x = WINSIZEX / 2 - 100;	//???? x??ǥ
	_y = WINSIZEY / 2 + 100;	//???? y??ǥ

	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());

	_probeY = _y + _ball->getHeight() / 2;


	return S_OK;
}

void pixelCollision::release()
{
}

void pixelCollision::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _x -= 5;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _x += 5;

	_probeY = _y + _ball->getHeight() / 2;

	//
	for (int i = _probeY - 50; i < _probeY + 50; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("????")->getMemDC(), _x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		//????Ÿ ?ȼ??? ?ƴϸ?
		if (!(r == 255 && g == 0 && b == 255))
		{
			_y = i - _ball->getHeight() / 2;
			break;
		}

	}

	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());
}

void pixelCollision::render()
{
	IMAGEMANAGER->findImage("????")->render(getMemDC());

	_ball->render(getMemDC(), _rc.left, _rc.top);
}
