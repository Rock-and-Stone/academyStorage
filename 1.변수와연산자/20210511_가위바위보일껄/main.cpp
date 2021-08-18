#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int comNum = rand() % 3;
	int playerNum;

	cout << "0. 바위, 1. 가위, 2.보 다 골라라 : ";
	cin >> playerNum;

	switch (comNum)
	{
		case 0:
			//바위
			if (playerNum == 0)
			{
				cout << "비겼당" << endl;
			}
			else if (playerNum == 1)
			{
				cout << "졌다" << endl;
			}
			else
			{
				cout << "이겼다" << endl;
			}
		break;
		case 1:
			//가위
			if (playerNum == 0)
			{
				cout << "이겼당" << endl;
			}
			else if (playerNum == 1)
			{
				cout << "비겼다" << endl;
			}
			else
			{
				cout << "졌다" << endl;
			}
		break;
		case 2:
			//보
		break;
	}


	return 0;
}

