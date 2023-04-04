#pragma once
#include<iostream>
using namespace std;
class Takmicar
{
private:
	int ind;
	int broj;
	double rez;
public:
	Takmicar() {
		ind = broj = 0;
		rez = 0;
	}
	Takmicar(int a,int b,double c) {
		ind = a;
		broj = b;
		rez = c;
	}
	~Takmicar()
	{
	
	}
	Takmicar operator=(Takmicar& T)
	{
		ind = T.ind;
		broj = T.broj;
		rez = T.rez;
		return*this;
	}
	friend bool operator==(Takmicar& T1, Takmicar& T2);
	friend ostream& operator<<(ostream& izlaz, Takmicar& T);
};

bool operator==(Takmicar& T1, Takmicar& T2)
{
	return T1.ind == T2.ind;
}
ostream& operator<<(ostream& izlaz, Takmicar& T)
{
	izlaz << "Takmicar(identifikacija,broj,rezultat): " << T.ind << ", " << T.broj << ", " << T.rez << endl;
	return izlaz;
}