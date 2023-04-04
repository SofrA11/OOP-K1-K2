#pragma once
#include "Cvet.h"
class Lala : public Cvet
{
private:
	float _masa;

public:
	static float _cenaPoGramu;

	Lala(float masa) : Cvet()
	{
		_masa = masa;
		_imeCveta = 'l';

		Lala::IzracunajCenu();
	}

	virtual void IzracunajCenu();

	static void SetCenaPoGramu(float cena) { _cenaPoGramu = cena; }

	//float GetIme() { return _imeCveta; }
};

