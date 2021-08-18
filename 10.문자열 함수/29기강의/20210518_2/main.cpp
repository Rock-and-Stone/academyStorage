#include <iostream>

using namespace std;

int main()
{
	char str[128] = "i my me mine";

	char* str2 = NULL;
	char* token = strtok_s(str, " ", &str2); //문자열의 진짜 끝의 NULL값 까지 자르기위해서

	cout << token << endl;

	while (token != NULL)
	{
		cout << token << endl;
		token = strtok_s(NULL, " ", &str2);
	}
	

	return 0;
}