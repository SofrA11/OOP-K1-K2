#include "Skola.h"
#include "Sport.h"
#include "Umetnost.h"

int main() {
	ifstream sport("sport.txt");
	ofstream izvestaj_sport("sport_izvestaj.txt");
	ofstream izvestaj_umetnost("umetnost_izvestaj.txt");
	Skola* skola_sporta = new Skola(10);
	Skola* skola_umetnosti = new Skola(5);
	if (!sport.good() or !izvestaj_sport.good() or !izvestaj_umetnost.good())
		return 0;
	for (int i = 0; i < 10; i++)
		skola_sporta->dodaj_aktivnost(new Sport());
	for (int i = 0; i < 5; i++)
		skola_umetnosti->dodaj_aktivnost(new Umetnost());
	try {
		skola_sporta->ucitaj(sport);
		skola_umetnosti->ucitaj(cin);

		skola_sporta->ukloni_aktivnost(1);
		skola_sporta->ukloni_aktivnost(0);
		
		skola_umetnosti->ukloni_aktivnost(3);
		skola_umetnosti->ukloni_aktivnost(4);

		skola_sporta->prikaz(izvestaj_sport);
		skola_umetnosti->prikaz(izvestaj_umetnost);
	}
	catch (exception ec) {
		cerr << ec.what();
	}
	catch (...) {
		cerr << "Neocekivana greska";
	}
	sport.close();
	izvestaj_sport.close();
	izvestaj_umetnost.close();
	delete skola_sporta;
	delete skola_umetnosti;

}