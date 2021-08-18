#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	//1. 변수 선언 및 초기화
	int comNum1, comNum2, comNum3;
	int player1, player2, player3;
	int strikeCount = 0;
	int ballCount = 0;
	int roundCount = 9;

	//컴터 숫자 정한 곳
	while (true)
	{
		comNum1 = rand() % 9 + 1;
		comNum2 = rand() % 10;

		if (comNum2 == comNum1) continue;

		comNum3 = rand() % 10;
		if (comNum3 == comNum2 || comNum3 == comNum1) continue;

		break;
	}

	//게임로직 
	while (true)
	{
		//2번째 입력받자
		cout << "첫번째 수 입력 : ";
		cin >> player1;

		if (player1 == 0 || player1 > 9)
		{
			cout << "다시 츄라이" << endl;
			continue;
		}

		cout << "두번째 수 입력 : ";
		cin >> player2;

		cout << "세번째 수 입력 : ";
		cin >> player3;

		//3. 연산을 합시다
		if (comNum1 == player1) strikeCount++;
		if (comNum1 == player2) ballCount++;
		if (comNum1 == player3) ballCount++;
		if (comNum2 == player1) ballCount++;
		if (comNum2 == player2) strikeCount++;
		if (comNum2 == player3) ballCount++;
		if (comNum3 == player1) ballCount++;
		if (comNum3 == player2) ballCount++;
		if (comNum3 == player3) strikeCount++;

		if (strikeCount < 1 && ballCount < 1)
		{
			cout << "아웃" << endl;
		}
		else if (strikeCount > 0 && ballCount < 1)
		{
			cout << strikeCount << " 스트라이크" << endl;
		}
		else if (strikeCount < 1 && ballCount > 0)
		{
			cout << ballCount << "볼" << endl;
		}
		else
		{
			cout << strikeCount << " 스트라이크" << ballCount << " 볼" << endl;
		}

		if (strikeCount >= 3)
		{
			cout << "You Win" << endl;
			break;
		}

		cout << roundCount << " 기회가 남았다" << endl;
		roundCount--;

		strikeCount = ballCount = 0;

		if (roundCount < 0)
		{
			cout << "G A M E O V E R" << endl;
			break;
		}

	}


	return 0;
}