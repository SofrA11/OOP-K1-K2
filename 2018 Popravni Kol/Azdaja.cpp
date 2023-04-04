#include "Azdaja.h"
#include<iostream>
using namespace std;
Azdaja::Azdaja()
{
	brojGlava = brojRepova = brojKrila = identifikacijaAzdaje= brojDelovaTela=0;
	DT = new DeoTela * [0];
}

Azdaja::Azdaja(int g, int r, int k, int id)
{
	 brojGlava=g;
	 brojRepova=r;
	 brojKrila=k;
	 identifikacijaAzdaje=id;
	 brojDelovaTela = brojGlava + brojKrila + brojRepova;
	 DT = new DeoTela * [brojGlava + brojKrila + brojRepova];
}

void Azdaja::DodajDeoTela(char c)
{
	char boja[25];
	char vitez[25];
	switch (c)
	{
	case'g':
		int id,brRogova,brTetovaza;
		cout << "Unesi ID glave: ";
		cin >> id;
		cout << "Unesi broj rogova: ";
		cin >> brRogova;
		cout << "Unesi broj tetovaza: ";
		cin >> brTetovaza;
		DT[brojDelovaTela] = new Glava(id,brRogova,brTetovaza,(char*)"glava");
		brojGlava++;
		brojDelovaTela++;
		break;
	case'k':
		double d, s, m, n;
		cout << "Unesi boju: ";
		cin >> boja;
		cout << "Unesi sirinu: ";
		cin >> s;
		cout << "Unesi duzinu: ";
		cin >> d;
		cout << "Unesi nosivost: ";
		cin >> n;
		cout << "Unesi max frekvenciju mahanja: ";
		cin >> m;
		DT[brojDelovaTela] = new Krilo(boja,d,s,n,m, (char*)"krilo");
		brojDelovaTela++;
		brojKrila++;
		break;
	case'r':
		double mu;
		int brk;
		cout << "Unesi Max udarac: ";
		cin >> mu;
		cout << "Unesi broj krljusti po metru kvadratnom: ";
		cin >> brk;
		cout << "Unesi ime prvog viteza: ";
		cin >> vitez;
		cout << "Unesi boju: ";
		cin >> boja;
		DT[brojDelovaTela] = new Rep(mu, brk, vitez, boja, (char*)"rep");
		brojDelovaTela++;
		brojRepova++;
		break;
	}
}

void Azdaja::PrikaziSpisak(ostream& out)
{
	out << "Azdaja: " << identifikacijaAzdaje+1 << endl;
	for (int i = 0;i < brojDelovaTela;i++)
		out << *DT[i] << endl;
}

Azdaja::~Azdaja()
{
	if (DT != nullptr)
	{
		delete[] DT;
	}
	DT = nullptr;
}
