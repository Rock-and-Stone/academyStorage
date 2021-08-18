#include "pch.h"
#include "soundTest.h"


soundTest::soundTest()
{
}


soundTest::~soundTest()
{
}

HRESULT soundTest::init()
{
	IMAGEMANAGER->addImage("마운틴", "mountain.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	_btnSceneChange = new button;
	_btnSceneChange->init("버튼", WINSIZEX / 2, WINSIZEY / 2,
		PointMake(0, 1), PointMake(0, 0), cbSceneChange);

	return S_OK;
}

void soundTest::release()
{
}

void soundTest::update()
{
	_btnSceneChange->update();
}

void soundTest::render()
{
	IMAGEMANAGER->findImage("마운틴")->render(getMemDC());

	_btnSceneChange->render();
}

void soundTest::cbSceneChange()
{
	SCENEMANAGER->changeScene("사운드씬");
}
