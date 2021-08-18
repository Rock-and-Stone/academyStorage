#include <iostream>

using namespace std;

//C++ 구조체 - 객체라고도 한다 / 기본 접근제한자가 public이다
//각기 다른 변수형 또는 자료형을 담을 수 있다

struct tagUnit
{
	const char* name;
	int hp;
	int mp;
	int atk;
	float speed;
	bool isLive;
};

int main()
{
	tagUnit cratos;

	cratos.name = "크레토스";
	cratos.hp = 100;
	cratos.speed = 3.0f;
	cratos.isLive = true;

	tagUnit vulture;

	vulture.name = "벌처";
	vulture.hp = 75;
	vulture.mp = 0;
	vulture.speed = 7.0f;

	tagUnit skeleton[3];

	for (int i = 0; i < 3; i++)
	{
		skeleton[i].name = "스켈레톤";
		skeleton[i].hp = 30;
		skeleton[i].mp = 0;
	}


	return 0;
}