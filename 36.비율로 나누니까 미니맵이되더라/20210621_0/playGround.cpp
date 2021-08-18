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

	_player = IMAGEMANAGER->addFrameImage("카타나런", "image/katana_run.bmp", 940, 148, 10, 2, true, RGB(255, 0, 255));
	_player->setX(WINSIZEX / 2);
	_player->setY(WINSIZEY / 2);

	_count = _index = 0;

	_miniMap = RectMake(0, 0, 200, 200);

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

	_miniPl = RectMake(_player->getX() / 5, _player->getY() / 4, _player->getFrameWidth() / 5, _player->getFrameHeight() / 4);


	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _player->setX(_player->getX() - 5);
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _player->setX(_player->getX() + 5);
	if (KEYMANAGER->isStayKeyDown(VK_UP)) _player->setY(_player->getY() - 5);
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) _player->setY(_player->getY() + 5);


	_count++;

	if (_count % 10 == 0)
	{
		_player->setFrameX(_index);
		_index++;
		if (_index >= _player->getMaxFrameX()) _index = 0;

		_count = 0;
	}

	
}

//여기다 그려줘라!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	_player->frameRender(backDC, _player->getX(), _player->getY());
	
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(backDC, _miniMap);
		Rectangle(backDC, _miniPl);
	}

	//=============== 밑에도 건들지마라 ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
