#pragma once
#include <iostream>
#include <map>

using namespace std;

class mapTest
{
private:
	//���� �����̳� ���� �� �ϳ�
	//first, second ���� 2���� ������
	//set�̶� �ֵ� �ִµ� first�θ� �� map�� ����

	map<const char*, int>			_mapTest;
	map<const char*, int>::iterator _mi;

	//������ 1���� �̸����δ� ���Ͱ� �ӵ����� �����ϴ� (�迭�� ����)
	//������ 1���� �̻���ʹ� ����Ʈ�� �ӵ����� �����ϴ�
	//������ 10���� �̻��� �����ʹ� ���� �����ϴ� (����� Ʈ���� ����)
	//������ 100���� �̻��� �����ʹ� �ؽ���(unorded_map)�� �����ϴ�

public:
	mapTest();
	~mapTest();
};

