#include <iostream>
#include <Windows.h>

using namespace std;

static int num = 0;

DWORD WINAPI threadFunc1(LPVOID lParam)
{

	//�ε�ó��
	while (true)
	{
		num++;
		cout << "�ѹ� : " << num << endl;
		cout << "������ 1��! 1��! 1��!" << endl;
	}
}


DWORD WINAPI threadFunc2(LPVOID lParam)
{
	while (true)
	{
		num++;
		cout << "�ѹ� : " << num << endl;
		cout << "������ 2��! 2��! 2��!" << endl;
	}
}

int main()
{
	HANDLE thread1 = NULL;
	HANDLE thread2 = NULL;

	DWORD dwThread1 = 0;
	DWORD dwThread2 = 0;

	thread1 = CreateThread(NULL, 0, threadFunc1, NULL, 0, &dwThread1);
	thread2 = CreateThread(NULL, 0, threadFunc2, NULL, 0, &dwThread2);

	//1. �������� ���ȼӼ� ����
	//�ڽ� �����찡 �ִ� ��쿡 �θ������쿡�� ������ ���μ��� �ڵ���
	//��ӵǾ����ִ� ��쿡�� ����Ѵ���

	//2. �������� ���ø޸� ũ�� ����
	//0���� �θ� ���ξ����� ���� ũ��� ����
	//���ÿ����÷� ���� ������ ���� ������ ���������ϰ� ��.

	//3. ����� ������ �Լ� �̸�

	//4. ������ ���� �Ѱ��� ������ ���� ������ �η� ����

	//5. 0�� ������ �����带 ��Ī�Ѵ�
	//CREATE_SUSPENDED ��ɾ ����ϸ� �����尡 ���� ������� ����
	//�ٽ� �����ؾ��ϴ� ��쿡�� ResumeThread() �Լ��� �����ؾ���

	//6. ������ ���� ID��ȣ
	//������7 �������� NULL�� ����ص� �ƴµ� ���ĺ��ʹ�
	//NULL�� ���� ������ ������ �Ұ��������� �׷��� ȣȯ�� + ������ �������� DWORD�� ����.

	Sleep(1000);

	return 0;
}