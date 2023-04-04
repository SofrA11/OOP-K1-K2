#pragma once
#include "Aktivnost.h"

class Umetnost : public Aktivnost {
private:
	int broj_polaznika;
	double izracunaj_vrednost() {
		return (broj_polaznika * 10);
	}
	void check_values() {
		if (broj_polaznika < 0)
			throw exception("Nedovoljno polaznika");
	}
public:
	Umetnost() : Aktivnost() {
		broj_polaznika = 0;
		vrednost = izracunaj_vrednost();
	}
	Umetnost(int bp) : Aktivnost() {
		broj_polaznika = bp;
		check_values();
		vrednost = izracunaj_vrednost();
	}
	~Umetnost () {}
	void prikaz(ostream& out) {
		out << "Umetnost; broj_polaznika = " << broj_polaznika;
	}
	void ucitaj(istream& in) {
		in >> broj_polaznika;
		check_values();
		vrednost = izracunaj_vrednost();
	}
};

