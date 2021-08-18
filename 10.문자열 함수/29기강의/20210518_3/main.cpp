#include "mainGame.h" //클래스 등 임의로 만든건 "" <--

int main()
{
	//정적 할당
	//런타임 도중 삭제 불가 (컴파일러 이전단계에서 메모리 잡고 들어옴)
	//스택 영역에 메모리 잡힘
	//mainGame mg;
	//mainGame mg1;
	//mainGame mg2;

	//동적 할당
	//컴파일러 끝나고 메모리를 힙영역에서 빌려옴
	//런타임 도중 삭제 쌉가능
	//힙영역에 메모리 잡힘
	mainGame* mg = new mainGame;

	delete mg;	//지우는게 아니고 빌려온거 반환





	return 0;
}