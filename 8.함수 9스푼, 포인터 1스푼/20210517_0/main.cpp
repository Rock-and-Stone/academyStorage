#include <iostream>

using namespace std;

//반환형 함수이름(매개변수 == parameter)

//뭔가를 출력하는 함수
void output()
{
	cout << "내일만하면 석가탄신일이라 수요일 쉽니다" << endl;
}

//싸우는 함수(체력, 공격력) 
int Fight(int hp, int atk)
{
	hp -= atk;

	cout << atk << "만큼의 데미지를 입어 " << hp << "체력이 되었다" << endl;

	return hp;
}

int Heal(int hp, int healRate)
{
	hp += healRate;

	cout << healRate << " 만큼 치유되어 체력이 " << hp << "가 되었다" << endl;

	return hp;
}

void main()
{
	int elfHP = 100;
	int elfAtk = 10;

	int orcHP = 150;
	int orcAtk = 8;

	int redPotion = 30;

	orcHP = Fight(orcHP, elfAtk);
	elfHP = Fight(elfHP, orcAtk);

	orcHP = Fight(orcHP, elfAtk);
	elfHP = Fight(elfHP, orcAtk);

	orcHP = Fight(orcHP, elfAtk);
	elfHP = Fight(elfHP, orcAtk);
	
	elfHP = Heal(elfHP, redPotion);
	
}

