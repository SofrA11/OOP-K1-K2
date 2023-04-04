#pragma once
class Cvet
{
protected:
	char _imeCveta;
	float _cena;
public:
	Cvet();

	virtual void IzracunajCenu() = 0;

	float GetCena() { return _cena; }
	char GetIme() { return _imeCveta; }
};

