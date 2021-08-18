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

	_obj.x = WINSIZEX / 2;
	_obj.y = WINSIZEY / 2;
	_obj.speed = 3.0f;
	_obj.radius = 50;
	_obj.angle = PI / 4;

	
	
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

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _obj.angle += 0.04f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _obj.angle -= 0.04f;

	_obj.x += cosf(_obj.angle) * 3;
	_obj.y += -sinf(_obj.angle) * 3;
	

}

//여기다 그려줘라!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	EllipseMakeCenter(backDC, _obj.x, _obj.y, _obj.radius * 2, _obj.radius * 2);
	
	

	//=============== 밑에도 건들지마라 ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
