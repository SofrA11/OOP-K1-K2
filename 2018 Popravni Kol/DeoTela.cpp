#include "DeoTela.h"

DeoTela::DeoTela()
{
	naziv = nullptr;
}

DeoTela::DeoTela(char* ime)
{
	naziv = new char[strlen(ime) + 1];
	strcpy(naziv, ime);
}

DeoTela::~DeoTela()
{
	if (naziv != nullptr)
	{
		delete[] naziv;
	}
	naziv = nullptr;
}

ostream& operator<<(ostream& out, DeoTela& dt)
{
	dt.prikaz(out);
	return out;
}
