#include"Skup.h"
#include"Studnet.h"
#include<iostream>
#include<fstream>
using namespace std;
void main()
{
	try {
	Skup<Student> Sk(3);
	Skup<Student> Sk1(2);
	Skup<Student> Sk2;
	ifstream ul("C:\\Users\\PC\\Desktop\\input.txt");
		ul >> Sk;
		ul >> Sk1;
		cout << Sk;
		cout << Sk1;
	Sk2 = Sk.presek(Sk1);
	cout << "Sk2 /++++++++++++++"<<endl;
	cout << Sk2;

	Student S;
	cin >> S;

	Sk2.brisi(S);
	cout << "++++++++++++++"<<endl;
	cout << Sk2;
	}
		catch (exception ec)
	{
			cerr << ec.what();
	}
	catch (...)
	{
		cerr << "OP";
	}
	//cin >> Sk;
	
	
	
	/*
	Skup<int> Sk(3);
	Skup<int> Sk1(5);
	Skup<int> Sk2;
	for (int i = 0;i < 3;i++)
	{
		Sk.dodaj(i+1);
		
	}
	for (int i = 0;i < 5;i++)
		Sk1.dodaj(i + 1);
	Sk2 = Sk.presek(Sk1);

	Sk2.brisi(1);
	//cin >> Sk;
	cout << Sk2 << endl;
	*/
}