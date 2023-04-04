#pragma once
#include<iostream>
#include<exception>
using namespace std;
template<class T>
class Skup{
private:
	T* niz;
	int n;
	int tren;
public:
	Skup() {
		n = tren = 0;
		niz = new T[n];
	}
	Skup(int br)
	{
		n = br;
		tren = 0;
		niz = new T[n];
	}
	~Skup(){}

	bool postoji(T element)
	{
		for (int i = 0;i < tren;i++)
		{
			if (niz[i] == element)
				return true;
		}
		return false;
	}
	int getInd(T element)
	{
		if (postoji(element) == true)
			for (int i = 0;i < tren;i++)
				if (niz[i] == element)
					return i;
	}
	void dodaj(T element)
	{
		for (int i = 0;i < tren;i++)
		{
			if (niz[i] == element)
			throw exception("Element vec postoji u nizu");
		}
		niz[tren] = element;
		tren++;
	}

	void brisi(T element)
	{
		if(postoji(element)==false)
			throw exception("Element ne postoji u nizu");
		int ind=getInd(element);
		for (int i = ind;i < tren - 1;i++)
			niz[i] = niz[i + 1];
		tren--;
	}
	void Sort(int s)
	{
		T pom;
		if (s == 1)//rastuci 
		{
			for (int i = 0;i < tren;i++)
			{
				for(int j=0;j<tren;j++)
				{
					if (niz[i] > niz[i + 1])
					{
						pom = niz[i];
						niz[i] = niz[i + 1];
						niz[i + 1] = pom;
					}
				}

			}
		}
		else
			if (s == -1)//opadajuci
			{
				for (int i = 0;i < tren;i++)
				{
					for (int j = 0;j < tren;j++)
					{
						if (niz[i] < niz[i + 1])
						{
							pom = niz[i];
							niz[i] = niz[i + 1];
							niz[i + 1] = pom;
						}
					}

				}
			}
			else
				throw exception("Nevalidan nacin uredjenja skupa");
	}
	Skup& presek(Skup& S)
	{
		int m,j=0;
		n > S.n ? m = n : m = S.n;
		Skup* pom = new Skup(m);
		for(int i=0;i<tren;i++)
		{
			if (S.postoji(niz[i]))
			{
				pom->niz[j] = niz[i];
				j++;
			}
		}
		pom->tren = j;
		return *pom;
	}
	friend istream& operator>> <>(istream& ulaz, Skup<T>& S);
	friend ostream& operator<< <>(ostream& izlaz, Skup<T>& S);
	Skup operator= (Skup& S)
	{
		if (niz != nullptr)
			delete[] niz;
		niz = new T[S.n];
		n = S.n;
		tren = S.tren;
		for (int i = 0;i < tren;i++)
			niz[i] = S.niz[i];
		return*this;
	}

};
template<class T>
istream& operator>> <>(istream& ulaz, Skup<T>& S)
{
	
	for (int i = 0;i <S.n;i++)
	{
		T el;
		ulaz >> el;
		S.dodaj(el);
	}
	return ulaz;
}
template<class T>
ostream& operator<< <>(ostream& izlaz, Skup<T>& S) 
{
	izlaz << "Broje elemenata skupa je " << S.tren << " ";
	for (int i = 0;i < S.tren;i++)
	{
		izlaz << S.niz[i] << endl;
	}
	return izlaz;
}