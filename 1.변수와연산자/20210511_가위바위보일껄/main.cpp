#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int comNum = rand() % 3;
	int playerNum;

	cout << "0. ����, 1. ����, 2.�� �� ���� : ";
	cin >> playerNum;

	switch (comNum)
	{
		case 0:
			//����
			if (playerNum == 0)
			{
				cout << "����" << endl;
			}
			else if (playerNum == 1)
			{
				cout << "����" << endl;
			}
			else
			{
				cout << "�̰��" << endl;
			}
		break;
		case 1:
			//����
			if (playerNum == 0)
			{
				cout << "�̰��" << endl;
			}
			else if (playerNum == 1)
			{
				cout << "����" << endl;
			}
			else
			{
				cout << "����" << endl;
			}
		break;
		case 2:
			//��
		break;
	}


	return 0;
}

