#include "vectorTest.h"

vectorTest::vectorTest()
{
	//STL �����̳� �� ���ʹ� �迭����� �����̳���

	//���� �����̳ʿ� ���� ������ push_back()
	_vNum.push_back(1);
	_vNum.push_back(2);
	for (int i = 0; i < 5; i++)
	{
		_vNum.push_back(i * 10);
	}

	//���� �����̳ʿ��� ���� ���������� ���ﶩ pop_back()
	_vNum.pop_back();
	_vNum.pop_back();

	//���Ϳ� ���� �߰��� �����ϰ������ insert()

	_vNum.insert(_vNum.begin() + 3, 777);
	_vNum.insert(_vNum.end() - 2, 8);

	//���� �����̳� �߰��� ���� ���ﶩ erase()
	_vNum.erase(_vNum.begin() + 3);

	//���� ���� �� �� ������ �Լ�
	//_vNum.clear();

	//������ ����� �˷��ִ� �Լ�
	//size()
	cout << "���� �����̳� �ȿ� �ڷ᰹�� : " << _vNum.size() << endl;

	for (int i = 0; i < _vNum.size(); i++)
	{
		cout << _vNum[i] << endl;
	}


}


vectorTest::~vectorTest()
{
}
