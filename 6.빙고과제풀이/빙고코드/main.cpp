#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int number[25];
	int dest, sour, temp;
	int inputNum;
	int bingoCount = 0;

	for (int i = 0; i < 25; i++)
	{
		number[i] = i + 1;
	}

	for (int i = 0; i < 100; i++)
	{
		dest = rand() % 25;
		sour = rand() % 25;

		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	while (true)
	{
		system("cls");
		
		cout << bingoCount << " ºù°í" << endl;

		for (int i = 0; i < 25; i++)
		{
			if (number[i] == 35)
			{
				cout << (char)number[i] << "\t";
			}
			else cout << number[i] << "\t";

			if ((i + 1) % 5 == 0) cout << endl << endl << endl;
		}

		cout << "ÀÔ·Â : ";
		cin >> inputNum;

		for (int i = 0; i < 25; i++)
		{
			if (inputNum == number[i])
			{
				number[i] = 35;
			}
		}

		bingoCount = 0;

		for (int i = 0; i < 5; i++)
		{
			//°¡·Î ºù°í
			if (number[i * 5] == 35 &&
				number[i * 5 + 1] == 35 &&
				number[i * 5 + 2] == 35 &&
				number[i * 5 + 3] == 35 &&
				number[i * 5 + 4] == 35)
			{
				bingoCount++;
			}

			//¼¼·Î ºù°í

			if (number[i] == 35 &&
				number[i + 5] == 35 &&
				number[i + 5 * 2] == 35 &&
				number[i + 5 * 3] == 35 &&
				number[i + 5 * 4] == 35)
			{
				bingoCount++;
			}
		}

		if (number[0] == 35 &&
			number[6] == 35 &&
			number[12] == 35 &&
			number[18] == 35 &&
			number[24] == 35)
		{
			bingoCount++;
		}

		if (number[4] == 35 &&
			number[8] == 35 &&
			number[12] == 35 &&
			number[16] == 35 &&
			number[20] == 35)
		{
			bingoCount++;
		}

	}


	return 0;
}