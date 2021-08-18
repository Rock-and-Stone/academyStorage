#include "listTest.h"

listTest::listTest()
{
	_lNum.push_back(1);
	_lNum.push_back(3);
	_lNum.push_back(5);

	_lNum.push_front(99);
	_lNum.push_front(77);

	_lNum.insert(_lNum.begin(), 999);

	for (_liNum = _lNum.begin(); _liNum != _lNum.end(); ++_liNum)
	{
		cout << *_liNum << endl;
	}

}


listTest::~listTest()
{
}
