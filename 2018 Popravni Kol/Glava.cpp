#include "Glava.h"

Glava::Glava()
{
	ID_Glave = brojRogova = brojTetovaza = 0;
	
}

Glava::Glava(int id, int brR, int brT, char* c)
	:DeoTela(c)
{
	ID_Glave = id;
	brojRogova = brR;
	brojTetovaza = brT;
}

Glava::~Glava()
{
}

void Glava::prikaz(ostream& out)
{
	out << ID_Glave << "(br_rogova, br_tetovaza) = (" << brojRogova << ", " << brojTetovaza << ")";
}
