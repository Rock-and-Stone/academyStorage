#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//형변환
	//자료형을 말그대로 변환하는 것.

	float speed = 3.3f;

	//9.9f가 나와야하지만 int 변수이기 때문에 소수점 단위는 잘려나간다
	//묵시적 형변환이라고 함
	int distance = speed * 3;

	//명시적 형변환
	cout << "속도 : " << (int)speed << endl;
	//cout << "이동한 거리 : " << distance << endl;

	static_cast<int>(speed);
	
	//C++ 형변환 문법
	//static_cast - 보통의 흔한 형변환과 같은 역할을 한다
	//              C스타일의 형변환은 안정성이 떨어지는데
	//              얘는 검사해서 안전하면 형변환을 한다

	//reinterpret_cast - 써본적은 없고, 쓸 일도 잘 없긴한데
	//                   강제형변환에 가깝다

	//const_cast - 상수화를 무효처리 한다
	//             팀장님이 싫어합니다 쓰지맙시다

	//dynamic_cast - 상속관계에서의 형변환을
	//               안정적으로 해준다
	
	int num = 35;

	cout << (char)num << endl;


	return 0;
}