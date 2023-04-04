#pragma once
#include<iostream>
#include <exception>
using namespace std;
template<class T>
class Lista {
private:
	T* niz;
	int n;
	int tren;
public:
	Lista() {
		n = 0;
		niz = new T[n];
		tren = 0;
	}
	Lista(int br)
	{
		n = br;
		niz = new T[n];
		tren = 0;
	}
	~Lista() {
		if (niz != nullptr)
			delete[] niz;
		niz = nullptr;
	}
	void dodaj(T ulaz)
	{
		if (tren < n)
		{
			niz[tren] = ulaz;
			tren++;
		}
		else
		{
			throw exception("Greska prilikom dodavanja elementa,Niz je pun!!!");
		}
	}
	void brisi(T k)
	{
		for (int i = 0;i < tren;i++)
		{
			if (niz[i] == k)
			{
				for (int j = i;j < tren-1;j++)
				{
					niz[j] = niz[j + 1];
				}
				tren--;
				i == 0 ? i = 0 : i--;
			}
		}
	}
	Lista<T>& upari(Lista<T>& L)
	{
		int m = 2*duza(L);
		Lista* pom = new Lista<T>(m);
		 m = kraca(L);
		int j = 0;
		int i = 0,g;
		for (i = 0,j=0;i <m;i++,j++)
		{
			pom->niz[j] = niz[i];
			j++;
			pom->niz[j] = L.niz[i];
			pom->tren += 2;
			if (tren > m * 2)
				throw exception("Trenutni broj elemenata ne moze biti veci od maksimalnog!!!");
		}
		if (tren != m)
		{
			for (int q = i, g = j;i < tren;i++, g++)
			{
				pom->niz[g] = niz[i];
				g++;
				pom->niz[g] = niz[i];
				pom->tren += 2;
				if (tren > m * 2)
					throw exception("Trenutni broj elemenata ne moze biti veci od maksimalnog!!!");
			}
		}
		else if (L.tren != m)
		{
			for (int q = i, g=j;i < L.tren;i++, g++)
			{
				pom->niz[g] = L.niz[i];
				g++;
				pom->niz[g] = L.niz[i];
				pom->tren += 2;
				if (tren > m * 2)
					throw exception("Trenutni broj elemenata ne moze biti veci od maksimalnog!!!");
			}
		}
		return *pom;
	}
	int kraca(Lista& L)
	{
		if (tren < 0 || L.tren < 0)
			throw exception("Niz ne moze imati negativan broj elemenata!!!");
		if (tren > L.tren)
			return L.tren;
		else
			if (tren < L.tren)
				return tren;
			else
				return tren;
	}
	int duza(Lista& L)
	{
		if (tren < 0 || L.tren < 0)
			throw exception("Niz ne moze imati negativan broj elemenata!!!");
		if (tren > L.tren)
			return tren;
		else
			if (tren < L.tren)
				return L.tren;
			else
				return tren;
	}
	Lista<T>& operator= (Lista<T>& L) {

		tren = L.tren;
		if(niz!=0)
		{
			delete[] niz;
		}
		niz = new T[L.n];
		for (int i = 0;i < L.tren;i++)
			niz[i] = L.niz[i];
		return *this;
	}
	friend ostream& operator<< <>(ostream& izlaz, Lista<T>& L);
};
template<class T>
ostream& operator<< (ostream& izlaz, Lista<T>& L)
{
	for (int i = 0;i < L.tren;i++)
		izlaz << L.niz[i] << " ";
	izlaz << endl;
	return izlaz;
}