#pragma once
#include <iostream>
#include <exception>
using namespace std;

template<typename Type, int n>
class Kolekcija {
private:
	int k;
	Type* niz;
public:
	Kolekcija() {
		k = 0;
		niz = new Type[n];
	}
	~Kolekcija() {
		if (niz != 0)
			delete[] niz;
		niz = 0;
	}
	void dodaj(Type new_element) {
		if (k + 1 > n)
			throw exception("Dostignut pun kapacitet kolekcije");
		niz[k++] = new_element;
	}
	double prosek() {
		double s = 0;
		for (int i = 0; i < k; i++)
			s += niz[i];
		return s / (double)k;
	}
	void izbaci(double proc) {
		double max = prosek() * (1 + proc / 100);
		double min = prosek() * (1 - proc / 100);
		for (int i = 0; i < k; i++) {
			if (niz[i] > max or niz[i] < min) {
				for (int j = i; j < k - 2; j++)
					niz[j] = niz[j + 1];
				k -= 1;
				i -= 1;
			}
		}
	}
	friend ostream& operator<< <>(ostream& out, const Kolekcija<Type, n>& kol);
};

template<class Type, int n>
ostream& operator<<(ostream& out, const Kolekcija<Type, n>& kol) {
	for (int i = 0; i < kol.k; i++)
		out << kol.niz[i] << " ";
	return out;
}
