#include <iostream>

using namespace std;

int main()
{
	//1. 문자열을 입력받아가지구 거꾸로 출력되게해볼것

	/*
	char str[128];

	cin >> str;
	
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		cout << str[i];
	}

	cout << endl;
	*/

	//2. 문자열을 입력받으세요
	//   입력받은 문자열의 짝수번째만 거꾸로 출력됩니다
	//예) a b c d e
	//    a d c b e

	char str[128];
	cin >> str;

	for (int i = 0; i < strlen(str); i++)
	{
		//짝수번째 문자열 == 홀수번째 배열인덱스
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