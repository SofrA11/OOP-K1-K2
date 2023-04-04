#pragma once
#include "Predmet.h"
#include "ZlatnaPoluga.h"
#include "DragiKamen.h"
#include "Jabuka.h"
#include <iostream>
using namespace std;
class Ranac
{
private:
	int _brojPredmeta;
	Predmet** _predmeti;
	int _iskorisceni;

public:
	Ranac();
	Ranac(int brojPredmeta);
	~Ranac();

	inline void DodajPredmet(float masa, char tipPredmeta)
	{
		if (_iskorisceni == _brojPredmeta)
			cout << "Sva mesta za predmete su iskoriscena, ne moze se dodati jos" << endl;
		else
		{
			float kCistoce, kk, ks;
			switch (tipPredmeta)
			{
			case 'z':
				float stepen_cistoce;
				do {
					cout << "Unesite stepen cistoce: " << endl;
					cin >> stepen_cistoce;
				} while (stepen_cistoce < 1 || stepen_cistoce>24);

				_predmeti[_iskorisceni] = new ZlatnaPoluga(masa, stepen_cistoce);
				_iskorisceni++;
				break;
			case 'd':
				do {
					cout << "Unesite koeficijent cistoce dragog kamena: " << endl;
					cin >> kCistoce;
				} while (kCistoce < 0.00 or kCistoce > 1.00);

				cout << "Unesite boju dragog kamena: " << endl;
				char boja[25];
				cin >> boja;

				cout << "Unesite rez dragog kamena: " << endl;
				int rez;
				cin >> rez;

				_predmeti[_iskorisceni] = new DragiKamen(kCistoce, boja, rez, masa);
				_iskorisceni++;
				break;
			case 'j':
				do {
					cout << "Unesite koeficijent slatkoce jabuke: " << endl;
					cin >> ks;
					cout << "Unesite koeficijent kiselosti jabuke: " << endl;
					cin >> kk;
				} while (ks < 0.00 || ks > 1.00 || kk < 0.00 || kk > 1.00);

				cout << "Unesite boju jabuke: " << endl;
				char t[25];
				cin >> t;
				_predmeti[_iskorisceni] = new Jabuka(ks, kk, t, masa);
				_iskorisceni++;
				break;

			default:
				cout << "Ne valja tip predmeta";
			}
		}
	}

	inline float ProsecnaVrednost()
	{
		float sum = 0;
		for (int i = 0; i < _iskorisceni; i++)
			sum += _predmeti[i]->GetVrednost();

		return sum / _iskorisceni;
	}

	inline float MaxVrednost()
	{
		float max = 0;
		for(int i = 0; i < _iskorisceni; i++)
		{
			if (_predmeti[i]->GetVrednost() > max)
				max = _predmeti[i]->GetVrednost();
		}

		return max;
	}
	inline float NajvrednijiPoMasi()
	{
		float max = 0;
		int j=0;
		for (int i = 0; i < _iskorisceni; i++)
		{
			if (_predmeti[i]->GetVrednost() * _predmeti[i]->GetMasa() > max)
			{
				max = _predmeti[i]->GetVrednost() * _predmeti[i]->GetMasa();
				j = i;
			}
		}

		return j;

	}

	friend ostream& operator<<(ostream& os, const Ranac& r);
};