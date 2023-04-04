#pragma once
#include "Student.h"

class StudentKolok : public Student {
private:
	int i_kolok;
	int ii_kolok;
public:
	StudentKolok(int bi, int pl) : Student(bi, pl) {
		i_kolok = ii_kolok = 0;
	}
	StudentKolok(int bi, int pl, int pu, int i_kolok, int ii_kolok) : Student(bi, pl, pu) {
		if (i_kolok > 20)
			this->i_kolok = 20;
		else if (i_kolok < 0)
			this->i_kolok = 0;
		else
			this->i_kolok = i_kolok;
		if (ii_kolok > 20)
			this->ii_kolok = 20;
		else if (ii_kolok < 0)
			this->ii_kolok = 0;
		else
			this->ii_kolok = i_kolok;
	}
	~StudentKolok() {}
	void set_i(int i) {
		i_kolok += i;
	}
	void set_ii(int i) {
		ii_kolok += i;
	}

	int ukupno_bodova() {
		return i_kolok + ii_kolok + poeni_usm + poeni_lab;
	}
	bool je_polozio() {
		return ((float)(i_kolok + ii_kolok + poeni_usm) / 80 > 0.5 && 
			(float)poeni_usm / 40 > 0.5 && (float)(i_kolok) / 20 > 0.25 && (float)ii_kolok / 20 > 0.25
			&& (float)(i_kolok + ii_kolok) / 40 > 0.5);
	}
	void prikaz(ostream& out) {
		Student::prikaz(out);
		out << (i_kolok + ii_kolok) << "(I = " << i_kolok << " II = " << ii_kolok << ")";
	}
};

