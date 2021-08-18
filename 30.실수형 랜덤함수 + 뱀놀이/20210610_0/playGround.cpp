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

	for (int i = 0; i < SNAKEBODY; ++i)
	{
		_snake[i].radius = 20;
		_snake[i].speed = 5;

		//�밡����?
		if (i == 0)
		{
			_snake[i].angle = RND->getFloat(PI2);//����?
			_snake[i].x = RND->getFromFloatTo(100, WINSIZEX - 100);
			_snake[i].y = RND->getFromFloatTo(100, WINSIZEY - 100);
		}
		else //�����̴�?
		{
			_snake[i].angle = _snake[i - 1].angle;
			_snake[i].x = _snake[i - 1].x - cosf(_snake[i].angle) * (_snake[i].radius * 2);
			_snake[i].y = _snake[i - 1].y - (-sinf(_snake[i].angle) * (_snake[i].radius * 2));

		}
	}
	
	
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
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _snake[0].angle += 0.04f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _snake[0].angle -= 0.04f;
	
	snakeMove();
}

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	for (int i = 0; i < SNAKEBODY; ++i)
	{
		EllipseMakeCenter(backDC, _snake[i].x, _snake[i].y, _snake[i].radius * 2, _snake[i].radius * 2);
	}

	//=============== �ؿ��� �ǵ������� ================
	this->getBackBuffer()->render(hdc, 0, 0);

}

void playGround::snakeMove()
{
	for (int i = 0; i < SNAKEBODY; ++i)
	{
		//�ӷ�?
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
		else //�����̴�?
		{
			//�տ� �ְ� ȸ���� ����������
			if (_snake[i].radius * 2 <= getDistance(_snake[i].x, _snake[i].y, _snake[i - 1].x, _snake[i - 1].y))
			{
				_snake[i].angle = getAngle(_snake[i].x, _snake[i].y, _snake[i - 1].x, _snake[i - 1].y);

				//������ ���ݽô�
				_snake[i].x = _snake[i - 1].x - (cosf(_snake[i].angle) * _snake[i].radius * 2);
				_snake[i].y = _snake[i - 1].y - (-sinf(_snake[i].angle) * _snake[i].radius * 2);
				
			}


			_snake[i].x += cosf(_snake[i].angle) * _snake[i].speed;
			_snake[i].y += -sinf(_snake[i].angle) * _snake[i].speed;
		}
	}
}
