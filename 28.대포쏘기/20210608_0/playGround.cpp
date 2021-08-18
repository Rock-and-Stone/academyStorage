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

	_cannon.angle = PI / 2;
	_cannon.cannon = 100;		//���� ����
	_cannon.radius = 100;
	_cannon.center.x = WINSIZEX / 2;
	_cannon.center.y = WINSIZEY;
	
	//��� �ϴ� �迡 �Ѿ˵� ���Խô�~
	for (int i = 0; i < BULLETMAX; ++i)
	{
		_bullet[i].speed = 5;
		_bullet[i].radius = 20;
		_bullet[i].isFire = false;
		_bullet[i].gravity = 0;
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
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _cannon.angle <= 3.04) _cannon.angle += 0.04f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _cannon.angle >= 0.10) _cannon.angle -= 0.04f;
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) bulletFire();

	_cannon.cannonEnd.x =  cosf(_cannon.angle) * _cannon.cannon + _cannon.center.x;
	_cannon.cannonEnd.y = -sinf(_cannon.angle) * _cannon.cannon + _cannon.center.y;
	
	bulletMove();
}

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	EllipseMakeCenter(backDC, _cannon.center.x, _cannon.center.y,
		100, 100);
	LineMake(backDC, _cannon.center.x, _cannon.center.y,
					 _cannon.cannonEnd.x, _cannon.cannonEnd.y);
	
	//������� �̷��� �Ȱ� �Ѿ˵� �׷�����
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		EllipseMakeCenter(backDC, _bullet[i].x, _bullet[i].y, _bullet[i].radius * 2, _bullet[i].radius * 2);
	}

	//=============== �ؿ��� �ǵ������� ================
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
	
		//ȭ�� �������� ����
		if (_bullet[i].x + _bullet[i].radius < 0)
		{
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
		}
		//ȭ�� ������
		if (_bullet[i].x - _bullet[i].radius > WINSIZEX)
		{
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
		}
		
		//ȭ�� �������� ����
		if (_bullet[i].y + _bullet[i].radius < 0)
		{
			_bullet[i].isFire = false;
		}
		//ȭ�� �Ʒ���
		if (_bullet[i].y - _bullet[i].radius > WINSIZEY)
		{
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
		}
	}
}
