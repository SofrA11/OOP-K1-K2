#include "Krilo.h"
#include<string.h>
Krilo::Krilo()
{
	duzina = sirina = nosivost = maxFrekvencijaMahanja = 0;
}

Krilo::Krilo(char b[25], double d, double s, double n, double m,char ime[30])
	:DeoTela(ime)
{
	strcpy(boja, b);
	duzina = d;
	sirina = s;
	nosivost = n;
	maxFrekvencijaMahanja = m;
}

Krilo::~Krilo()
{
	
}

void Krilo::prikaz(ostream& out)
{
	out <<" (duzina,sirina, nosivost, frekvencija, boja) = ("<<duzina<<", "<< sirina << ", " << nosivost << ", " << maxFrekvencijaMahanja << ", " << boja << ")"<<endl;
}
