#pragma once
class gameNode
{
public:
	gameNode();
	virtual ~gameNode();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

};

