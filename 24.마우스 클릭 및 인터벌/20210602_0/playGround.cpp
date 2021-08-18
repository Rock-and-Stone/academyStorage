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

	for (int i = 0; i < 5; i++)
	{
		_box[i].rc = RectMakeCenter(100 + i * 200, WINSIZEY / 2 - 250, 100, 100);
		_box[i].isCheck = false;
		_box[i].isJoker = false;
	}

	_box[RND->getInt(5)].isJoker = true;

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

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < 5; i++)
		{
			if (PtInRect(&_box[i].rc, _ptMouse))
			{
				_box[i].isCheck = true;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (_box[i].isCheck && _box[i].isJoker)
		{
			_box[i].rc.top += 5;
			_box[i].rc.bottom += 5;

			if (_box[i].rc.top > WINSIZEY) this->init();
		}
	}



}

//여기다 그려줘라!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	for (int i = 0; i < 5; i++)
	{
		if (_box[i].isCheck && !_box[i].isJoker)
		{
			HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
			HBRUSH oldBrush = (HBRUSH)SelectObject(backDC, brush);
			Rectangle(backDC, _box[i].rc);
			SelectObject(backDC, oldBrush);
			DeleteObject(brush);
		}
		else if (_box[i].isCheck && _box[i].isJoker)
		{
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
			HBRUSH oldBrush = (HBRUSH)SelectObject(backDC, brush);
			Rectangle(backDC, _box[i].rc);
			SelectObject(backDC, oldBrush);
			DeleteObject(brush);
		}
		else Rectangle(backDC, _box[i].rc);
	}

	//=============== 밑에도 건들지마라 ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
