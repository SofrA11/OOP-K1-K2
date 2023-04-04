#include<iostream>
#include"Azdaja.h"
using namespace std;
void main()
{

	//Azdaja* A=new Azdaja();
	Azdaja B[2];
	char c;
	int i = 0;
/*	do {
		do {
			cout << "Unesi "<<i+1<< ". deo tela: ";
			cin >> c;
		} while (c != 'g' && c != 'r' && c != 'k' && c != 'x');
		if(c!='x')
		A->DodajDeoTela(c);
		i++;
		system("cls");
	} while (c != 'x');
	 i = 0;
*/
	for (i = 0;i < 2;i++)
	{
		do {
			cout << "Unesi " << i + 1 << ". deo tela: ";
			cin >> c;
		} while (c != 'g' && c != 'r' && c != 'k' && c != 'x');
		if (c != 'x')
			B->DodajDeoTela(c);
		system("cls");
	}
	//A->PrikaziSpisak(cout);
	//cout << "----------------------";
	B->PrikaziSpisak(cout);
}