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

	_background = new image;
	_background->init("�ƹ�ư��ġ��.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_cameraX = _cameraY = 0;

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

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _cameraX -= 2;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _cameraX += 2;
	if (KEYMANAGER->isStayKeyDown(VK_UP)) _cameraY -= 2;
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) _cameraY += 2;
	
}

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	
	_background->render(backDC);
	//200,200��ǥ�κ��� ���� 300, ���� 300 ��ŭ�� ������
	//0,0 �Ѹ��ڴ�
	_background->render(backDC, 0, 0, _cameraX, _cameraY, 300, 300);

	//=============== �ؿ��� �ǵ������� ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
