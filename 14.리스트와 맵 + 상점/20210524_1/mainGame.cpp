#include "mainGame.h"



mainGame::mainGame()
{
	_shop = new shop;
	_shop->itemSetup();

	_inven = new inventory;

	_money = 100000;
	_selectNum = 0;

	//처음에는 메인화면(?)을 띄워놓자
	setMainPage();
}


mainGame::~mainGame()
{
	delete _shop;
	delete _inven;
}

void mainGame::setLocation(int number)
{
	
	switch (number)
	{
		case LOCATION_SHOP:
			setShopPage();
		break;
		case LOCATION_INVEN:
			setInvenPage();
		break;
		default:
			setMainPage();
		break;
	}

}

void mainGame::setMainPage()
{
	cout << "============ 29기 잡화상점 =============" << endl;
	cout << "1. 상점               2. 인벤토리" << endl;
	cout << "=======================================" << endl;

	cin >> _selectNum;
	system("cls");
	setLocation(_selectNum);
}

void mainGame::setShopPage()
{
	while (true)
	{
		cout << "=================== 29기 잡화상점 ======================" << endl;
		cout << "1. 무기구 2.방어구 3.악세서리 4. 포선류" << endl;
		cout << "=======================================================" << endl;
		cout << "메인화면으로 가려면 ☞ 0번";

		cin >> _selectNum;
		system("cls");

		if (_selectNum == 0)
		{
			setMainPage();
			break;
		}

		_shop->itemOutput(_selectNum);

		cout << "다른 물건을 보시려면 아무키나 누르세요" << endl;
		cin >> _selectNum;
		system("cls");

	}
}

void mainGame::setInvenPage()
{
}
