#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	//1. 변수 선언 및 초기화
	int comNum = rand() % 1000;
	int roundCount = 9;
	int playerNum;

	cout << "0 ~ 999 중 숫자를 하나 정했다 맞춰봐라" << endl;

	while (true)
	{
		cout << "입력 : ";
		cin >> playerNum;

		if (playerNum < comNum)
		{
			cout << "그거보다 큰뒈? 큰뒈? 큰뒈에에?" << endl;
		}
		if (playerNum > comNum)
		{
			cout << "그거보다 작은데에에에에" << endl;
		}
		if (playerNum == comNum)
		{
			cout << " 오! 정답!" << endl;
			break;
		}

		cout << roundCount << " 회 남았다" << endl;
		roundCount--;
		if (roundCount < 0)
		{
			cout << "너의 패배" << endl;
			cout << "정답공개 : " << comNum << endl;
			break;
		}
	}

	return 0;
}