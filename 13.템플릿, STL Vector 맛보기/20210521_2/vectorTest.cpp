#include "vectorTest.h"

vectorTest::vectorTest()
{
	//STL 컨테이너 중 벡터는 배열기반의 컨테이너임

	//벡터 컨테이너에 값을 넣을땐 push_back()
	_vNum.push_back(1);
	_vNum.push_back(2);
	for (int i = 0; i < 5; i++)
	{
		_vNum.push_back(i * 10);
	}

	//벡터 컨테이너에서 값을 순차적으로 지울땐 pop_back()
	_vNum.pop_back();
	_vNum.pop_back();

	//벡터에 값을 중간에 삽입하고싶을땐 insert()

	_vNum.insert(_vNum.begin() + 3, 777);
	_vNum.insert(_vNum.end() - 2, 8);

	//벡터 컨테이너 중간의 값을 지울땐 erase()
	_vNum.erase(_vNum.begin() + 3);

	//벡터 안을 걍 싹 날리는 함수
	//_vNum.clear();

	//벡터의 사이즈를 알려주는 함수
	//size()
	cout << "현재 컨테이너 안에 자료갯수 : " << _vNum.size() << endl;

	for (int i = 0; i < _vNum.size(); i++)
	{
		cout << _vNum[i] << endl;
	}


}


vectorTest::~vectorTest()
{
}
