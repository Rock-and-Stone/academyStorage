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

	IMAGEMANAGER->addImage("����", "����.bmp",  130, 188, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "����.bmp", 130, 188, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ǳ��", "��׹�.bmp", 130, 188, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "�������ٰ�.bmp", 130, 188, true, RGB(255, 0, 255));

	_player = IMAGEMANAGER->findImage("����");

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

	if(KEYMANAGER->isOnceKeyDown(VK_F1)) _player = IMAGEMANAGER->findImage("����");
	if(KEYMANAGER->isOnceKeyDown(VK_F2)) _player = IMAGEMANAGER->findImage("����");
	if(KEYMANAGER->isOnceKeyDown(VK_F3)) _player = IMAGEMANAGER->findImage("ǳ��");
	if (KEYMANAGER->isOnceKeyDown(VK_F4)) _player = IMAGEMANAGER->findImage("����");
}

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	
	_player->render(backDC, 300, 100);

	//=============== �ؿ��� �ǵ������� ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
