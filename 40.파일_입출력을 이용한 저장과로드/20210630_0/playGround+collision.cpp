#include "pch.h"
#include "playGround.h"

//��������� �������� cpp ������ �Ŵ���(?) �� �ְԵǴµ�
//�ڵ差�� �������� ������ �Լ����� ������ cpp������ ����
//�����ϴ� ������ ������ ���� ��ȣ�Ͽ��� (Ư�� �¶��� MMORPG�� �ڵ差�� ��û ������)

void playGround::collision()
{
	for (int i = 0; i < _em->getVMinion().size(); i++)
	{
		for (int j = 0; j < _ship->getHellFire()->getVBullet().size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_ship->getHellFire()->getVBullet()[j].rc, &
				_em->getVMinion()[i]->getRect()))
			{
				_em->removeMinion(i);
				_ship->getHellFire()->removeMissile(j);
				break;
			}
		}
	}


}