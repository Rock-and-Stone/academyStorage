#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	/*
	int elfHP = 100;
	int elfAtk = 8;

	int orcHP = 130;
	int orcAtk = 10;

	cout << "����ü�� : " << elfHP << endl;
	cout << "�������ݷ� : " << elfAtk << endl;

	cout << "��ũü�� : " << orcHP << endl;
	cout << "��ũ���ݷ� : " << orcAtk << endl;

	orcHP = orcHP - elfAtk;

	cout << elfAtk << "��ŭ�� �������� �Ծ� ü���� " << orcHP << " ���Ҵ�" << endl;
	cout << "��ũü�� : " << orcHP << endl;

	orcHP -= elfAtk;
	
	cout << "��ũü�� : " << orcHP << endl;

	int healthPotion = 10;

	orcHP += healthPotion;
	*/

	//int num = 2;

	//num += 1;

	//��ġ
	//num++; //+ 1
	//��ġ
	//++num;
	/*
	int a = 3;
	int b = ++a;

	cout << a << endl;
	cout << "b�� : " << b << endl;
	*/

	//��� - cout
	//�Է� - cin
	/*
	int number;

	cout << "���� �����ϴ� ���ڴ�?";
	cin >> number;

	cout << "��� : " << number << endl;
	*/

	//���ǹ�(�б⹮) 
	//1. if
	//2. switch
	//3. ���׿�����(���������X)


	//if ���࿡ ~~ �ϸ�
	srand(time(NULL));

	/*
	int gotcha = rand() % 10;

	cout << gotcha << endl;

	if (gotcha < 2)
	{
		cout << "5�� ������ ���" << endl;
	}
	else if (gotcha >= 2 && gotcha < 5)
	{
		cout << "4�� ������ ���" << endl;
	}
	else//5,6,7,8,9 
	{
		cout << "3�� �ְ� ������" << endl;
	}
	*/

	//2.switch
	//���� �Ǵ� ������(enum��) �� ��밡��

	int selectNum;
	cout << "è�Ǿ��� ���ÿ�" << endl;
	cout << "1. �̷����� 2. Ű�Ƴ� 3. ī��� 4. �����" << endl;

	cin >> selectNum;

	switch (selectNum)
	{
		case 1: //if(selectNum == 1)
			cout << "�̷����Ƹ� �����" << endl;
		break;
		case 2://else if(selectNum == 2)
			cout << "Ű�Ƴ��� �����" << endl;
		break;
		case 3://else if(selectNum == 3)
			cout << "ī����� �����" << endl;
		break;
		case 4://else if(selectNum == 4)
			cout << "������� �����" << endl;
		break;
		default:
			cout << "����ĳ���� �����" << endl;
		break;
	}
	


	return 0;
}