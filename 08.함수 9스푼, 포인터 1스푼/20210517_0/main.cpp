#include <iostream>

using namespace std;

//��ȯ�� �Լ��̸�(�Ű����� == parameter)

//������ ����ϴ� �Լ�
void output()
{
	cout << "���ϸ��ϸ� ����ź�����̶� ������ ���ϴ�" << endl;
}

//�ο�� �Լ�(ü��, ���ݷ�) 
int Fight(int hp, int atk)
{
	hp -= atk;

	cout << atk << "��ŭ�� �������� �Ծ� " << hp << "ü���� �Ǿ���" << endl;

	return hp;
}

int Heal(int hp, int healRate)
{
	hp += healRate;

	cout << healRate << " ��ŭ ġ���Ǿ� ü���� " << hp << "�� �Ǿ���" << endl;

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

