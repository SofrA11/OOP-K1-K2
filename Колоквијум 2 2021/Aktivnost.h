#pragma once
#include <string.h>
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

class Aktivnost {
protected:
	double vrednost;
	virtual double izracunaj_vrednost() = 0;
	virtual void check_values() = 0;
public:
	Aktivnost() {
		vrednost = 0;
	}
	virtual ~Aktivnost() {}

	double get_vrednost() {
		return vrednost;
	}

	virtual void prikaz(ostream& out) = 0;
	virtual void ucitaj(istream& in) = 0;
};

