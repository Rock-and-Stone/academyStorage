#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//배열
	//변수나 자료형들의 연속적인 나열
	//순차적으로 공간들이 이루어져있다(포인터방식)

	//배열을 5개 선언했다
	//int number[5];
	//
	////포문으로 한 번에 초기화 할 수 있다
	//for (int i = 0; i < 5; i++)
	//{
	//	//number[2] = 2 + 1
	//	number[i] = i + 1;
	//}

	//800번지 예를들어서 입니다
	//800 + sizeof(int) * 0	== 800
	//800 + sizeof(int) * 1	== 804
	//800 + sizeof(int) * 2	== 808
	//800 + sizeof(int) * 3	== 812
	//800 + sizeof(int) * 4 == 816

	//number[0] = 0;
	//number[1] = 12;
	//number[2] = 777;
	//number[3] = 8;
	//number[4] = 144;

	//2중 배열
	//행과 열로 되어있음 
	/*
	int number[3][3];
	
	number[0][0]; number[0][1]; number[0][2];
	number[1][0]; number[1][1]; number[1][2];
	number[2][0]; number[2][1]; number[2][2];
	*/

	




	return 0;
}