#include "Buket.h"
#include "Cvet.h"
#include <iostream>
using namespace std;

Buket::Buket()
{
	_cvetovi = new Cvet * [0];
	_brojCvetova = 0;
	_used = 0;
}

Buket::Buket(int brojCvetova)
{
	_brojCvetova = brojCvetova;
	_cvetovi = new Cvet * [brojCvetova];
	_used = 0;
}

Buket::~Buket()
{
	delete[] _cvetovi;
}

//void Buket::DodajCvet(char tipCveta, int r = 0, int g = 0, int b = 0, float masa = 0)
//{
//	if (_used == _brojCvetova)
//		cout << "Broj mesta u buketu popunjen";
//	else
//	{
//		/*int r, g, b;
//		float masa;*/
//		if (tipCveta == 'r' or tipCveta == 'R')
//		{
//			//cout << "Unesite boje ruze (R, G, B): " << endl;
//			//cin >> r;
//			//cin >> g;
//			//cin >> b;
//
//			_cvetovi[_used] = new Ruza(r, g, b);
//			_used++;
//		}
//		else if (tipCveta == 'l' or tipCveta == 'L')
//		{
//			//cout << "Unesite masu lale: ";
//			//cin >> masa;
//
//			_cvetovi[_used] = new Lala(masa);
//			_used++;
//		}
//	}
//}

void Buket::DodajLalu(float masa)
{
	_cvetovi[_used] = new Lala(masa);
	_used++;
}
void Buket::DodajRuzu(int r, int g, int b)
{
	_cvetovi[_used] = new Ruza(r, g, b);
	_used++;
}

ostream& operator<<(ostream& os, const Buket& b)
{
	for (int i = 0; i < b._used; i++)
	{
		if (b._cvetovi[i]->GetIme() == 'r')
			os << "Ruza je cene: " << b._cvetovi[i]->GetCena() << endl;
		else if (b._cvetovi[i]->GetIme() == 'l')
			os << "Lala je cene: " << b._cvetovi[i]->GetCena() << endl;
	}

	return os;
}