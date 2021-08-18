#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	//int 배열을 45개 선언
	int number[45];
	int dest, sour, temp;

	//배열 초기화
	for (int i = 0; i < 45; i++)
	{
		number[i] = i + 1;
	}

	//셔플을 할때에 for문의 갯수는 섞는 횟수
	for (int i = 0; i < 333; i++)
	{
		dest = rand() % 45; //배열의 인덱스 범위만큼 하자
		sour = rand() % 45;	

		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	//출력 
	for (int i = 0; i < 6; i++)
	{
		cout << number[i] << endl;
	}


	return 0;
}