#include "Niz.h"
#include "Roda.h"
#include "Zaba.h"
#include <fstream>

int main() {
	ifstream rode("Rode.txt"), zabe("Zabe.txt");
	if (not rode.good() or not zabe.good())
		return 0;
	Niz<Roda, 5> A;
	Niz<Zaba, 7> B;
	try {
		rode >> A;
		A.ukloni(2);
		A.ukloni(7);
	}
	catch (exception ec) {
		cerr << ec.what() << endl;
	}
	cout << "Rode: " << endl << A << endl;

	try {
		zabe >> B;
		B.ukloni(-2);
		B.ukloni(5);
	}
	catch (exception ec) {
		cerr << ec.what() << endl;
	}
	cout << "Zabe: " << endl << B;

	rode.close();
	zabe.close();
	return 0;
}