#include <iostream>

using namespace std;

void main()
{
	//ĳ���ʹ� 1����Ʈ���� ���� �ϳ��� ���� �� �ִµ�
	//�迭�� ���ڿ��� ������ ���ڿ��� ���� �˸���
	//�� ���� �ϳ� ���� 
	//char str[5] = "star";

	//1. strlen (string length)����
	//���ڿ� ���̸� ��ȯ�ϴ� �Լ�
	/*
	char str[64] = "apple";

	int num = strlen(str);

	cout << "���ڼ� �� �� ? - " << num << endl;
	*/
	//2. strcmp - ���ڿ� �� �Լ�
	//�� ���ڿ��� ���ؼ� �������� ũ�� 1
	//������ ũ�� -1 , ������ 0�� ��ȯ�Ѵ�

	/*
	char str[64] = "abc";
	char str2[64] = "abd";

	int result = strcmp(str, str2);

	cout << result << endl;
	*/

	//3.strcat -  ���ڿ� �̾���̱�
	//strcat(���ڿ�1, ���ڿ�2) ���ڿ�2�� 1�� �̾���δ�
	//���ڿ�1�� ���ڿ�2�� ������ �� ���������� Ŀ����
	/*
	char str[128] = "i love you ";
	char str2[64] = "three thousand";
	strcat_s(str, str2);

	cout << str << endl;
	*/

	//4. strcpy - ���ڿ� ����(string copy ������)
	//strcpy(���ڿ�1, ���ڿ�2) ���ڿ�2�� ���ڿ�1�� �����Ѵ�
	//�翬�� ���ڿ�1�� 2�� �����Ҹ�ŭ ����ũ�⸦ �������Ѵ�

	/*
	char str[128];
	char str2[128] = "home sweet home";
	strcpy_s(str, str2);

	cout << str << endl;
	*/
	/*
	char str[128];
	const char* str2 = "take me home country load";

	cout << str2 << endl;

	strcpy_s(str, str2);

	cout << str << endl;
	*/

	const char* star = "*****";
	const char* space = "    ";

	for (int i = 0; i < 5; i++)
	{
		cout << star + i << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << star + 4 - i << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << space + 4 - i << star + i << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << space + i << star + 4 - i << endl;
	}
}