#include "Skeleton.h"
#include "player.h"

void main()
{
	//Skeleton sk; �⺻ �����ڰ� ����ȴ�
	Skeleton sk(50, 10); //������ �����ε尡 ����ȴ�

	player pl;

	cout << "�÷��̾� ü�� : " << pl.getPlayerHP() << endl;

	pl.setPlayerHP(pl.getPlayerHP() - sk.getSkeletonAtk());

	cout << "�÷��̾� ü�� : " << pl.getPlayerHP() << endl;

	//= <-- ��� C���
	//int num(7);

}