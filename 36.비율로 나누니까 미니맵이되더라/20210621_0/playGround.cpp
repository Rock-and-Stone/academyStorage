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

	_player = IMAGEMANAGER->addFrameImage("īŸ����", "image/katana_run.bmp", 940, 148, 10, 2, true, RGB(255, 0, 255));
	_player->setX(WINSIZEX / 2);
	_player->setY(WINSIZEY / 2);

	_count = _index = 0;

	_miniMap = RectMake(0, 0, 200, 200);

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

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	_player->frameRender(backDC, _player->getX(), _player->getY());
	
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(backDC, _miniMap);
		Rectangle(backDC, _miniPl);
	}

	//=============== �ؿ��� �ǵ������� ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
