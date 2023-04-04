#pragma once
#include "Predmet.h"
#include <ostream>
using namespace std;

class ZlatnaPoluga : public Predmet
{
private:
	float _stepenCistoce;

public:
	ZlatnaPoluga(float masa, float stepenCistoce) : Predmet(masa)
	{
		_stepenCistoce = stepenCistoce;
		ZlatnaPoluga::IzracunajVrednost();
	}

	inline virtual float IzracunajVrednost()
	{
		_vrednost = _masa * _stepenCistoce / 24;
		return _vrednost;
	};

	virtual ostream& Prikazi(ostream& os)
	{
		os << _masa;

		return os;
	};
	inline virtual void print()
	{
		cout <<"Zlatna poluga stepna cistoce " << _stepenCistoce <<", mase:" << Predmet::GetMasa() <<"kg" << ", vrednosti" << Predmet::GetVrednost() << "$" << endl;
	};
};

