#include <iostream>
#include <time.h>	//�ý��� �ð��� ������ �����Լ��� ����Ҽ�����

using namespace std;

int main()
{
	//������
	//���������
	// +		���ϱ�
	// -		����
	// *		���ϱ�
	// /		������
	// %		������

	srand(time(NULL));

	//rand() == �����Լ�(����)�� �߻���
	/*
	int num = rand();
	int num2 = rand();

	cout << "���� num : " << num << endl;
	cout << "���� num2 : " << num2 << endl;
	*/

	//������ �������� �ɰԵǸ� �׻� �� ������ 1���� ��������
	//�߻��ȴ�
	//        0 ~ 5
	//int dice = rand() % 6 + 1;

	//cout << "������ " << dice << "ĭ ���ÿ�" << endl;

	//�����ٹ�
	//oldClub 3 ~ 7
	int oldClub = rand() % 5 + 3;

	//���ҵ�(sword) 11 ~ 15

	// 0 or 1
	bool isWin = rand() % 2;

	int lottoNum = rand() % 45 + 1;
	int lottoNum1 = rand() % 45 + 1;
	int lottoNum2 = rand() % 45 + 1;
	int lottoNum3 = rand() % 45 + 1;
	int lottoNum4 = rand() % 45 + 1;
	int lottoNum5 = rand() % 45 + 1;

	cout << lottoNum << endl;
	cout << lottoNum1 << endl;
	cout << lottoNum2 << endl;
	cout << lottoNum3 << endl;
	cout << lottoNum4 << endl;
	cout << lottoNum5 << endl;

	return 0;
}