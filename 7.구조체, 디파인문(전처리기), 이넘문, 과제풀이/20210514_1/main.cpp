#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

//���� ARROWMAX ��� �ܾ ���� 100�� ��Ÿ����
#define ARROWMAX 100
//#define PLUS(a) a + a

#define BLESSACCOUNT

int main()
{
	int arrow[ARROWMAX];
	int dest, sour, temp;

#ifdef BLESSACCOUNT
	cout << "��ȯȮ�� �� �� UP!" << endl;
#else
	cout << "��ȯȮ���� ����Ʈ ��ġ��" << endl;
#endif


	return 0;
}