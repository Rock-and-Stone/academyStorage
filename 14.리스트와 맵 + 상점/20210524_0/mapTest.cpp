#include "mapTest.h"



mapTest::mapTest()
{
	//pair�� �ְ�, make_pair

	_mapTest.insert(pair<const char*, int>("�α�", 3));
	_mapTest.insert(pair<const char*, int>("����", 16));
	_mapTest.insert(pair<const char*, int>("�ؿ�", 6));
	_mapTest.insert(pair<const char*, int>("����", 8));

	//���ͷ����ͷ� ã�� Ű ���� �����̴�
	_mi = _mapTest.find("����");

	//�����ͷ����Ͱ� ���� ���� ���� �ʴ�
	//-> Ű ���� ã�Ҵٸ�
	if (_mi != _mapTest.end())
	{
		cout << _mi->first << "�� �����ϴ� ���ڴ� : " << _mi->second << endl;
	}
	else //���ٸ�
	{
		cout << "�׷� �л��� ���� �ݿ� ���!" << endl;
	}
	


}


mapTest::~mapTest()
{
}
