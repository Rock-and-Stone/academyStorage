#include <iostream>

using namespace std;

int main()
{
	//1. ���ڿ��� �Է¹޾ư����� �Ųٷ� ��µǰ��غ���

	/*
	char str[128];

	cin >> str;
	
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		cout << str[i];
	}

	cout << endl;
	*/

	//2. ���ڿ��� �Է¹�������
	//   �Է¹��� ���ڿ��� ¦����°�� �Ųٷ� ��µ˴ϴ�
	//��) a b c d e
	//    a d c b e

	char str[128];
	cin >> str;

	for (int i = 0; i < strlen(str); i++)
	{
		//¦����° ���ڿ� == Ȧ����° �迭�ε���
		if ( i % 2 != 0)
		{

			//cout << str[strlen(str) - i - ((strlen(str) % 2 == 0 ? 0 : 1))];
			if (strlen(str) % 2 == 0)
			{
				cout << str[strlen(str) - i];
			}
			else
			{
				cout << str[strlen(str) - i - 1];
			}
			
		}
		else cout << str[i];
	}



	return 0;
}