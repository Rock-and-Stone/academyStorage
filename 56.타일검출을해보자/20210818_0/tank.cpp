#include "pch.h"
#include "tank.h"


tank::tank()
{
}


tank::~tank()
{
}

HRESULT tank::init()
{
	//��ũ�� ����Ʈ�� �������� �����ְ� ����
	_direction = TANKDIRECTION_RIGHT;

	_image = IMAGEMANAGER->addFrameImage("tank", "tank.bmp", 256, 128, 8, 4, true, RGB(255, 0, 255));

	_speed = 100.0f;

	return S_OK;
}

void tank::release()
{
}

void tank::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_direction = TANKDIRECTION_LEFT;
		tankMove();
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_direction = TANKDIRECTION_RIGHT;
		tankMove();
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_direction = TANKDIRECTION_UP;
		tankMove();
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_direction = TANKDIRECTION_DOWN;
		tankMove();
	}
	
}

void tank::render()
{
	_image->frameRender(getMemDC(), _rc.left, _rc.top);
}

void tank::tankMove()
{
	//���Ⱑ ���� �߿��� �κ����� �ͽ���
	RECT rcCollision;	//������ �浹������Ʈ�� �ϳ� ����

	int tileIndex[2];	//Ÿ�� ���⿡ �ʿ��� �ε���
	int tileX, tileY;	//�÷��̾ ��� �ִ� Ÿ���� �ε���

	//������ ������Ʈ�� ���� ��Ʈ�� ����������
	rcCollision = _rc;

	//STEP3
	//������ ������Ʈ�� ���¦ �������

	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elapsedTime * _speed;

	switch (_direction)
	{
		case TANKDIRECTION_LEFT:
			_image->setFrameX(0);
			_image->setFrameY(3);

			_x -= moveSpeed;

			rcCollision = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
		break;
		case TANKDIRECTION_UP:
			_image->setFrameX(0);
			_image->setFrameY(0);

			_y -= moveSpeed;

			rcCollision = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
		break;
		case TANKDIRECTION_RIGHT:
			_image->setFrameX(0);
			_image->setFrameY(2);

			_x += moveSpeed;

			rcCollision = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
		break;
		case TANKDIRECTION_DOWN:
			_image->setFrameX(0);
			_image->setFrameY(1);

			_y += moveSpeed;

			rcCollision = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
		break;
	
	}


	//tileX = rcCollision.left / TILESIZE;
	//tileY = 
	//STEP4
	//���� ������ �ƴұ� ������

	switch (_direction)
	{
		case TANKDIRECTION_LEFT:
			//tileIndex[0] = �� �� Ÿ�� tileX + 1 * tileY
			//tileIndex[1] = �� �� Ÿ���� �� ���� Ÿ��
		break;
		case TANKDIRECTION_UP:

		break;
		case TANKDIRECTION_RIGHT:

		break;
		case TANKDIRECTION_DOWN:

		break;
	
	}

	_rc = rcCollision;

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
}

void tank::setTankPostion()
{
	_rc = _tankMap->getTile()[_tankMap->getPosFirst()].rc;

	_x = (_rc.left + _rc.right) / 2;
	_y = (_rc.top + _rc.bottom) / 2;
}
