#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//����ȯ
	//�ڷ����� ���״�� ��ȯ�ϴ� ��.

	float speed = 3.3f;

	//9.9f�� ���;������� int �����̱� ������ �Ҽ��� ������ �߷�������
	//������ ����ȯ�̶�� ��
	int distance = speed * 3;

	//����� ����ȯ
	cout << "�ӵ� : " << (int)speed << endl;
	//cout << "�̵��� �Ÿ� : " << distance << endl;

	static_cast<int>(speed);
	
	//C++ ����ȯ ����
	//static_cast - ������ ���� ����ȯ�� ���� ������ �Ѵ�
	//              C��Ÿ���� ����ȯ�� �������� �������µ�
	//              ��� �˻��ؼ� �����ϸ� ����ȯ�� �Ѵ�

	//reinterpret_cast - �ẻ���� ����, �� �ϵ� �� �����ѵ�
	//                   ��������ȯ�� ������

	//const_cast - ���ȭ�� ��ȿó�� �Ѵ�
	//             ������� �Ⱦ��մϴ� �������ô�

	//dynamic_cast - ��Ӱ��迡���� ����ȯ��
	//               ���������� ���ش�
	
	int num = 35;

	cout << (char)num << endl;


	return 0;
}