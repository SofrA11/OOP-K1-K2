#include "Cvet.h"
#include "Lala.h"
#include "Ruza.h"
#include "Buket.h"
#include <iostream>
#include <fstream>
using namespace std;

float Ruza::_cenaBeleRuze = 1000;
float Lala::_cenaPoGramu = 1;

void main()
{

	Buket* buket = new Buket(15);

	ifstream ulaz("ulaz.txt");

	if (ulaz.good())
	{
		int r, g, b;
		float masa;
		//ruze
		for (int i = 0; i < 6; i++)
		{
			ulaz >> r;
			ulaz >> g;
			ulaz >> b;

			buket->DodajRuzu(r, g, b);
		}
		//lale
		for (int i = 0; i < 9; i++)
		{
			ulaz >> masa;
			buket->DodajLalu(masa);
		}
	}
	else
		cout << "fajl nije pronadjen";

	ulaz.close();

	ofstream izlaz("izlaz1.txt");

	izlaz << buket[0];
	izlaz.close();

	delete buket;
}