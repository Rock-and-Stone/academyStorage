#include <iostream>

using namespace std;

// call by value
//장점 - 원본 데이터를 건드리지 않는다.(안정적이다!?)
//단점 - 매개변수를 내부에서 복사해서 쓰기때문에 속도는 느리다
/*
void Attack(int hp, int atk)
{
	hp -= atk;

	cout << "현재 체력 : " << hp << endl;
}*/

//call by reference
//장점 - 내부에서 복사를 거치지 않기 때문에 빠름 빠름
//단점 - 원본 데이터를 건드리기 때문에 값변형이 일어날수있다
void Attack(int& hp, int& atk)
{
	hp -= atk;

	cout << "현재 체력 : " << hp << endl;
}

void main()
{
	/*
	int elfHP = 100;
	int elfAtk = 12;

	int orcHP = 200;
	int orcAtk = 10;

	Attack(elfHP, orcAtk);
	Attack(elfHP, orcAtk);
	Attack(elfHP, orcAtk);
	*/

	int a = 3;	//int변수 a
	int b = 7;	//int변수 b
	int* c;		//int포인터 c

	//포인터 == 가르키는거
	cout << "b의 값 : " << b << endl;

	c = &b;

	cout << "&b의 값 : " << &b << endl;

	*c = 9;

	cout << "b의 값 : " << b << endl;


}