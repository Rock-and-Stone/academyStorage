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
			/*
			MoveToEx(hdc, 50, 50, NULL);
			LineTo(hdc, 100, 100);
			LineTo(hdc, 300, 300);
			LineTo(hdc, 100, 400);

			MoveToEx(hdc, 400, 100, NULL);
			LineTo(hdc, 400, 400);
			*/

			//�簢�� �׸��� �Լ� == Rectangle()
			Rectangle(hdc, 100, 100, 300, 300);

			//�� �׸��� �Լ� ==  Ellipse()	
			Ellipse(hdc, 100, 100, 300, 300);
			
			//��¥ ���״�� 1�ȼ� ��� �ʹ�
			SetPixel(hdc, 50, 50, RGB(255, 0, 255));

			EndPaint(hWnd, &ps);
		}
		break;

		case WM_DESTROY:
			PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}