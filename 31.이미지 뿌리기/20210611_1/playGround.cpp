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

	_day = new image;
	_day->init("낮.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_night = new image;
	_night->init("밤.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	_background = _day;

	_isDay = true;
	_count = 0;

	_smile.img = new image;
	_smile.img->init("스마일.bmp", 50, 45, true, RGB(255, 0, 255));
	_smile.rc = RectMakeCenter(WINSIZEX / 2 - 200, WINSIZEY / 2, 50, 45);
	_smile.gravity = _smile.jumpPower = 0;

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

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_smile.jumpPower = 3.0f;
		_smile.gravity = 0.1f;
	}

	_smile.rc.top -= _smile.jumpPower;
	_smile.rc.bottom -= _smile.jumpPower;

	_smile.jumpPower -= _smile.gravity;


	
	_count++;

	if (_count >= 200)
	{
		if (_isDay == true)
		{
			_isDay = false;
			_background = _night;
		}
		else
		{
			_isDay = true;
			_background = _day;
		}

		_count = 0;
	}
	
}

//여기다 그려줘라!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	_background->render(backDC, 0, 0);
	_smile.img->render(backDC, _smile.rc.left, _smile.rc.top);

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(backDC, _smile.rc);
	}
	

	//=============== 밑에도 건들지마라 ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
