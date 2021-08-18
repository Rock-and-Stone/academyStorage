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

	_enemy.x = WINSIZEX / 2;
	_enemy.y = WINSIZEY / 2;
	_enemy.angle = 0;
	
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
	
	_player.x = _ptMouse.x;
	_player.y = _ptMouse.y;

	_enemy.angle = getAngle(_enemy.x, _enemy.y, _player.x, _player.y);

	_enemy.x += cosf(_enemy.angle) * 2;
	_enemy.y += -sinf(_enemy.angle) * 2;
	
}

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	EllipseMakeCenter(backDC, _enemy.x, _enemy.y, 50, 50);
	EllipseMakeCenter(backDC, _player.x, _player.y, 50, 50);

	//=============== �ؿ��� �ǵ������� ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
