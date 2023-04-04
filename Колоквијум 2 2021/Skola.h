#pragma once
#include "Aktivnost.h"

class Skola {
private:
	Aktivnost** aktivnosti;
	int kapac;
	int tren;
public:
	Skola() {
		aktivnosti = 0;
		kapac = tren = 0;
	}
	Skola(int c) {
		tren = 0;
		kapac = c;
		aktivnosti = new Aktivnost * [kapac];
		for (int i = 0; i < kapac; i++)
			aktivnosti[i] = 0;
	}
	~Skola() {
		if (aktivnosti != 0) {
			for (int i = 0; i < kapac; i++)
				delete aktivnosti[i];
			delete[] aktivnosti;
		}
		aktivnosti = 0;
	}
	void dodaj_aktivnost(Aktivnost* nova) {
		if (tren + 1 > kapac) {
			prikaz(cerr);
			throw exception("Nema dovoljno sala");
		}
		int k = tren, i = 0;
		bool found = false;
		while (!found and i < tren) {
			if (nova->get_vrednost() > aktivnosti[i]->get_vrednost()) {
				found = true;
				k = i;
			}
			i += 1;
		}
		for (int i = tren; i > k; i--)
			aktivnosti[i] = aktivnosti[i - 1];
		aktivnosti[k] = nova;
		tren += 1;
	}
	void ukloni_aktivnost(int br_sale) {
		if (0 > br_sale or br_sale > tren) {
			prikaz(cerr);
			throw exception("Nepostojeci broj sale");
		}
		delete aktivnosti[br_sale];
		for (int i = br_sale; i < tren - 1; i++)
			aktivnosti[i] = aktivnosti[i + 1];
		tren -= 1;
		aktivnosti[tren] = 0;
	}
	void ucitaj(istream& in) {
		for (int i = 0; i < kapac; i++) {
			aktivnosti[i]->ucitaj(in);
		}
	}
	void prikaz(ostream& out) {
		for (int i = 0; i < tren; i++) {
			aktivnosti[i]->prikaz(out);
			out << endl;
		}
		out << "Najvrednija aktivnost: ";
		najvrednija()->prikaz(out);
		out << endl;
		out << "Najmanje vredna aktivnost: ";
		najmanje_vredna()->prikaz(out);
		out << endl;
		out << "Prosecna vrednost aktivnosti: " << prosecna_vrednost();
	}
	double prosecna_vrednost() {
		double s = 0;
		for (int i = 0; i < tren; i++)
			s += aktivnosti[i]->get_vrednost();
		return static_cast<double>(s) / static_cast<double>(tren);
	}
	Aktivnost* najvrednija() {
		return aktivnosti[0];
	}
	Aktivnost* najmanje_vredna() {
		return aktivnosti[tren - 1];
	}
};

