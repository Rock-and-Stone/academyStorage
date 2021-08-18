#include <iostream>

using namespace std;

//함수의 전방선언
//전방선언 하면 컴파일러한테 우선 실행하라고 하는 것과 같다
//물론 함수를 따로 만들어둬야함 
void output();

void main()
{
	//뭐야 그거 몰라 무서웡
	output();

}

void output()
{
	cout << "답정너 아닙니다 여러분" << endl;
}