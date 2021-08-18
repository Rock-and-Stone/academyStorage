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

	arrStr.pushBack("���� ������� ����");
	arrStr.pushBack("1�ð� �ڸ� ����̿� �츮");
	arrStr.pushBack("�ʳ� �� ���ڵǰŶ� �ָ�");

	for (int i = 0; i < arrStr.GetSize(); i++)
	{
		cout << arrStr[i] << endl;
	}

}