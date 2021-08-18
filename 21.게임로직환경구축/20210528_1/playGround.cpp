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

	_player = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 150, 50, 100);
	
	for (int i = 0; i < BALLMAX; i++)
	{
		_ball[i].rc = RectMakeCenter(50 + i * 75, -30, 25, 25);
		_ball[i].speed = RND->getFromIntTo(7, 15);
	}

	_isStart = false;
	_isGameOver = false;
	

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

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (!_isStart && !_isGameOver)
		{
			_isStart = true;
		}

		if (_isGameOver)
		{
			this->init();
		}
	}

	if (_isStart)
	{
		if (KEYMANAGER->isStayKeyDown('A'))
		{
			_player.left -= 5;
			_player.right -= 5;
		}
		if (KEYMANAGER->isStayKeyDown('D'))
		{
			_player.left += 5;
			_player.right += 5;
		}

		for (int i = 0; i < BALLMAX; i++)
		{
			_ball[i].rc.top += _ball[i].speed;
			_ball[i].rc.bottom += _ball[i].speed;

			RECT temp;
			if (IntersectRect(&temp, &_player, &_ball[i].rc))
			{
				_isStart = false;
				_isGameOver = true;
			}


			if (_ball[i].rc.top > WINSIZEY)
			{
				_ball[i].rc = RectMakeCenter(50 + i * 75, 20, 25, 25);
				_ball[i].speed = RND->getFromIntTo(7, 15);
			}

		}

	}

}

//여기다 그려줘라!!!
void playGround::render(HDC hdc)
{
	Rectangle(hdc, _player);

	for (int i = 0; i < BALLMAX; i++)
	{
		Ellipse(hdc, _ball[i].rc);
	}

	if (_isGameOver)
	{
		TextOut(hdc, WINSIZEX / 2, WINSIZEY / 2, "게임 오바!", strlen("게임 오바!"));
	}
}
