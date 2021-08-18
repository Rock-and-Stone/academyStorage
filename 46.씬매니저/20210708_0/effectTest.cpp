#include "pch.h"
#include "effectTest.h"


effectTest::effectTest()
{
}


effectTest::~effectTest()
{
}

HRESULT effectTest::init()
{
	IMAGEMANAGER->addImage("explosion", "explosion.bmp", 832, 62, true, RGB(255, 0, 255));

	_effectSample = new effect;
	_effectSample->init(IMAGEMANAGER->findImage("explosion"), 32, 62, 1, 1.0f);

	EFFECTMANAGER->addEffect("explosion1", "explosion.bmp", 832, 62, 32, 62, 1, 0.1f, 1000);

	return S_OK;
}

void effectTest::release()
{
}

void effectTest::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_effectSample->startEffect(_ptMouse.x, _ptMouse.y);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	{
		EFFECTMANAGER->play("explosion1", _ptMouse.x, _ptMouse.y);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F2)) SCENEMANAGER->changeScene("¾Ö´Ï¸ŞÀÌ¼Ç¾À");

	_effectSample->update();
	EFFECTMANAGER->update();

}

void effectTest::render()
{
	_effectSample->render();
	EFFECTMANAGER->render();
}
