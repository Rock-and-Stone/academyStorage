#include <iostream>

using namespace std;

int main()
{
	char str[128] = "i my me mine";

	char* str2 = NULL;
	char* token = strtok_s(str, " ", &str2); //���ڿ��� ��¥ ���� NULL�� ���� �ڸ������ؼ�

	cout << token << endl;

	while (token != NULL)
	{
		cout << token << endl;
		token = strtok_s(NULL, " ", &str2);
	}
	

	return 0;
}