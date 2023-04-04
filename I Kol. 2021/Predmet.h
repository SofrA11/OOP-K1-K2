#pragma once
#include <iostream>
using namespace std;
class Predmet
{
protected:
	float _masa;
	float _vrednost;

public:
	Predmet();
	Predmet(float masa);

	virtual float IzracunajVrednost()=0;
	
	float GetMasa() { return _masa; }
	float GetVrednost() { return _vrednost; }
	virtual void print()=0;

};

