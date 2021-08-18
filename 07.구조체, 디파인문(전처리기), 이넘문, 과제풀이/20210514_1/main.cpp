#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

//이제 ARROWMAX 라는 단어가 정수 100을 나타낸다
#define ARROWMAX 100
//#define PLUS(a) a + a

#define BLESSACCOUNT

int main()
{
	int arrow[ARROWMAX];
	int dest, sour, temp;

#ifdef BLESSACCOUNT
	cout << "소환확률 좀 더 UP!" << endl;
#else
	cout << "소환확률은 디폴트 수치로" << endl;
#endif


	return 0;
}