#pragma once
#include <iostream>

using namespace std;

class motherClass
{
private:
	//�� ��ü�� ���ٰ����ϴ�
	int _mothersMoney;


protected:
	//��Ӱ��迡���� ���ٰ�����.
	int _familyMoney;	//��Ȱ��

public:
	int _freeMoney;		//�氡�� ������ ��


	motherClass();
	~motherClass();
};

