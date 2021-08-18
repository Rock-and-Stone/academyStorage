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

	for (int i = 0; i < 5; i++)
	{
		_box[i].rc = RectMakeCenter(100 + i * 200, WINSIZEY / 2 - 250, 100, 100);
		_box[i].isCheck = false;
		_box[i].isJoker = false;
	}

	_box[RND->getInt(5)].isJoker = true;

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

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

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

	//=============== �ؿ��� �ǵ������� ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
