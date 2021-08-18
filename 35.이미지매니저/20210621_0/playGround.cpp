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

	IMAGEMANAGER->addImage("수주", "기유.bmp",  130, 188, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("염주", "형님.bmp", 130, 188, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("풍주", "사네미.bmp", 130, 188, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("음주", "우즈이텐겐.bmp", 130, 188, true, RGB(255, 0, 255));

	_player = IMAGEMANAGER->findImage("염주");

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

	if(KEYMANAGER->isOnceKeyDown(VK_F1)) _player = IMAGEMANAGER->findImage("수주");
	if(KEYMANAGER->isOnceKeyDown(VK_F2)) _player = IMAGEMANAGER->findImage("염주");
	if(KEYMANAGER->isOnceKeyDown(VK_F3)) _player = IMAGEMANAGER->findImage("풍주");
	if (KEYMANAGER->isOnceKeyDown(VK_F4)) _player = IMAGEMANAGER->findImage("음주");
}

//여기다 그려줘라!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	
	_player->render(backDC, 300, 100);

	//=============== 밑에도 건들지마라 ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
