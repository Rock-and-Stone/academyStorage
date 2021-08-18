#include "shop.h"



shop::shop()
{
}


shop::~shop()
{
}

void shop::itemSetup()
{
	tagItemInfo weapon1;
	weapon1.itemKind = ITEM_WEAPON;
	weapon1.name = "������ ���̵�";
	weapon1.description = "������ �ֵθ����� �� Į�� �ֵθ��� ������ �Ȱ����� �𸥴�";
	weapon1.ability = 30;
	weapon1.price = 24000;

	_vItem.push_back(weapon1);

	tagItemInfo weapon2;
	weapon2.itemKind = ITEM_WEAPON;
	weapon2.name = "������ Ȱ";
	weapon2.description = "���Ⱑ ���� �߸��� �ְھ� �� ���� ſ�ؾ���";
	weapon2.ability = 100;
	weapon2.price = 10000;

	_vItem.push_back(weapon2);

	tagItemInfo weapon3;
	weapon3.itemKind = ITEM_WEAPON;
	weapon3.name = "�������� �ٺ� 40kg";
	weapon3.description = "�� ���Դ� ������ ������� �����";
	weapon3.ability = 2300;
	weapon3.price = 500;

	_vItem.push_back(weapon3);

	tagItemInfo armor1;
	armor1.itemKind = ITEM_ARMOR;
	armor1.name = "��ġ���� ����";
	armor1.description = "������ ���� ��Եǳ� �е帳�� ���� �ȴ�";
	armor1.ability = 150;
	armor1.price = 15000;
	_vItem.push_back(armor1);

	tagItemInfo armor2;
	armor2.itemKind = ITEM_ARMOR;
	armor2.name = "���ϸ�(feat.HALO)";
	armor2.description = "�װ� �Ծ��ٰ� ���ĸ�ź�� �Ǵ°� �ƴϴ�";
	armor2.ability = 300;
	armor2.price = 24000;

	_vItem.push_back(armor2);

	tagItemInfo armor3;
	armor3.itemKind = ITEM_ARMOR;
	armor3.name = "������� ����";
	armor3.description = "�츮�� ������� �԰��־���";
	armor3.ability = 50;
	armor3.price = 3000;
	_vItem.push_back(armor3);

	tagItemInfo acce1;
	acce1.itemKind = ITEM_ACCESORY;
	acce1.name = "������ �������";
	acce1.description = "�޸鿡 '���α�����'�̶�� �����ִ�";
	acce1.ability = 1000;
	acce1.price = 5000;

	_vItem.push_back(acce1);

	tagItemInfo acce2;
	acce2.itemKind = ITEM_ACCESORY;
	acce2.name = "������";
	acce2.description = "���� ��ġ��� ������ ��������";
	acce2.ability = 15;
	acce2.price = 400;
	_vItem.push_back(acce2);

	tagItemInfo potion1;
	potion1.itemKind = ITEM_POTION;
	potion1.name = "�α��� ��������";
	potion1.description = "ü�� 3000 ȸ��";
	potion1.ability = 3000;
	potion1.price = 1500;

	_vItem.push_back(potion1);

	tagItemInfo potion2;
	potion2.itemKind = ITEM_POTION;
	potion2.name = "�ѱ����� �����";
	potion2.description = "������ �޾����� �ʾƿ�";
	potion2.ability = 1000;
	potion2.price = 1000;

	_vItem.push_back(potion2);


}

void shop::itemOutput(int itemNum)
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		if (_viItem->itemKind != itemNum) continue;

		cout << "===================== 29�� �� �� ======================" << endl;
		cout << "��  �� : " << _viItem->name << endl;
		cout << "��  �� : " << _viItem->ability << endl;
		cout << "��  �� : " << _viItem->price << endl;
		cout << "��  �� : " << _viItem->description << endl;
		cout << "======================================================" << endl;
	}
}
