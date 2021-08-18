#include <iostream>
#include <time.h>	//시스템 시간을 가지고 랜덤함수를 사용할수있음

using namespace std;

int main()
{
	//연산자
	//산술연산자
	// +		더하기
	// -		빼기
	// *		곱하기
	// /		나누기
	// %		나머지

	srand(time(NULL));

	//rand() == 랜덤함수(난수)를 발생함
	/*
	int num = rand();
	int num2 = rand();

	cout << "변수 num : " << num << endl;
	cout << "변수 num2 : " << num2 << endl;
	*/

	//난수에 나머지를 걸게되면 항상 그 수보다 1작은 범위까지
	//발생된다
	//        0 ~ 5
	//int dice = rand() % 6 + 1;

	//cout << "앞으로 " << dice << "칸 가시오" << endl;

	//날좀바바
	//oldClub 3 ~ 7
	int oldClub = rand() % 5 + 3;

	//숏소드(sword) 11 ~ 15

	// 0 or 1
	bool isWin = rand() % 2;

	int lottoNum = rand() % 45 + 1;
	int lottoNum1 = rand() % 45 + 1;
	int lottoNum2 = rand() % 45 + 1;
	int lottoNum3 = rand() % 45 + 1;
	int lottoNum4 = rand() % 45 + 1;
	int lottoNum5 = rand() % 45 + 1;

	cout << lottoNum << endl;
	cout << lottoNum1 << endl;
	cout << lottoNum2 << endl;
	cout << lottoNum3 << endl;
	cout << lottoNum4 << endl;
	cout << lottoNum5 << endl;

	return 0;
}