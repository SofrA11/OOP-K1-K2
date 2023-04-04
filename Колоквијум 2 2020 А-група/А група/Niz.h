#pragma once
#include <exception>
#include <iostream>
using namespace std;

template <class Type, int size>
class Niz {
private:
	Type* niz;
	int tren;
public:
	Niz() {
		niz = new Type[size];
		tren = 0;
	}
	~Niz() {
		if (niz != 0)
			delete[] niz;
		niz = 0;
	}
	void dodaj(Type new_element) {
		if (tren + 1 > size)
			throw exception("Niz je pun");
		bool found = false;
		int i = 0;
		while (i < tren and not found) {
			if (new_element == niz[i])
				throw exception("Element je vec u nizu");
			else if (niz[i] > new_element)
				found = true;
			else
				i += 1;
		}
		for (int j = tren; j > i; j--)
			niz[j] = niz[j - 1];
		niz[i] = new_element;
		tren += 1;
	}
	void ukloni(int ind) {
		if (ind < 0 or ind > tren)
			throw exception("Invalid index");
		for (int i = ind; i < tren; i++)
			niz[i] = niz[i + 1];
		tren -= 1;
	}
	Type& operator[](int ind) {
		if (ind < 0 or ind > tren)
			throw exception("Invalid index");
		return niz[ind];
	}
	friend ostream& operator<< <>(ostream& out, Niz<Type, size>& niz);
	friend istream& operator>> <>(istream& in, Niz<Type, size>& niz);
};

template<class Type, int size>
ostream& operator<<(ostream& out, Niz<Type, size>& niz) {
	for (int i = 0; i < niz.tren; i++)
		out << niz[i] << endl;
	return out;
}

template <class Type, int size>
istream& operator>>(istream& in, Niz<Type, size>& niz) {
	for (int i = 0; i < size; i++) {
		Type pom;
		in >> pom;
		niz.dodaj(pom);
	}
	return in;
}

