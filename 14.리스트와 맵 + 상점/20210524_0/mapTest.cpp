#include "mapTest.h"



mapTest::mapTest()
{
	//pair가 있고, make_pair

	_mapTest.insert(pair<const char*, int>("민기", 3));
	_mapTest.insert(pair<const char*, int>("반장", 16));
	_mapTest.insert(pair<const char*, int>("준영", 6));
	_mapTest.insert(pair<const char*, int>("서현", 8));

	//이터레이터로 찾을 키 값은 반장이다
	_mi = _mapTest.find("태은");

	//맵이터레이터가 맵의 끝과 같지 않다
	//-> 키 값을 찾았다면
	if (_mi != _mapTest.end())
	{
		cout << _mi->first << "가 좋아하는 숫자는 : " << _mi->second << endl;
	}
	else //없다면
	{
		cout << "그런 학생은 저희 반에 없어영!" << endl;
	}
	


}


mapTest::~mapTest()
{
}
