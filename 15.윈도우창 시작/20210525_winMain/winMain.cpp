#include <Windows.h>

//인스턴스(메모리 상에 할당되어 실행중인 프로그램)
HINSTANCE _hInstance;

//윈도우 핸들
HWND _hWnd;

LPCTSTR _lpszClass = TEXT("29기클라쓰");

//함수의 프로토 타입 선언
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

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
	wndClass.lpszClassName = _lpszClass;		
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//윈도우를 위에 설정한 정보를 토대로 등록해준다
	RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		_lpszClass,				//클래스 이름
		_lpszClass,				//윈도우 이름
		WS_OVERLAPPEDWINDOW,	//윈도우 창 모양
		50,						//시작좌표 X (left)
		50,						//시작좌표 Y (top)
		800,					//윈도우 창 가로크기
		600,					//윈도우 창 세로크기
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	//실제로 윈도우 창을 우리 눈에 보이게 해주는 함수
	ShowWindow(_hWnd, cmdShow);

	//GetMessage vs PeekMessage
	//겟메세지는 윈도우에서 처리해달라는 메세지가 넘어올때 동작하고
	//픽메세지는 메세지가 있든 없든 계속해서 동작하고 있다.

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