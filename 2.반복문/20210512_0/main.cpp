#include <iostream>

using namespace std;

int main()
{
	//�ݺ���
	//1. for��
	/*
	for (int i = 0; i < 5; i++)
	{
		cout << "����!" << endl;
	}*/

	/*
	int num;

	cout << "�ֿ��̰� ���ϴ� �������� ���� : ";
	cin >> num;

	for (int i = 1; i < 10; i++)
	{
		cout << num << " X " << i << " = " << num * i << endl;
	}
	*/

	/*
	//for���ȿ� for���� ������ 2�������̴� (�ð����⵵�� n����)
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
	//   **		������ �����ϰ�
	//  ***		����   �����Ѵ�
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