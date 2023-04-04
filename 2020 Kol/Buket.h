#pragma once
#include "Cvet.h"
#include "Lala.h"
#include "Ruza.h"
#include <iostream>
using namespace std;

class Buket
{
private:
	Cvet** _cvetovi;
	int _brojCvetova;
	int _used;

public:
	Buket();

	Buket(int brojCvetova);

	~Buket();

	void DodajLalu(float masa);
	void DodajRuzu(int r, int g, int b);

	friend ostream& operator<<(ostream& os, const Buket& b);
};

