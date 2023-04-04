#include "Kolekcija.h"
#include "Banana.h"
int main() {
	srand(time(0));
	Kolekcija<double, 5>k1;
	Kolekcija<Banana, 5>k2;
	try {
		k2.dodaj(Banana(-1));
		for (int i = 1; i < 5; i++)
			k2.dodaj(Banana(i * 20));
		cout << k2 << "Prosek = " << k2.prosek() << endl;
		k2.izbaci(10);
		cout << k2 << endl;
	}
	catch (exception ec) {
		cerr << ec.what() << endl;
	}
	catch (...) {
		cerr << "Neocekivana greska" << endl;
	}
	try {
		for (int i = 0; i < 5; i++)
			k1.dodaj((double)500 * (double)rand() / (double)RAND_MAX);
		cout << k1 << "Prosek = " << k1.prosek() << endl;
		k1.izbaci(5);
		cout << k1 << endl;
	}
	catch (exception ec) {
		cerr << ec.what() << endl;
	}
	catch (...) {
		cerr << "Neocekivana greska" << endl;
	}
}