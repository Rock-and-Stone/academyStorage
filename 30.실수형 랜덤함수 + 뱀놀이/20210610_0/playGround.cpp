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

	for (int i = 0; i < SNAKEBODY; ++i)
	{
		_snake[i].radius = 20;
		_snake[i].speed = 5;

		//대가리니?
		if (i == 0)
		{
			_snake[i].angle = RND->getFloat(PI2);//좋쥬?
			_snake[i].x = RND->getFromFloatTo(100, WINSIZEX - 100);
			_snake[i].y = RND->getFromFloatTo(100, WINSIZEY - 100);
		}
		else //몸통이니?
		{
			_snake[i].angle = _snake[i - 1].angle;
			_snake[i].x = _snake[i - 1].x - cosf(_snake[i].angle) * (_snake[i].radius * 2);
			_snake[i].y = _snake[i - 1].y - (-sinf(_snake[i].angle) * (_snake[i].radius * 2));

		}
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
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _snake[0].angle += 0.04f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _snake[0].angle -= 0.04f;
	
	snakeMove();
}

//여기다 그려줘라!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	for (int i = 0; i < SNAKEBODY; ++i)
	{
		EllipseMakeCenter(backDC, _snake[i].x, _snake[i].y, _snake[i].radius * 2, _snake[i].radius * 2);
	}

	//=============== 밑에도 건들지마라 ================
	this->getBackBuffer()->render(hdc, 0, 0);

}

void playGround::snakeMove()
{
	for (int i = 0; i < SNAKEBODY; ++i)
	{
		//머뤼뉘?
		if (i == 0)
		{
			_snake[i].x += cosf(_snake[i].angle) * _snake[i].speed;
			_snake[i].y += -sinf(_snake[i].angle) * _snake[i].speed;

			if (_snake[i].x - _snake[i].radius < 0)
			{
				_snake[i].angle = PI - _snake[i].angle;
			}
			if (_snake[i].x + _snake[i].radius >= WINSIZEX)
			{
				_snake[i].angle = PI - _snake[i].angle;
			}
			if (_snake[i].y - _snake[i].radius < 0)
			{
				_snake[i].angle = PI2 - _snake[i].angle;
			}
			if (_snake[i].y + _snake[i].radius >= WINSIZEY)
			{
				_snake[i].angle = PI2 - _snake[i].angle;
			}

		}
		else //몸통이뉘?
		{
			//앞에 애가 회전을 시전했으면
			if (_snake[i].radius * 2 <= getDistance(_snake[i].x, _snake[i].y, _snake[i - 1].x, _snake[i - 1].y))
			{
				_snake[i].angle = getAngle(_snake[i].x, _snake[i].y, _snake[i - 1].x, _snake[i - 1].y);

				//보정을 해줍시다
				_snake[i].x = _snake[i - 1].x - (cosf(_snake[i].angle) * _snake[i].radius * 2);
				_snake[i].y = _snake[i - 1].y - (-sinf(_snake[i].angle) * _snake[i].radius * 2);
				
			}


			_snake[i].x += cosf(_snake[i].angle) * _snake[i].speed;
			_snake[i].y += -sinf(_snake[i].angle) * _snake[i].speed;
		}
	}
}
