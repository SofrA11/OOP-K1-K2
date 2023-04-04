#pragma once
#include "Aktivnost.h"

class Sport : public Aktivnost {
private:
	int broj_igraca;
	int broj_rezervi;
	char* obuca;
	double budzet;
	double koef;
	double izracunaj_vrednost() {
		return ((broj_igraca + broj_rezervi) * budzet * koef);
	}
	void check_values() {
		if (broj_igraca < 1 or broj_igraca > 20)
			throw exception("Previse igraca na terenu");
		if (broj_rezervi < 0 or broj_rezervi > 10)
			throw exception("Previse rezervnih igraca");
		if (koef < 0 or koef > 1)
			throw exception("Nevazeca vrednost koeficijenta");
		if (budzet < 0 or budzet > 50000)
			throw exception("Budzet prevazilazi granice dozvoljenog");
	}
public:
	Sport() : Aktivnost() {
		broj_igraca = broj_rezervi = 0;
		budzet = koef = 0;
		obuca = 0;
		vrednost = izracunaj_vrednost();
	}
	Sport(int bi, int br, char* o, double bu, double k) : Aktivnost() {
		broj_igraca = bi;
		broj_rezervi = br;
		budzet = bu;
		obuca = new char[strlen(o) + 1];
		strcpy(obuca, o);
		check_values();
		vrednost = izracunaj_vrednost();
	}
	~Sport() {
		if (obuca != 0)
			delete[] obuca;
		obuca = 0;
	}
	void prikaz(ostream& out) {
		out << "Sportska aktivnost; broj_igraca = " << broj_igraca << ", broj_rezervi = " << broj_rezervi << ", budzet = " << budzet << ", koef_pop = " << koef;
		out << ", obuca = " << obuca;
	}
	virtual void ucitaj(istream& in) {
		char pom[20];
		in >> broj_igraca >> broj_rezervi >> pom >> budzet >> koef;
		delete[] obuca;
		obuca = new char[strlen(pom) + 1];
		strcpy(obuca, pom);
		check_values();
		vrednost = izracunaj_vrednost();
	}

};

