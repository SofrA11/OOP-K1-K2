#include "Cvet.h"
#pragma once
class Ruza : public Cvet
{
private:
	int _r;
	int _g;
	int _b;

public:
	static float _cenaBeleRuze;

	Ruza() : Cvet()
	{
		_r = 0;
		_g = 0;
		_b = 0;
		_imeCveta = 'r';
	}

	Ruza(int r, int g, int b) : Cvet()
	{
		_r = r;
		_g = g;
		_b = b;
		_imeCveta = 'r';

		Ruza::IzracunajCenu();
	}

	static void SetCenaBeleRuze(float cena) { _cenaBeleRuze = cena; }

	virtual void IzracunajCenu();

	//float GetIme() { return _imeCveta; }
};

