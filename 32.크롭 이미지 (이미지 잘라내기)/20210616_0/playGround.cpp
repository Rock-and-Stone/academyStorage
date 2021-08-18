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

	_background = new image;
	_background->init("아무튼비치임.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_cameraX = _cameraY = 0;

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

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _cameraX -= 2;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _cameraX += 2;
	if (KEYMANAGER->isStayKeyDown(VK_UP)) _cameraY -= 2;
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) _cameraY += 2;
	
}

//여기다 그려줘라!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	
	_background->render(backDC);
	//200,200좌표로부터 가로 300, 세로 300 만큼을 오려다
	//0,0 뿌리겠다
	_background->render(backDC, 0, 0, _cameraX, _cameraY, 300, 300);

	//=============== 밑에도 건들지마라 ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
