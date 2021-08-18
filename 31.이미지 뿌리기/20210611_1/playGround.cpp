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

	_day = new image;
	_day->init("��.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_night = new image;
	_night->init("��.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	_background = _day;

	_isDay = true;
	_count = 0;

	_smile.img = new image;
	_smile.img->init("������.bmp", 50, 45, true, RGB(255, 0, 255));
	_smile.rc = RectMakeCenter(WINSIZEX / 2 - 200, WINSIZEY / 2, 50, 45);
	_smile.gravity = _smile.jumpPower = 0;

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

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	_background->render(backDC, 0, 0);
	_smile.img->render(backDC, _smile.rc.left, _smile.rc.top);

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(backDC, _smile.rc);
	}
	

	//=============== �ؿ��� �ǵ������� ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
