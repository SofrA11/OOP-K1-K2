#pragma once
#include "Student.h"
#include "StudentIspit.h"
#include "StudentKolok.h"

class Evidencija {
private:
	int br_stud;
	int tren;
	Student** radovi;
public:
	Evidencija() {
		br_stud = tren = 0;
		radovi = 0;
	}
	Evidencija(int br) {
		br_stud = br;
		tren = 0;
		radovi = new Student * [br_stud];
	}
	~Evidencija() {
		if (radovi != 0) {
			for (int i = 0; i < tren; i++)
				delete radovi[i];
			delete[] radovi;
		}
	}

	void prikaz(ostream& out) {
		for (int i = 0; i < tren; i++) {
			radovi[i]->prikaz(out);
			out << endl;
		}
	}

	void dodaj(Student* s) {
		if (tren + 1 <= br_stud)
			radovi[tren++] = s;
	}
	void ukloni(int ind) {
		int i = 0;
		while (i < tren && radovi[i]->index() != ind)
			i += 1;
		delete radovi[i];
		for (int j = i; j < tren - 1; j++)
			radovi[j] = radovi[j + 1];
		tren -= 1;
	}
	Student* max_usm() {
		int ind = 0;
		for (int i = 1; i < tren; i++)
			if (radovi[ind]->usm() < radovi[i]->usm())
				i = ind;
		return radovi[ind];
	}
	Student* max_ceo() {
		int ind = 0;
		for (int i = 1; i < tren; i++)
			if (radovi[ind]->ukupno_bodova() < radovi[i]->ukupno_bodova())
				ind = i;
		return radovi[ind];
	}
	int polozili() {
		int s = 0;
		for (int i = 0; i < tren; i++)
			if (radovi[i]->je_polozio())
				s += 1;
		return s;
	}
	int pros_poen() {
		int s = 0;
		for (int i = 0; i < tren; i++)
			if (radovi[i]->je_polozio())
				s += radovi[i]->ukupno_bodova();
		return (float)s / tren;
	}
	void update_usm(int ind, int np) {
		int i = 0;
		while (i < tren && radovi[i]->index() != ind)
			i += 1;
		if (radovi[i]->index() != tren)
			radovi[i]->set_poeni_usm(np);
	}
	void update_pis(int ind, int np, int klk = 0) {
		for (int i = 0; i < tren; i++) {
			if (radovi[i]->index() == ind && klk == 0)
				((StudentIspit*)radovi[i])->set_poeni_pis(np);
			else if (radovi[i]->index() == ind && klk == 1)
				((StudentKolok*)radovi[i])->set_i(np);
			else if (radovi[i]->index() == ind && klk == 2)
				((StudentKolok*)radovi[i])->set_ii(np);
		}
	}
};

