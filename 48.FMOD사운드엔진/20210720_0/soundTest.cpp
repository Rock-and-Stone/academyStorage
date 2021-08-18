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
	SOUNDMANAGER->addSound("���̺���", "A Fine Frenzy  Almost Lover.mp3", true, true);
	SOUNDMANAGER->addSound("ũ�ҽ�", "Disclosure  Willing  Able ft Kwabs.mp3", true, true);


	return S_OK;
}

void soundTest::release()
{
}

void soundTest::update()
{
	if (KEYMANAGER->isOnceKeyDown('Q')) SOUNDMANAGER->play("���̺���", 1.0f);
	if (KEYMANAGER->isOnceKeyDown('W'))SOUNDMANAGER->stop("���̺���");
	if (KEYMANAGER->isOnceKeyDown('E'))SOUNDMANAGER->pause("���̺���");
	if (KEYMANAGER->isOnceKeyDown('R'))SOUNDMANAGER->resume("���̺���");

	if (KEYMANAGER->isOnceKeyDown('A')) SOUNDMANAGER->play("ũ�ҽ�", 1.0f);
	if (KEYMANAGER->isOnceKeyDown('S'))SOUNDMANAGER->stop("ũ�ҽ�");
	if (KEYMANAGER->isOnceKeyDown('D'))SOUNDMANAGER->pause("ũ�ҽ�");
	if (KEYMANAGER->isOnceKeyDown('F'))SOUNDMANAGER->resume("ũ�ҽ�");

}

void soundTest::render()
{
}
