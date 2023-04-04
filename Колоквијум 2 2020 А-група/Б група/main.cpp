#pragma once
#include<exception>
#include<iostream>
#include"Niz.h"
#include"SefUoblikuKocke.h"
#include"Zlato.h"
#include<fstream>
using namespace std;
int main()
{
	try {
		Niz<double> D;
		cin >> D;
		cout << D;
		D.brisi(3);
		cout << D;
		/*
		Niz<ZlatnaPoluga> A;
		Niz<Sef> B;
		ifstream a("A.txt"), b("B.txt");
		a >> A;
		cout << A;
		A.brisi(5);
		//A.brisi(-2);
		ofstream ao("izlazA.txt"), bo("izlazB.txt");
		ao << A;
		b >> B;
		cout << B;
		B.brisi(5);
		//B.brisi(7);
		bo << B;
		*/
	}
	catch (exception ec)
	{
		cerr << ec.what();
	}
	catch (...)
	{
		cerr << "...";
	}
	return 0;
}
