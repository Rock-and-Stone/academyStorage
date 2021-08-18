#include <iostream>

using namespace std;

int main()
{
	//반복문
	//1. for문
	/*
	for (int i = 0; i < 5; i++)
	{
		cout << "야후!" << endl;
	}*/

	/*
	int num;

	cout << "주연이가 원하는 구구단의 단은 : ";
	cin >> num;

	for (int i = 1; i < 10; i++)
	{
		cout << num << " X " << i << " = " << num * i << endl;
	}
	*/

	/*
	//for문안에 for문이 있으면 2중포문이다 (시간복잡도는 n제곱)
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " X " << j << " = " << i * j << endl;
		}
	}*/

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	//*****
	//****
	//***
	//**
	//*

	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < i; k++)
		{
			cout << " ";
		}
		for (int j = 5; j > i; j--)
		{
			cout << "*";
		}

		

		cout << endl;
	}


	//*
	//**
	//***
	//****
	//*****

	//*****
	//****
	//***
	//**
	//*

	//*****
	// ****
	//  ***
	//   **
	//    *

	//    *
	//   **		공백이 감소하고
	//  ***		별이   증가한다
	// ****
	//*****
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j > i; j--)
		{
			cout << " ";
		}
		for (int k = 0; k < i + 1; k++)
		{
			cout << "*";
		}
		
		cout << endl;
	}


	return 0;
}