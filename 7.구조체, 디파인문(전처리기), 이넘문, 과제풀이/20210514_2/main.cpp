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
			cout << "�⺻�Ѿ��� �����̴�" << endl;
		break;
		case POWER1:
			cout << "1�ܰ� �Ŀ���" << endl;
		break;
		case POWER2:
			cout << "2�ܰ� �Ŀ���" << endl;
		break;
		case POWERMAX:
			cout << "�ƽ� �Ŀ�" << endl;
		break;
	}

	cout << "�ұ��̳�! ����ȣ! " << endl;
	cout << "�ұ��̳�! ����ȣ! " << endl;
	cout << "�ұ��̳�! ����ȣ! " << endl;
	

	return 0;
}