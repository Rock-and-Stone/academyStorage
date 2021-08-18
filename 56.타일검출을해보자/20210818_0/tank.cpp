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
	//탱크의 디폴트는 오른쪽을 보고있게 하자
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
	//여기가 제일 중요한 부분이지 싶슴다
	RECT rcCollision;	//가상의 충돌판정렉트를 하나 생성

	int tileIndex[2];	//타일 검출에 필요한 인덱스
	int tileX, tileY;	//플레이어가 밟고 있는 타일의 인덱스

	//가상의 판정렉트에 현재 렉트를 대입해주자
	rcCollision = _rc;

	//STEP3
	//가상의 판정렉트를 사알짝 깍아주자

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
	//가장 메인이 아닐까 싶으요

	switch (_direction)
	{
		case TANKDIRECTION_LEFT:
			//tileIndex[0] = 내 앞 타일 tileX + 1 * tileY
			//tileIndex[1] = 내 앞 타일의 그 옆에 타일
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
