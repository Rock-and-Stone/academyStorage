#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum ITEM
{
	ITEM_WEAPON = 1,
	ITEM_ARMOR,
	ITEM_ACCESORY,
	ITEM_POTION,
	ITEM_END
};

struct tagItemInfo
{
	ITEM itemKind;			//아이템 종류
	string name;			//아이템 이름
	string description;		//아이템 설명
	int ability;			//아이템 성능
	int price;				//가격대위
};

class shop
{
private:
	//구조체를 담는 벡터 선언
	vector<tagItemInfo>				_vItem;
	vector<tagItemInfo>::iterator	_viItem;

public:
	shop();
	~shop();

	//아이템 설정
	void itemSetup();

	//아이템 출력
	void itemOutput(int itemNum);

	vector<tagItemInfo> getVItem() { return _vItem; }
	vector<tagItemInfo>::iterator getVIItem() { return _viItem; }
};

