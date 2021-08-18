#include <Windows.h>
#include <iostream>

using namespace std;

int num = 0;

//멀티 쓰레드 동기화 개념 크게 2개가 있음
//커널 영역 동기화
//비커널 영역 동기화

//커널 영역 동기화
//뮤텍스, 세마포어 방식이 있음
//기능이 많음, 속도는 느림

//비커널 영역 동기화 
//크리티컬 섹션 방식이 있음
//기능이 없다보니 속도가 빠름

CRITICAL_SECTION cs;

DWORD WINAPI threadFunc1(LPVOID lpParam)
{
	//크리티컬 섹션 초기화
	EnterCriticalSection(&cs);

	for (int i = 0; i < 10; ++i)
	{
		num++;
		cout << "1번 쓰레드드드드" << endl;
		cout << num << endl;
	}

	//얘가 실제로 데이터 넘겨주는 애임
	LeaveCriticalSection(&cs);

	return 0;
}

DWORD WINAPI threadFunc2(LPVOID lpParam)
{
	//크리티컬 섹션 초기화
	EnterCriticalSection(&cs);

	for (int i = 0; i < 10; ++i)
	{
		num++;
		cout << "2번 쓰레드드드드" << endl;
		cout << num << endl;
	}

	//얘가 실제로 데이터 넘겨주는 애임
	LeaveCriticalSection(&cs);

	return 0;
}

int main()
{
	HANDLE thread[2] = { NULL, NULL };

	DWORD dwThread1 = 0;
	DWORD dwThread2 = 1;

	//크리티컬 섹션을 이용해서 멀티쓰레드 동기화 하려면 필수임 (초기화)
	InitializeCriticalSection(&cs);

	thread[0] = CreateThread(NULL, 0, threadFunc1, NULL, 0, &dwThread1);
	thread[1] = CreateThread(NULL, 0, threadFunc2, NULL, 0, &dwThread2);

	//1번째 인자 : 기다려야할 오브젝트 수 (쓰레드 갯수)
	//2번째 인자 : 쓰레드 포인터 주소값
	//3번째 인자 : TRUE 등록된 쓰레드 전부 기다린다 FALSE 하나만 기다린다
	//4번째 인자 : 얼마나 기다릴껀지

	WaitForMultipleObjects(2, thread, TRUE, INFINITY);

	Sleep(1000);

	return 0;
}