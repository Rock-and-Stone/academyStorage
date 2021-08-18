#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	//1. ���� ���� �� �ʱ�ȭ
	int comNum1, comNum2, comNum3;
	int player1, player2, player3;
	int strikeCount = 0;
	int ballCount = 0;
	int roundCount = 9;

	//���� ���� ���� ��
	while (true)
	{
		comNum1 = rand() % 9 + 1;
		comNum2 = rand() % 10;

		if (comNum2 == comNum1) continue;

		comNum3 = rand() % 10;
		if (comNum3 == comNum2 || comNum3 == comNum1) continue;

		break;
	}

	//���ӷ��� 
	while (true)
	{
		//2��° �Է¹���
		cout << "ù��° �� �Է� : ";
		cin >> player1;

		if (player1 == 0 || player1 > 9)
		{
			cout << "�ٽ� �����" << endl;
			continue;
		}

		cout << "�ι�° �� �Է� : ";
		cin >> player2;

		cout << "����° �� �Է� : ";
		cin >> player3;

		//3. ������ �սô�
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
			cout << "�ƿ�" << endl;
		}
		else if (strikeCount > 0 && ballCount < 1)
		{
			cout << strikeCount << " ��Ʈ����ũ" << endl;
		}
		else if (strikeCount < 1 && ballCount > 0)
		{
			cout << ballCount << "��" << endl;
		}
		else
		{
			cout << strikeCount << " ��Ʈ����ũ" << ballCount << " ��" << endl;
		}

		if (strikeCount >= 3)
		{
			cout << "You Win" << endl;
			break;
		}

		cout << roundCount << " ��ȸ�� ���Ҵ�" << endl;
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