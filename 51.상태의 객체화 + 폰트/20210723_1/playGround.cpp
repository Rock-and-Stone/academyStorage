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
	gameNode::init(true);

	IMAGEMANAGER->addImage("���", "background.bmp", WINSIZEX, WINSIZEY, true,
		RGB(255, 0, 255));
	
	
	

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
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============
	
	char str[256];
	HFONT oldFont, font1;
	/*
	CreateFont(
		40,			//������
		0,			//���� ����
		40,			//���� ����(��¥ ������)
		0,			//���� ����
		600,		//���� ����
		0,			//bool ���� ���� ���Ÿ�ü �������
		0,			//bool ���� ���� 
		0,			//bool ���� ��Ҽ� (������Ű�� ���� �װ�)
		HANGUL_CHARSET,	//���� ����
		0,				//��� ��Ȯ��
		0,				//Ŭ���� ��Ȯ��
		0,				//����� ����Ƽ
		0,				//�ڰ�
		TEXT("�ü�ü"));	//��Ʈ 
	*/
	/*
	

	font1 = CreateFont(50, 0, 0, 0, 100, true, true, true, HANGUL_CHARSET, 0, 0, 0, 50, TEXT("�޸ձ���"));
	oldFont = (HFONT)SelectObject(getMemDC(), font1);
	sprintf_s(str, "��Ʈ�� ĸ�� ���̾�");
	TextOut(getMemDC(), 10, 100, str, strlen(str));
	DeleteObject(font1);
	*/
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	RECT rcText = RectMake(10, 300, 400, 100);

	HFONT font2 = CreateFont(40, 0, 0, 0, 300, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

	HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), font2);

	DrawText(getMemDC(), TEXT("Subway"), 7, &rcText, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	SelectObject(getMemDC(), oldFont2);
	DeleteObject(font2);



	TIMEMANAGER->render(getMemDC());

	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);

}

