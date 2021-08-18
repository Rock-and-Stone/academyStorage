#pragma once
#include <iostream>

using namespace std;

class motherClass
{
private:
	//이 객체만 접근가능하다
	int _mothersMoney;


protected:
	//상속관계에서만 접근가능함.
	int _familyMoney;	//생활비

public:
	int _freeMoney;		//길가에 떨어진 돈


	motherClass();
	~motherClass();
};

