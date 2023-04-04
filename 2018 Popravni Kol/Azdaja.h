#pragma once
#include "DeoTela.h"
#include "Glava.h"
#include"Krilo.h"
#include"Rep.h"
class Azdaja
{
private:
	int brojGlava;
	int brojRepova;
	int brojKrila;
	int brojDelovaTela;
	int identifikacijaAzdaje;
	DeoTela** DT;
public:
	Azdaja();
	Azdaja(int, int, int,int);
	void DodajDeoTela(char);
	void PrikaziSpisak(ostream&);
	~Azdaja();
};

