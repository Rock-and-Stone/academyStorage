#include <iostream>
#include <Windows.h>

using namespace std;

static int num = 0;

DWORD WINAPI threadFunc1(LPVOID lParam)
{

	//로딩처리
	while (true)
	{
		num++;
		cout << "넘버 : " << num << endl;
		cout << "쓰레드 1번! 1번! 1번!" << endl;
	}
}


DWORD WINAPI threadFunc2(LPVOID lParam)
{
	while (true)
	{
		num++;
		cout << "넘버 : " << num << endl;
		cout << "쓰레드 2번! 2번! 2번!" << endl;
	}
}

int main()
{
	HANDLE thread1 = NULL;
	HANDLE thread2 = NULL;

	DWORD dwThread1 = 0;
	DWORD dwThread2 = 0;

	thread1 = CreateThread(NULL, 0, threadFunc1, NULL, 0, &dwThread1);
	thread2 = CreateThread(NULL, 0, threadFunc2, NULL, 0, &dwThread2);

	//1. 쓰레드의 보안속성 유무
	//자식 윈도우가 있는 경우에 부모윈도우에서 윈도우 프로세스 핸들이
	//상속되어져있는 경우에만 사용한다함

	//2. 쓰레드의 스택메모리 크기 지정
	//0으로 두면 메인쓰레드 스택 크기와 동일
	//스택오버플로 현상 방지를 위해 별도로 지정가능하게 됨.

	//3. 사용할 쓰레드 함수 이름

	//4. 쓰레드 간의 넘겨줄 데이터 유무 없을땐 널루 지정

	//5. 0은 보통의 쓰레드를 지칭한다
	//CREATE_SUSPENDED 명령어를 사용하면 쓰레드가 따로 실행되지 않음
	//다시 실행해야하는 경우에는 ResumeThread() 함수를 실행해야함

	//6. 쓰레드 관리 ID번호
	//윈도우7 이전에는 NULL을 사용해도 됐는데 이후부터는
	//NULL을 쓰면 쓰레드 생성이 불가능해졌다 그래서 호환성 + 안전성 목적으로 DWORD를 쓴다.

	Sleep(1000);

	return 0;
}