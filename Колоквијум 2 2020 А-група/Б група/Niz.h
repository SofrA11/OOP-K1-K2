#pragma once
#include<exception>
#include<iostream>
using namespace std;
template<class T>
class Niz
{
private:
	int n;
	int tren;
	T* niz;
public:
	Niz()
	{
		n = tren = 0;
		niz = 0;
	}
	Niz(int x)
	{
		tren = 0;
		n = x;
		niz = new T[n];
	}
	~Niz()
	{
		if (niz !=nullptr)
			delete[] niz;
		niz = 0;
	}
	T suma(int ind)
	{
		if (ind < 0)
			throw exception("nevalidan indeks za sumiranje");
		T sum;
		sum = niz[0];
		for (int i = 1;i < ind;i++)
			sum = sum + niz[i];
		return sum;
	}
	void dodaj(T element)
	{
		int o = 0;
		if (tren >= n)
			throw exception("Nije moguce dodati element u pun niz");
		if(!(suma(tren)<element))
		 throw exception("Nije moguce dodati element, uslov sume nije ispunjen");
		for (int i = 0;i < tren;i++)
		{
			if (element<niz[i] && suma(i) < element)
			{
				for (int j = tren;j > i;j--)
				{
					niz[j] = niz[j - 1];
				}
				niz[i] = element;
				o = 28;
				i = tren * 2;
			}
		}
		if (o != 28 && suma(tren) < element)
			niz[tren] = element;
		tren++;
	}
	void brisi(int ind)
	{
		if (tren <= 0)
			throw exception("Nije moguce brisati iz praznog niza!!!");
		if(ind<0 || ind>tren)
			throw exception("Index out of bounds");
		for (int i = ind-1;i < tren - 1;i++)
			niz[i] = niz[i + 1];
		tren--;
	}
	friend ostream& operator<< <>(ostream& izlaz, Niz<T>& N);
	friend istream& operator>> <>(istream& ulaz, Niz<T>& N);

};
template<class T>
ostream& operator<< <>(ostream& izlaz, Niz<T>& N)
{
	izlaz << "Ovaj niz ima ukupno " << N.n << " elemenata, od kojih je " << N.tren << " popunjeno";
	for (int i = 0;i < N.tren;i++)
		izlaz << N.niz[i]<<" ";
	izlaz << endl;
	return izlaz;
}
template<class T>
istream& operator>> <>(istream& ulaz, Niz<T>& N)
{
	if (N.n == 0)
	{
		ulaz >> N.n;
		N.niz = new T[N.n];
	}
	for (int i = 0;i <N.n;i++)
	{
		T pom;
		ulaz >> pom;
		N.dodaj(pom);
	}
	return ulaz;
}
