#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	//int �迭�� 45�� ����
	int number[45];
	int dest, sour, temp;

	//�迭 �ʱ�ȭ
	for (int i = 0; i < 45; i++)
	{
		number[i] = i + 1;
	}

	//������ �Ҷ��� for���� ������ ���� Ƚ��
	for (int i = 0; i < 333; i++)
	{
		dest = rand() % 45; //�迭�� �ε��� ������ŭ ����
		sour = rand() % 45;	

		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	//��� 
	for (int i = 0; i < 6; i++)
	{
		cout << number[i] << endl;
	}


	return 0;
}