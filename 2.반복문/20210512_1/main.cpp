#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//2. while��
	//���϶��� �����Ѵ� + �⺻������ ���ѷ����̴�

	/*
	while (true)
	{
		cout << "�����࿰ ��Ǫ��Ǫ" << endl;
	}
	*/

	//���
	//1. return - ���� ��ȯ�ϰ� �����Ѵ�
	//2. continue - (������������ ��밡��) ������ �ǳʶڴ�
	//3. break - (������������ ��밡��) ������ �����Ѵ�
	//4. go to - ��������...(������� ������ ������ ����..)

	/*
	for (int i = 0; i < 10; i++)
	{
		if (i == 4) continue;

		cout << i << endl;
	}*/

	/*
	srand(time(NULL));

	int elfHP = 10000;
	int elfAtk;

	int orcHP = 10000;
	int orcAtk;

	while (orcHP > 0 && elfHP > 0)
	{
		//if (orcHP < 0 || elfHP < 0) break;

		orcAtk = rand() % 100;
		elfAtk = rand() % 100;

		orcHP -= elfAtk;
		cout << "��ũ ���� ü�� : " << orcHP << endl;
		elfHP -= orcAtk;
		cout << "���� ���� ü�� : " << elfHP << endl;
	}
	*/

	int num;
	int count = 0;		//�� �� ���� ����°� ��Ÿ������

	while (true)
	{
		cout << count << " ��° �Է�" << endl;
		cout << "��ö�̰� �����ϴ� ���ڸ� �����" << endl;
		cout << "0 ~ 15 �߿� �ִ�" << endl;
		cout << "�Է� : ";

		cin >> num;

		if (num < 0 || num > 15)
		{
			cout << "�ٽ� �Է��ض�" << endl;
			continue;
		}

		if (num == 14)
		{
			cout << "����!" << endl;
			break;
		}
		
		count++;
	}


	return 0;
}