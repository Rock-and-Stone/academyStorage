#include <iostream>

using namespace std;

// call by value
//���� - ���� �����͸� �ǵ帮�� �ʴ´�.(�������̴�!?)
//���� - �Ű������� ���ο��� �����ؼ� ���⶧���� �ӵ��� ������
/*
void Attack(int hp, int atk)
{
	hp -= atk;

	cout << "���� ü�� : " << hp << endl;
}*/

//call by reference
//���� - ���ο��� ���縦 ��ġ�� �ʱ� ������ ���� ����
//���� - ���� �����͸� �ǵ帮�� ������ �������� �Ͼ���ִ�
void Attack(int& hp, int& atk)
{
	hp -= atk;

	cout << "���� ü�� : " << hp << endl;
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

	int a = 3;	//int���� a
	int b = 7;	//int���� b
	int* c;		//int������ c

	//������ == ����Ű�°�
	cout << "b�� �� : " << b << endl;

	c = &b;

	cout << "&b�� �� : " << &b << endl;

	*c = 9;

	cout << "b�� �� : " << b << endl;


}