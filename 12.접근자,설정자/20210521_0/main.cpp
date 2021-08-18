#include "Skeleton.h"
#include "player.h"

void main()
{
	//Skeleton sk; 기본 생성자가 실행된다
	Skeleton sk(50, 10); //생성자 오버로드가 실행된다

	player pl;

	cout << "플레이어 체력 : " << pl.getPlayerHP() << endl;

	pl.setPlayerHP(pl.getPlayerHP() - sk.getSkeletonAtk());

	cout << "플레이어 체력 : " << pl.getPlayerHP() << endl;

	//= <-- 얘는 C방식
	//int num(7);

}