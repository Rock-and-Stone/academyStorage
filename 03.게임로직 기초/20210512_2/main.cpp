#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	//1. ���� ���� �� �ʱ�ȭ
	int comNum = rand() % 1000;
	int roundCount = 9;
	int playerNum;

	cout << "0 ~ 999 �� ���ڸ� �ϳ� ���ߴ� �������" << endl;

	while (true)
	{
		cout << "�Է� : ";
		cin >> playerNum;

		if (playerNum < comNum)
		{
			cout << "�װź��� ū��? ū��? ū�ؿ���?" << endl;
		}
		if (playerNum > comNum)
		{
			cout << "�װź��� ��������������" << endl;
		}
		if (playerNum == comNum)
		{
			cout << " ��! ����!" << endl;
			break;
		}

		cout << roundCount << " ȸ ���Ҵ�" << endl;
		roundCount--;
		if (roundCount < 0)
		{
			cout << "���� �й�" << endl;
			cout << "������� : " << comNum << endl;
			break;
		}
	}

	return 0;
}