#pragma once
#include <iostream>
#include <exception>
using namespace std;

class Roda {
private:
	double masa;
	double raspon_krila;
	double visina;
	double pojedene_zabe;
public:
	Roda() {
		masa = raspon_krila = visina = pojedene_zabe = 0;
	}
	Roda(double m, double rk, double v, double pz) {
		if (m < 0 or rk < 0 or v < 0 or pz < 0)
			throw exception("Invalid value for class Roda");
		masa = m;
		raspon_krila = rk;
		visina = v;
		pojedene_zabe = pz;
	}
	~Roda() {}
	bool operator>(const Roda& r1) {
		if (masa > r1.masa or (masa == r1.masa and pojedene_zabe > r1.pojedene_zabe) or
			(masa == r1.masa and pojedene_zabe == r1.pojedene_zabe and visina > r1.visina) or
			(masa == r1.masa and pojedene_zabe == r1.pojedene_zabe and visina == r1.visina and raspon_krila > r1.raspon_krila))
			return true;
		return false;
	}
	bool operator==(const Roda& r1) {
		return (masa == r1.masa and raspon_krila == r1.raspon_krila and visina == r1.visina and pojedene_zabe == r1.pojedene_zabe);
	}
	double get_masa() {
		return masa;
	}
	friend ostream& operator<<(ostream& out, Roda& roda);
	friend istream& operator>>(istream& in, Roda& roda);
};

ostream& operator<<(ostream& out, Roda& roda) {
	out << "Roda (masa, visina, pojedene_zabe, raspon_krila) = " << "(" << roda.masa << ", " << roda.visina << ", " << roda.pojedene_zabe << ", " << roda.raspon_krila;
	return out;
}

istream& operator>>(istream& in, Roda& roda) {
	double m, v, pz, rk;
	in >> m >> v >> pz >> rk;
	if (m < 0 or v < 0 or pz < 0 or rk < 0)
		throw exception("Invalid value for class Roda");
	roda.masa = m; roda.visina = v; roda.pojedene_zabe = pz; roda.raspon_krila = rk;
	return in;
}

