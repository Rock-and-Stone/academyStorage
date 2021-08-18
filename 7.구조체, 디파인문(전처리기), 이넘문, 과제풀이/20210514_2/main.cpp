#include <iostream>

using namespace std;

enum STATE
{
	POWER_IDLE,
	POWER1,
	POWER2,
	POWERMAX
};

int main()
{
	STATE powerState;

	powerState = POWER_IDLE;

	if (powerState == POWER_IDLE)
	{
		powerState = POWER1;
	}

	switch (powerState)
	{
		case POWER_IDLE:
			cout << "기본총알의 상태이다" << endl;
		break;
		case POWER1:
			cout << "1단계 파워업" << endl;
		break;
		case POWER2:
			cout << "2단계 파워업" << endl;
		break;
		case POWERMAX:
			cout << "맥스 파워" << endl;
		break;
	}

	cout << "불금이네! 무야호! " << endl;
	cout << "불금이네! 무야호! " << endl;
	cout << "불금이네! 무야호! " << endl;
	

	return 0;
}