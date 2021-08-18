#include <Windows.h>

//�ν��Ͻ�(�޸� �� �Ҵ�Ǿ� �������� ���α׷�)
HINSTANCE _hInstance;

//������ �ڵ�
HWND _hWnd;

LPCTSTR _lpszClass = TEXT("����ȣ");

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
		2000,					//������ǥ X (left)
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
	PAINTSTRUCT ps;		
	HDC			hdc;	//<-- �� �� HDC�� ���� �˾Ƶθ� �����ϴ�

	switch (iMessage)
	{
		case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);

			//���� �׾�ô�
			//���� �������� �������຾�ô�
			//�� ��ĥ�Ҷ��� HPEN
			/*
			HPEN pen = CreatePen(PS_DASHDOTDOT, 1, RGB(10, 200, 0));
			HPEN oldPen = (HPEN)SelectObject(hdc, pen);

			MoveToEx(hdc, 50, 50, NULL);
			LineTo(hdc, 150, 150);

			SelectObject(hdc, oldPen);
			DeleteObject(pen);

			HPEN pen1 = CreatePen(PS_DOT, 1, RGB(0, 0, 255));
			HPEN oldPen1 = (HPEN)SelectObject(hdc, pen1);

			MoveToEx(hdc, 300, 50, NULL);
			LineTo(hdc, 50, 450);

			SelectObject(hdc, oldPen1);
			DeleteObject(pen1);
			*/

			//���� ��ĥ�Ҷ� HBRUSH
			HBRUSH brush = CreateSolidBrush(RGB(150, 100, 100));
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
			Ellipse(hdc, 100, 100, 300, 300);
			SelectObject(hdc, oldBrush);
			DeleteObject(brush);

			EndPaint(hWnd, &ps);
		}
		break;

		case WM_DESTROY:
			PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}