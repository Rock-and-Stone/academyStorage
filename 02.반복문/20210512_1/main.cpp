#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//2. while문
	//참일때만 동작한다 + 기본적으로 무한루프이다

	/*
	while (true)
	{
		cout << "꺼내줘염 어푸어푸" << endl;
	}
	*/

	//제어문
	//1. return - 값을 반환하고 종료한다
	//2. continue - (루프문에서만 사용가능) 연산을 건너뛴다
	//3. break - (루프문에서만 사용가능) 연산을 중지한다
	//4. go to - 쓰지말자...(팀장님이 집으로 보내는 수가..)

	/*
	for (int i = 0; i < 10; i++)
	{
		if (i == 4) continue;

		cout << i << endl;
	}*/

	/*
	srand(time(NULL));

	int elfHP = 10000;
	int elfAtk;

	int orcHP = 10000;
	int orcAtk;

	while (orcHP > 0 && elfHP > 0)
	{
		//if (orcHP < 0 || elfHP < 0) break;

		orcAtk = rand() % 100;
		elfAtk = rand() % 100;

		orcHP -= elfAtk;
		cout << "오크 남은 체력 : " << orcHP << endl;
		elfHP -= orcAtk;
		cout << "엘프 남은 체력 : " << elfHP << endl;
	}
	*/

	int num;
	int count = 0;		//몇 번 만에 맞췄는가 나타내보자

	while (true)
	{
		cout << count << " 번째 입력" << endl;
		cout << "문철이가 좋아하는 숫자를 맞춰라" << endl;
		cout << "0 ~ 15 중에 있다" << endl;
		cout << "입력 : ";

		cin >> num;

		if (num < 0 || num > 15)
		{
			cout << "다시 입력해라" << endl;
			continue;
		}

		if (num == 14)
		{
			cout << "정답!" << endl;
			break;
		}
		
		count++;
	}


	return 0;
}