#pragma once
#include <iostream>
using namespace std;

class Student {
protected:
	int broj_indeksa;
	int poeni_lab;
	int poeni_usm;
public:
	Student(int bi, int pl) {
		broj_indeksa = bi; 
		if (poeni_lab > 20)
			poeni_lab = 20;
		else if (poeni_lab < 0)
			poeni_lab = 0;
		else
			poeni_lab = pl;
		poeni_usm = 0;
	}
	Student(int bri, int pl, int pu) {
		broj_indeksa = bri;
		if (pl > 20)
			poeni_lab = 20;
		else if (pl < 0)
			poeni_lab = 0;
		else
			poeni_lab = pl;
		if (pu > 40)
			poeni_usm = 40;
		else if (pu < 0)
			poeni_usm = 0;
		else
			poeni_usm = pu;
	}
	virtual ~Student() {}

	void set_poeni_usm(int poeni) {
		poeni_usm = poeni;
	}

	int index() {
		return broj_indeksa;
	}

	int usm() {
		return poeni_usm;
	}

	virtual int ukupno_bodova() = 0;
	virtual bool je_polozio() = 0;

	virtual void prikaz(ostream& out) {
		out << broj_indeksa << "poeni lab = " << poeni_lab << "; poeni usm = " << poeni_usm << "; poeni pism = ";
	}
};

