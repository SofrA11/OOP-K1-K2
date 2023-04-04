#pragma once
#include<exception>
#include<iostream>
#include<math.h>
using namespace std;

class Sef
{
private:
	int brojBrava;// >1 <4
	int debljina;//u mm >0
	int duzina;//u cm >0
	int gustina;// g/m3 >0
public:
	// masa = duzina*duzina*duzina - (duzina-debljina)*(duzina-debljina)(duzina-debljina)
	//debljina*10 na -
	//duzina*10 na -2 
	Sef()
	{
		brojBrava = 0;
		debljina = 0;
		duzina = 0;
		gustina = 0;
	}
	~Sef()
	{
	}
	 bool operator<(Sef& S1)
	{
		 double masa1, masa2;
		 masa1 = S1.getMasa();
		 masa2 = getMasa();
		 if (masa2 * brojBrava < masa1 * S1.brojBrava)
			 return  true;
		 return false;
	}
	double getMasa()
	{
		double masa;
		masa = pow(10, -6) * (pow(duzina, 3) - pow((duzina - (debljina / 5)), 3));
		masa = masa * gustina;
		return masa;
	}
	Sef& operator=(Sef& S)
	{
		brojBrava=S.brojBrava;
		 debljina=S.debljina;
		 duzina=S.duzina;
		 gustina=S.gustina;
		 return *this;
	}
	Sef& operator+(Sef& S)
	{
		Sef* pom = new Sef;
		pom->brojBrava = brojBrava+S.brojBrava;
		pom->debljina = debljina+S.debljina;
		pom->duzina = duzina+ S.duzina;
		pom->gustina = gustina+ S.gustina;
		return *pom;
	}
	friend istream& operator>>(istream& ulaz, Sef& S);
	friend ostream& operator<<(ostream& izlaz, Sef& S);
};

istream& operator>>(istream& ulaz, Sef& S)
{
	ulaz >> S.brojBrava >> S.debljina >> S.duzina >> S.gustina;
	if (S.brojBrava < 1 || S.brojBrava>4)
		throw exception("Brava van opsega");
	if (S.debljina<0||S.duzina<0)
		throw exception("Duzina ne moze biti negativna");
	if (S.gustina<0)
		throw exception("Gustina mora biti >0");
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Sef& S)
{
izlaz << S.brojBrava<<" "<< S.debljina <<" " << S.duzina<<" "<< S.gustina;
return izlaz;
}