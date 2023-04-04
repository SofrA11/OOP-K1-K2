#pragma once
#include"Takmicar.h";
#include"Lista.h";
#include<iostream>;
using namespace std;
void main()
{
	Lista<Takmicar> A(5);
	
	for (int i = 0;i < 4;i++)
	{
		try {
			Takmicar T(i, 1 + rand() % 25, 1 + rand() % 5);
			A.dodaj(T);
		}
		catch(exception ec)
		{
			cerr << ec.what() << endl;
		}
		catch(...)
		{ }
	}
	
	try {
		Takmicar T(1, 1, 1);
		A.dodaj(T);
	}
	catch (exception ec)
	{
		cerr << ec.what() << endl;
	}
	catch (...)
	{
	}
//A.dodaj(1 + rand() % 20);
	cout << A;
	Lista<Takmicar> B(3);
	for (int i = 0;i < 3;i++)
	{
		Takmicar T(i, 1 + rand() % 25, 1 + rand() % 5);
		B.dodaj(T);
	}
	cout << B;
		//B.dodaj(1 + rand() % 20);
	Lista<Takmicar> C;
	C = A.upari(B);
	cout << C;
	C.brisi(T);
	cout << C;


}