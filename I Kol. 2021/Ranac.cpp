#include "Ranac.h"
#include "Predmet.h"
#include <iostream>;
using namespace std;

Ranac::Ranac()
{
	_brojPredmeta = 0;
	_predmeti = new Predmet * [0];
	_iskorisceni = 0;
}

Ranac::Ranac(int brojPredmeta)
{
	_brojPredmeta = brojPredmeta;
	_predmeti = new Predmet * [brojPredmeta];
	_iskorisceni = 0;
}

Ranac::~Ranac()
{
	delete[] _predmeti;
}

ostream& operator<<(ostream& os, const Ranac& r)
{
	os << "Broj predmeta u rancu: " << r._brojPredmeta << endl <<
		"Predmeti: " << endl;
	for (int i = 0; i < r._iskorisceni; i++)
	{
		r._predmeti[i]->print();
	}

	os << endl;
	return os;
}