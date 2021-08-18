#include <Windows.h>

//�ν��Ͻ�(�޸� �� �Ҵ�Ǿ� �������� ���α׷�)
HINSTANCE _hInstance;

//������ �ڵ�
HWND _hWnd;

LPCTSTR _lpszClass = TEXT("29��Ŭ��");

//�Լ��� ������ Ÿ�� ����
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int cmdShow)
{
	_hInstance = hInstance;

	//������ �޼��� ����ü
	MSG message;

	//������ Ŭ���� ����ü
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;		//Ŭ���� ���� �޸�
	wndClass.cbWndExtra = 0;		//������ ���� �޸�
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//������ ������
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//������ Ŀ�����
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//������ ���
	wndClass.hInstance = hInstance;									//�ν��Ͻ� �ο�
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//���ν��� ����
	wndClass.lpszClassName = _lpszClass;		
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//�����츦 ���� ������ ������ ���� ������ش�
	RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		_lpszClass,				//Ŭ���� �̸�
		_lpszClass,				//������ �̸�
		WS_OVERLAPPEDWINDOW,	//������ â ���
		50,						//������ǥ X (left)
		50,						//������ǥ Y (top)
		800,					//������ â ����ũ��
		600,					//������ â ����ũ��
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	//������ ������ â�� �츮 ���� ���̰� ���ִ� �Լ�
	ShowWindow(_hWnd, cmdShow);

	//GetMessage vs PeekMessage
	//�ٸ޼����� �����쿡�� ó���ش޶�� �޼����� �Ѿ�ö� �����ϰ�
	//�ȸ޼����� �޼����� �ֵ� ���� ����ؼ� �����ϰ� �ִ�.

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}