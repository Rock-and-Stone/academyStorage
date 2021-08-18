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

	cout << "엘프체력 : " << elfHP << endl;
	cout << "엘프공격력 : " << elfAtk << endl;

	cout << "오크체력 : " << orcHP << endl;
	cout << "오크공격력 : " << orcAtk << endl;

	orcHP = orcHP - elfAtk;

	cout << elfAtk << "만큼의 데미지를 입어 체력이 " << orcHP << " 남았다" << endl;
	cout << "오크체력 : " << orcHP << endl;

	orcHP -= elfAtk;
	
	cout << "오크체력 : " << orcHP << endl;

	int healthPotion = 10;

	orcHP += healthPotion;
	*/

	//int num = 2;

	//num += 1;

	//후치
	//num++; //+ 1
	//전치
	//++num;
	/*
	int a = 3;
	int b = ++a;

	cout << a << endl;
	cout << "b는 : " << b << endl;
	*/

	//출력 - cout
	//입력 - cin
	/*
	int number;

	cout << "내가 좋아하는 숫자는?";
	cin >> number;

	cout << "결과 : " << number << endl;
	*/

	//조건문(분기문) 
	//1. if
	//2. switch
	//3. 삼항연산자(사망연산자X)


	//if 만약에 ~~ 하면
	srand(time(NULL));

	/*
	int gotcha = rand() % 10;

	cout << gotcha << endl;

	if (gotcha < 2)
	{
		cout << "5성 영웅을 줘라" << endl;
	}
	else if (gotcha >= 2 && gotcha < 5)
	{
		cout << "4성 영웅을 줘라" << endl;
	}
	else//5,6,7,8,9 
	{
		cout << "3성 주고 보내라" << endl;
	}
	*/

	//2.switch
	//정수 또는 열거형(enum문) 만 사용가능

	int selectNum;
	cout << "챔피언을 고르시오" << endl;
	cout << "1. 이렐리아 2. 키아나 3. 카사딘 4. 르블랑" << endl;

	cin >> selectNum;

	switch (selectNum)
	{
		case 1: //if(selectNum == 1)
			cout << "이렐리아를 골랐다" << endl;
		break;
		case 2://else if(selectNum == 2)
			cout << "키아나를 골랐다" << endl;
		break;
		case 3://else if(selectNum == 3)
			cout << "카사딘을 골랐다" << endl;
		break;
		case 4://else if(selectNum == 4)
			cout << "르블랑을 골랐다" << endl;
		break;
		default:
			cout << "랜덤캐릭을 골랐다" << endl;
		break;
	}
	


	return 0;
}