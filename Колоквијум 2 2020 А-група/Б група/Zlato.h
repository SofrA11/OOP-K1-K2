#pragma once
#include<exception>
#include<iostream>
using namespace std;

class ZlatnaPoluga
{
private:
	int finoca;// od 1 do 999 u promilima
	double masa;//>0 unce
public:
	ZlatnaPoluga()
	{
		finoca = 0;
		masa = 0;
	}
	ZlatnaPoluga(int x,double y)
	{
		if (x < 1 || x>999)
			throw exception("Greska, nevalidan opseg cistoce zlata");
		if (y <= 0)
			throw exception("Masa ne moze biti negativna");
		finoca = x;
		masa = y;
	}
	~ZlatnaPoluga()
	{

	}
	ZlatnaPoluga& operator=(ZlatnaPoluga& Z)
	{
		finoca = Z.finoca;
		masa = Z.masa;
		return *this;
	}
	ZlatnaPoluga& operator+(ZlatnaPoluga& Z)
	{
		ZlatnaPoluga* pom=new ZlatnaPoluga;
		pom->finoca = finoca + Z.finoca;
		pom->masa = masa + Z.masa;
		return *pom;
	}
	 bool operator<(ZlatnaPoluga& Z1)
	 {
		 if ((((finoca) / 1000) * masa)<(((Z1.finoca) / 1000) * Z1.masa) )
		 {
			 return true;
		 }
		 return false;
	 }
	friend istream& operator>> (istream& ulaz, ZlatnaPoluga& Z);
	friend ostream& operator<< (ostream& izlaz, ZlatnaPoluga& Z);
};
istream& operator>> (istream& ulaz, ZlatnaPoluga& Z)
{
	ulaz >> Z.finoca >> Z.masa;
	if (Z.finoca < 1 || Z.finoca>999)
		throw exception("Greska, nevalidan opseg cistoce zlata");
	if (Z.masa <= 0)
		throw exception("Masa ne moze biti negativna");
	return ulaz;
}
ostream& operator<< (ostream& izlaz, ZlatnaPoluga& Z)
{
	izlaz << "Finoca zlata u poluzi je " << Z.finoca << ", a masa poluge je " << Z.masa << endl;
	return izlaz;
}