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
	weapon1.name = "망령의 블레이드";
	weapon1.description = "망령이 휘두른건지 이 칼을 휘두르다 망령이 된건지는 모른다";
	weapon1.ability = 30;
	weapon1.price = 24000;

	_vItem.push_back(weapon1);

	tagItemInfo weapon2;
	weapon2.itemKind = ITEM_WEAPON;
	weapon2.name = "한조의 활";
	weapon2.description = "무기가 무슨 잘못이 있겠어 니 손을 탓해야지";
	weapon2.ability = 100;
	weapon2.price = 10000;

	_vItem.push_back(weapon2);

	tagItemInfo weapon3;
	weapon3.itemKind = ITEM_WEAPON;
	weapon3.name = "형진이의 바벨 40kg";
	weapon3.description = "봉 무게는 다행히 조상님이 들어줌";
	weapon3.ability = 2300;
	weapon3.price = 500;

	_vItem.push_back(weapon3);

	tagItemInfo armor1;
	armor1.itemKind = ITEM_ARMOR;
	armor1.name = "리치왕의 투구";
	armor1.description = "막강한 힘을 얻게되나 패드립의 왕이 된다";
	armor1.ability = 150;
	armor1.price = 15000;
	_vItem.push_back(armor1);

	tagItemInfo armor2;
	armor2.itemKind = ITEM_ARMOR;
	armor2.name = "묠니르(feat.HALO)";
	armor2.description = "그거 입었다고 스파르탄이 되는건 아니다";
	armor2.ability = 300;
	armor2.price = 24000;

	_vItem.push_back(armor2);

	tagItemInfo armor3;
	armor3.itemKind = ITEM_ARMOR;
	armor3.name = "워모그의 갑옷";
	armor3.description = "우리팀 이즈리얼이 입고있었다";
	armor3.ability = 50;
	armor3.price = 3000;
	_vItem.push_back(armor3);

	tagItemInfo acce1;
	acce1.itemKind = ITEM_ACCESORY;
	acce1.name = "사우론의 절대반지";
	acce1.description = "뒷면에 '종로금은방'이라고 적혀있다";
	acce1.ability = 1000;
	acce1.price = 5000;

	_vItem.push_back(acce1);

	tagItemInfo acce2;
	acce2.itemKind = ITEM_ACCESORY;
	acce2.name = "도란링";
	acce2.description = "적을 해치우면 마나가 차오른다";
	acce2.ability = 15;
	acce2.price = 400;
	_vItem.push_back(acce2);

	tagItemInfo potion1;
	potion1.itemKind = ITEM_POTION;
	potion1.name = "민기의 빨간포션";
	potion1.description = "체력 3000 회복";
	potion1.ability = 3000;
	potion1.price = 1500;

	_vItem.push_back(potion1);

	tagItemInfo potion2;
	potion2.itemKind = ITEM_POTION;
	potion2.name = "한길이의 레드불";
	potion2.description = "날개를 달아주진 않아요";
	potion2.ability = 1000;
	potion2.price = 1000;

	_vItem.push_back(potion2);


}

void shop::itemOutput(int itemNum)
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		if (_viItem->itemKind != itemNum) continue;

		cout << "===================== 29기 상 점 ======================" << endl;
		cout << "이  름 : " << _viItem->name << endl;
		cout << "성  능 : " << _viItem->ability << endl;
		cout << "가  격 : " << _viItem->price << endl;
		cout << "설  명 : " << _viItem->description << endl;
		cout << "======================================================" << endl;
	}
}
