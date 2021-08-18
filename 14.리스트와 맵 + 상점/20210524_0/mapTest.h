#pragma once
#include <iostream>
#include <map>

using namespace std;

class mapTest
{
private:
	//연관 컨테이너 종류 중 하나
	//first, second 인자 2개를 가진다
	//set이란 애도 있는데 first로만 된 map과 같음

	map<const char*, int>			_mapTest;
	map<const char*, int>::iterator _mi;

	//데이터 1만개 미만으로는 벡터가 속도에서 유리하다 (배열로 구성)
	//데이터 1만개 이상부터는 리스트가 속도에서 유리하다
	//데이터 10만개 이상의 데이터는 맵이 유리하다 (레드블랙 트리로 구성)
	//데이터 100만개 이상의 데이터는 해쉬맵(unorded_map)이 유리하다

public:
	mapTest();
	~mapTest();
};

