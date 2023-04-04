#include "Predmet.h"
#include <string.h>
#pragma once
class Jabuka : public Predmet
{
private:
	float _ks;
	float _kk;
	char _boja[25];

public:
	Jabuka(float ks, float kk, char boja[25], float masa) : Predmet(masa)
	{
		_ks = ks;
		_kk = kk;
		strcpy(_boja, boja);
		//_boja = boja;

		Jabuka::IzracunajVrednost();
	}

	inline virtual float IzracunajVrednost()
	{
		if (_kk < 0.5 or _ks < 0.5)
			_vrednost = 0;
		else
			_vrednost = _kk * _ks * _masa * 1000.00;

		return _vrednost;
	}
	inline virtual void print()
	{
		cout << "Jabuka koeficijenta slatkosti " << _ks << ", koeficijenta kiselosti " << _kk << ", boje:" << _boja << ", mase:" << Predmet::GetMasa()<<"kg"<< ", vrednosti " << Predmet::GetVrednost() << "$" << endl;
	}
};

