#include "Ranac.h"
#include <iostream>;
using namespace std;

void main()
{
	cout << "Unesi broj predmeta u rancu"<< endl;
	int n=0;
	cin >> n;
	Ranac* r = new Ranac(n);
	float masa;
	char tip;
	for (int i = 0; i < n; i++)
	{
		do
		{
			cout << "Unesite tip za "<<i+1 <<". predmeta: ";
			cin >> tip;
		} while (tip != 'z' && tip != 'j' && tip != 'd');
		cout << "Unesite masu predmeta: ";
	cin >> masa;
		r->DodajPredmet(masa, tip);
	}

	cout << r[0];

	cout << endl << "Prosecna vrednost predmeta u rancu: " << r[0].ProsecnaVrednost();
	cout << endl << "Najveca vrednost predmeta u rancu: " << r[0].NajvrednijiPoMasi();
}