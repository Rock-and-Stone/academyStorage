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
	SOUNDMANAGER->addSound("에이빠인", "A Fine Frenzy  Almost Lover.mp3", true, true);
	SOUNDMANAGER->addSound("크왑스", "Disclosure  Willing  Able ft Kwabs.mp3", true, true);


	return S_OK;
}

void soundTest::release()
{
}

void soundTest::update()
{
	if (KEYMANAGER->isOnceKeyDown('Q')) SOUNDMANAGER->play("에이빠인", 1.0f);
	if (KEYMANAGER->isOnceKeyDown('W'))SOUNDMANAGER->stop("에이빠인");
	if (KEYMANAGER->isOnceKeyDown('E'))SOUNDMANAGER->pause("에이빠인");
	if (KEYMANAGER->isOnceKeyDown('R'))SOUNDMANAGER->resume("에이빠인");

	if (KEYMANAGER->isOnceKeyDown('A')) SOUNDMANAGER->play("크왑스", 1.0f);
	if (KEYMANAGER->isOnceKeyDown('S'))SOUNDMANAGER->stop("크왑스");
	if (KEYMANAGER->isOnceKeyDown('D'))SOUNDMANAGER->pause("크왑스");
	if (KEYMANAGER->isOnceKeyDown('F'))SOUNDMANAGER->resume("크왑스");

}

void soundTest::render()
{
}
