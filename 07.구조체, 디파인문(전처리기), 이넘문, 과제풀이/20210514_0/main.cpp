#include <iostream>

using namespace std;

//C++ ����ü - ��ü��� �Ѵ� / �⺻ ���������ڰ� public�̴�
//���� �ٸ� ������ �Ǵ� �ڷ����� ���� �� �ִ�

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

	cratos.name = "ũ���佺";
	cratos.hp = 100;
	cratos.speed = 3.0f;
	cratos.isLive = true;

	tagUnit vulture;

	vulture.name = "��ó";
	vulture.hp = 75;
	vulture.mp = 0;
	vulture.speed = 7.0f;

	tagUnit skeleton[3];

	for (int i = 0; i < 3; i++)
	{
		skeleton[i].name = "���̷���";
		skeleton[i].hp = 30;
		skeleton[i].mp = 0;
	}


	return 0;
}