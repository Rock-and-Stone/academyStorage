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

	_radian = PI;
	_degree = 180.0f;
	
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

	

}

//����� �׷����!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	char strRadian[128];
	char strDegree[128];

	sprintf_s(strRadian, "%.2f ���� ���� %.2f ��׸��� ����",
		_radian, _radian * (180.0f / PI));
	TextOut(backDC, 100, 100, strRadian, strlen(strRadian));

	sprintf_s(strDegree, "%.2f ��׸� ���� %.2f ���Ȱ� ����",
		_degree, _degree * (PI / 180.0f));
	TextOut(backDC, 100, 200, strDegree, strlen(strDegree));
	
	

	//=============== �ؿ��� �ǵ������� ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
