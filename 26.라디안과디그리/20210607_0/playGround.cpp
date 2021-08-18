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

	_radian = PI;
	_degree = 180.0f;
	
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

	

}

//여기다 그려줘라!!!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	char strRadian[128];
	char strDegree[128];

	sprintf_s(strRadian, "%.2f 라디안 값은 %.2f 디그리와 같다",
		_radian, _radian * (180.0f / PI));
	TextOut(backDC, 100, 100, strRadian, strlen(strRadian));

	sprintf_s(strDegree, "%.2f 디그리 값은 %.2f 라디안과 같다",
		_degree, _degree * (PI / 180.0f));
	TextOut(backDC, 100, 200, strDegree, strlen(strDegree));
	
	

	//=============== 밑에도 건들지마라 ================
	this->getBackBuffer()->render(hdc, 0, 0);

}
