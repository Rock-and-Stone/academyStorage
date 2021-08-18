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

	_idle = new image;
	_idle->init("image/katana_idle.bmp", 924, 176, 14, 2, true, RGB(255, 0, 255));

	_run = new image;
	_run->init("image/katana_run.bmp", 940, 148, 10, 2, true, RGB(255, 0, 255));
	
	_player.img = _idle;
	_player.x = WINSIZEX / 2;
	_player.y = WINSIZEY / 2;
	_player.rc = RectMakeCenter(_player.x, _player.y, 
		_player.img->getFrameWidth(), _player.img->getFrameHeight());

	_count = _index = 0;

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

	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_player.x += 5;
		_player.direction = RIGHT_RUN;
		_player.img = _run;
		_player.img->setFrameY(0);
	}
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		_player.direction = RIGHT_IDLE;
		_player.img = _idle;
		_player.img->setFrameY(0);
	}

	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_player.x -= 5;
		_player.direction = LEFT_RUN;
		_player.img = _run;
		_player.img->setFrameY(1);
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_player.direction = LEFT_IDLE;
		_player.img = _idle;
		_player.img->setFrameY(1);
	}

	_count++;

	if (_count % 10 == 0)
	{
		switch (_player.direction)
		{
			case RIGHT_IDLE:
				_player.img->setFrameX(_index);
				_index++;

				if (_index >= _player.img->getMaxFrameX()) _index = 0;
			break;
			case LEFT_IDLE:
				_player.img->setFrameX(_index);
				_index--;

				if (_index <= 0) _index = _player.img->getMaxFrameX();
			break;
			case RIGHT_RUN:
				_player.img->setFrameX(_index);
				_index++;

				if (_index >= _player.img->getMaxFrameX()) _index = 0;
			break;
			case LEFT_RUN:
				_player.img->setFrameX(_index);
				_index--;

				if (_index <= 0) _index = _player.img->getMaxFrameX();
			break;
		
		}

		

		_count = 0;
	}



	_player.rc = RectMakeCenter(_player.x, _player.y,
		_player.img->getFrameWidth(), _player.img->getFrameHeight());
}

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	
	_player.img->frameRender(backDC, _player.rc.left, _player.rc.top);


	//=============== �ؿ��� �ǵ������� ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
