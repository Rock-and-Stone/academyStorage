#include <iostream>

using namespace std;

void main()
{
	//캐릭터는 1바이트여서 문자 하나를 담을 수 있는데
	//배열에 문자열을 담을땐 문자열의 끝을 알리는
	//널 값이 하나 들어간다 
	//char str[5] = "star";

	//1. strlen (string length)약자
	//문자열 길이를 반환하는 함수
	/*
	char str[64] = "apple";

	int num = strlen(str);

	cout << "글자수 몇 개 ? - " << num << endl;
	*/
	//2. strcmp - 문자열 비교 함수
	//두 문자열을 비교해서 오른쪽이 크면 1
	//왼쪽이 크면 -1 , 같으면 0을 반환한다

	/*
	char str[64] = "abc";
	char str2[64] = "abd";

	int result = strcmp(str, str2);

	cout << result << endl;
	*/

	//3.strcat -  문자열 이어붙이기
	//strcat(문자열1, 문자열2) 문자열2를 1에 이어붙인다
	//문자열1은 문자열2를 수용할 수 있을정도로 커야함
	/*
	char str[128] = "i love you ";
	char str2[64] = "three thousand";
	strcat_s(str, str2);

	cout << str << endl;
	*/

	//4. strcpy - 문자열 복사(string copy 약자임)
	//strcpy(문자열1, 문자열2) 문자열2를 문자열1에 복사한다
	//당연히 문자열1은 2를 수용할만큼 버퍼크기를 가져야한다

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