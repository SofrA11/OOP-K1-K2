#pragma once
#include "Student.h"

class StudentIspit : public Student {
private:
	int poeni_pis;
public:
	StudentIspit(int bi, int pl) : Student(bi, pl) { poeni_pis = 0; }
	StudentIspit(int bi, int pl, int pu, int pp) : Student(bi, pl, pu) { 
		if (pp > 40)
			poeni_pis = 40;
		else if (pp < 0)
			poeni_pis = 0;
		else
			poeni_pis = pp;
	}
	~StudentIspit() {}

	void set_poeni_pis(int novi) {
		poeni_pis += novi;
	}

	int ukupno_bodova() {
		return poeni_lab + poeni_pis + poeni_usm;
	}
	bool je_polozio() {
		return ((float)poeni_pis / 40 > 0.5 && (float)poeni_usm / 40 > 0.5 && (float)(poeni_pis + poeni_usm) / 80 > 0.5);
	}
	void prikaz(ostream& out) {
		Student::prikaz(out);
		out << poeni_pis;
	}
};

