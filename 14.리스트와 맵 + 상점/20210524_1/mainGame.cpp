#include "mainGame.h"



mainGame::mainGame()
{
	_shop = new shop;
	_shop->itemSetup();

	_inven = new inventory;

	_money = 100000;
	_selectNum = 0;

	//ó������ ����ȭ��(?)�� �������
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
	cout << "============ 29�� ��ȭ���� =============" << endl;
	cout << "1. ����               2. �κ��丮" << endl;
	cout << "=======================================" << endl;

	cin >> _selectNum;
	system("cls");
	setLocation(_selectNum);
}

void mainGame::setShopPage()
{
	while (true)
	{
		cout << "=================== 29�� ��ȭ���� ======================" << endl;
		cout << "1. ���ⱸ 2.�� 3.�Ǽ����� 4. ������" << endl;
		cout << "=======================================================" << endl;
		cout << "����ȭ������ ������ �� 0��";

		cin >> _selectNum;
		system("cls");

		if (_selectNum == 0)
		{
			setMainPage();
			break;
		}

		_shop->itemOutput(_selectNum);

		cout << "�ٸ� ������ ���÷��� �ƹ�Ű�� ��������" << endl;
		cin >> _selectNum;
		system("cls");

	}
}

void mainGame::setInvenPage()
{
}
