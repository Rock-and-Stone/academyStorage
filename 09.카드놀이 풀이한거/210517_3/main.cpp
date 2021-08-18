#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	srand((unsigned int)time(NULL));

	int card[52];
	int shape[3], number[3];
	int dest, sour, temp;
	int money = 1000000;
	int betting;
	int turn = 0;

	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
	}

	for (int i = 0; i < 777; i++)
	{
		dest = rand() % 52;
		sour = rand() % 52;

		temp = card[dest];
		card[dest] = card[sour];
		card[sour] = temp;
	}

	while (true)
	{
		cout << "�ù� 29���� �Ͽ콺" << endl;
		cout << "�� �� �� : " << money << endl;

		for (int i = 0; i < 3; i++)
		{
			shape[i] = card[i + turn] / 13; 
			number[i] = card[i + turn] % 13;

			if (i == 2) break;
			switch (shape[i])
			{
				case 0:
					cout << "��";
				break;
				case 1:
					cout << "��";
				break;
				case 2:
					cout << "��";
				break;
				case 3:
					cout << "��";
				break;
			}

			switch (number[i])
			{
				case 0:
					cout << "A\t";
				break;
				case 10:
					cout << "J\t";
				break;
				case 11:
					cout << "Q\t";
				break;
				case 12:
					cout << "K\t";
				break;
				default:
					cout << number[i] + 1 << "\t";
				break;
			}
		}

		cout << endl;
		cout << "������ �غ��� �ּҹ��þ��� 10�����̴�" << endl;
		cout << "���� : ";
		cin >> betting;

		if (betting < 100000 || betting > money)
		{
			cout << "�ٽ� �ɾ�׾�?" << endl;
			continue;
		}

		if ((number[0] < number[2] && number[2] < number[1]) ||
			(number[1] < number[2] && number[2] < number[0]))
		{
			money += betting;
			cout << betting << " ȹ��!" << endl;
		}
		else
		{
			money -= betting;
			cout << betting << "����!" << endl;
		}

		if (money < 100000)
		{
			cout << "���̰� �� �����̳�" << endl;
			break;
		}

		turn += 3;
	}

}