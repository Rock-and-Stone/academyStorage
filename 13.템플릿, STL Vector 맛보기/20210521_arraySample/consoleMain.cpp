#include <iostream>
#include "arraySample.h"

using namespace std;

void main()
{
	arraySample<int> arrNum;

	arrNum.pushBack(1);
	arrNum.pushBack(3);

	for (int i = 0; i < 5; i++)
	{
		arrNum.pushBack(i * 10);
	}

	for (int i = 0; i < arrNum.GetSize(); i++)
	{
		cout << arrNum[i] << endl;
	}


	arraySample<const char*> arrStr;

	arrStr.pushBack("나만 배고프니 지금");
	arrStr.pushBack("1시간 뒤면 퇴근이여 우리");
	arrStr.pushBack("너넨 꼭 부자되거라 주륵");

	for (int i = 0; i < arrStr.GetSize(); i++)
	{
		cout << arrStr[i] << endl;
	}

}