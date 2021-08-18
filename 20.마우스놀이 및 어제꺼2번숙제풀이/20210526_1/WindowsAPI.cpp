#include "pch.h"

//인스턴스(메모리 상에 할당되어 실행중인 프로그램)
HINSTANCE _hInstance;

//윈도우 핸들
HWND _hWnd;

//함수의 프로토 타입 선언
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void setWindowsSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int cmdShow)
{
	_hInstance = hInstance;

	//윈도우 메세지 구조체
	MSG message;

	//윈도우 클래스 구조체
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;		//클래스 여분 메모리
	wndClass.cbWndExtra = 0;		//윈도우 여분 메모리
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//윈도우 바탕색
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//윈도우 커서모양
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//아이콘 모양
	wndClass.hInstance = hInstance;									//인스턴스 부여
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//프로시저 설정
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//윈도우를 위에 설정한 정보를 토대로 등록해준다
	RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		WINNAME,				//클래스 이름
		WINNAME,				//윈도우 이름
		WS_OVERLAPPEDWINDOW,	//윈도우 창 모양
		WINSTARTX,				//시작좌표 X (left)
		WINSTARTY,				//시작좌표 Y (top)
		WINSIZEX,				//윈도우 창 가로크기
		WINSIZEY,				//윈도우 창 세로크기
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	//클라이언트 영역 재조정 
	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	//실제로 윈도우 창을 우리 눈에 보이게 해주는 함수
	ShowWindow(_hWnd, cmdShow);

	//GetMessage vs PeekMessage
	//겟메세지는 윈도우에서 처리해달라는 메세지가 넘어올때 동작하고
	//픽메세지는 메세지가 있든 없든 계속해서 동작하고 있다.

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);	//키 입력 등의 메시지 처리를 담당
		DispatchMessage(&message);	//실제 윈도우에 메시지를 전달해주는 역할 담당
	}

	return message.wParam;
}

POINT _ptMouse;
RECT _rc;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC			hdc;	//<-- 한 번 HDC가 뭔지 알아두면 좋습니다
	

	char str[128];

	switch (iMessage)
	{
		//윈도우 창이 생성되는 딱 그 순간 신호가 들어옴(1번)
		case WM_CREATE:
			_rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);
		break;
		case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);
		
			sprintf_s(str, "마우스 X : %d, 마우스 Y : %d",
				_ptMouse.x, _ptMouse.y);

			Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);
		
			TextOut(hdc, 20, 20, str, strlen(str));

			EndPaint(hWnd, &ps);
		}
		break;

		case WM_MOUSEMOVE:
			_ptMouse.x = LOWORD(lParam);
			_ptMouse.y = HIWORD(lParam);

			InvalidateRect(_hWnd, NULL, true);
		break;

		case WM_LBUTTONDOWN:
			hdc = GetDC(_hWnd);

			/*
			if (_rc.left < _ptMouse.x && _ptMouse.x < _rc.right &&
				_rc.top < _ptMouse.y && _ptMouse.y < _rc.bottom)
			{
				TextOut(hdc, WINSIZEX / 2, 20, "렉트 안", strlen("렉트 안"));
			}
			else
			{
				TextOut(hdc, WINSIZEX / 2, 20, "렉트 밖", strlen("렉트 안"));
			}*/

			if (PtInRect(&_rc, _ptMouse))
			{
				TextOut(hdc, WINSIZEX / 2, 20, "렉트 안", strlen("렉트 안"));
			}
			else
			{
				TextOut(hdc, WINSIZEX / 2, 20, "렉트 밖", strlen("렉트 안"));
			}


			ReleaseDC(_hWnd, hdc);
		break;

		case WM_LBUTTONUP:

		break;

		case WM_KEYDOWN:
		{
			switch (wParam)
			{
				case VK_ESCAPE:
					PostQuitMessage(0);
				break;
			}
		}
		break;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

//클라이언트 영역 재조정 함수
void setWindowsSize(int x, int y, int width, int height)
{
	RECT winRect;

	winRect.left = 0;
	winRect.top = 0;
	winRect.right = width;
	winRect.bottom = height;

	//윈도우 사이즈 재조정을 해주는 함수
	AdjustWindowRect(&winRect, WINSTYLE, false);

	SetWindowPos(_hWnd, NULL, x, y, (winRect.right - winRect.left),
		(winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);

}