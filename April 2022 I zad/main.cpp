#include "Evidencija.h"

int main() {
	srand(1);
	Evidencija* e1 = new Evidencija(6);
	
	for (int i = 0; i < 3; i++) {
		Student* s1 = new StudentIspit(17500 + rand() % 300, rand() % 21, rand() % 41, rand() % 41);
		e1->dodaj(s1);
		s1 = new StudentKolok(17500 + rand() % 300, rand() % 21, rand() % 41, rand() % 21, rand() % 21);
		e1->dodaj(s1);
	}
	e1->prikaz(cout);
	cout << "-------------------------------" << endl;
	e1->ukloni(17600);
	e1->prikaz(cout);
	cout << "-------------------------------" << endl;
	e1->update_pis(17762, 2, 2);
	e1->update_pis(17681, 2, 0);
	e1->prikaz(cout);
	cout << "-------------------------------" << endl;
	Student* s = e1->max_ceo();
	s->prikaz(cout);
	cout << endl << "-------------------------------" << endl;
	cout << "Ispit je polozilo " << e1->polozili() << ", a pros br poena " << e1->pros_poen();
}