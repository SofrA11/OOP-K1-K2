#pragma once
#include "Predmet.h"
#include <string.h>
class DragiKamen : public Predmet
{
private:
	float _kCistoce;
	char _boja[25];
	int _rez;

public:
	DragiKamen(float kCistoce, char boja[25], int rez, float masa) : Predmet(masa)
	{
		_kCistoce = kCistoce;
		strcpy(_boja, boja);
		//_boja = boja;
		_rez = rez;
		DragiKamen::IzracunajVrednost();
	}

	inline virtual float IzracunajVrednost()
	{
		_vrednost = _masa * _kCistoce;

		return _vrednost;
	}

	inline virtual void print()
	{
		cout << "Dragi kamen koeficijenta cisoce " << _kCistoce << ", boje:" << _boja << ", broj rezova " << _rez << ", mase:" << Predmet::GetMasa()<<"kg" << ", vrednosti" << Predmet::GetVrednost()<<"$"<< endl;
	}
};