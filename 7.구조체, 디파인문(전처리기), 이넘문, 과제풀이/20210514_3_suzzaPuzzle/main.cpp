#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int number[25];
	int dest, sour, temp;
	int player;	//ÀÔ·Â¹ÞÀ»²¨
	int zero = 24;

	for (int i = 24; i >= 0; i--)
	{
		number[24 - i] = i;
	}

	for (int i = 0; i < 34; i++)
	{
		//0 ~ 23
		dest = rand() % 24;
		sour = rand() % 24;

		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	while (true)
	{
		system("cls");
		for (int i = 0; i < 25; i++)
		{
			cout << number[i] << "\t";

			if ((i + 1) % 5 == 0) cout << "\n\n\n";
		}

		player = _getch();

		switch (player)
		{
			//¿ì
			case 77:
				if ((zero + 1) % 5 == 0) break;

				temp = number[zero];
				number[zero] = number[zero + 1];
				number[zero + 1] = temp;
				zero++;

			break;
			//ÁÂ
			case 75:
				if (zero % 5 == 0) break;

				temp = number[zero];
				number[zero] = number[zero - 1];
				number[zero - 1] = temp;
				zero--;
			break;
			//¾Æ·¡
			case 80:
				if (zero > 19) break;

				temp = number[zero];
				number[zero] = number[zero + 5];
				number[zero + 5] = temp;
				zero += 5;
			break;
			//À§
			case 72:
				if (zero < 5) break;

				temp = number[zero];
				number[zero] = number[zero - 5];
				number[zero - 5] = temp;
				zero -= 5;
			break;
		}
	}



	return 0;
}