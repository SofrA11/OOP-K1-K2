#pragma once
#include <exception>
#include <iostream>
using namespace std;

class Zaba {
private:
	double gustina_pega;
	double masa;
	double velicina_muve;
public:
	Zaba() {
		gustina_pega = masa = velicina_muve = 0;
	}
	Zaba(double gp, double m, double vm) {
		if (gp < 0 or m < 0 or vm < 0)
			throw exception("Invalid value for class Zaba");
		gustina_pega = gp;
		masa = m;
		velicina_muve = vm;
	}
	~Zaba() {}
	bool operator>(const Zaba& z1) {
		if ((masa > z1.masa) or (masa == z1.masa and velicina_muve > z1.velicina_muve) or 
			(masa == z1.masa and velicina_muve == z1.velicina_muve and gustina_pega > z1.gustina_pega))
			return true;
		return false;
	}
	bool operator==(const Zaba& z1) {
		return (masa == z1.masa and velicina_muve == z1.velicina_muve and gustina_pega == z1.gustina_pega);
	}
	double get_masa() {
		return masa;
	}
	friend ostream& operator<<(ostream& out, Zaba& zaba);
	friend istream& operator>>(istream& in, Zaba& zaba);
};

ostream& operator<<(ostream& out, Zaba& zaba) {
	out << "Zaba (masa, gustina_pega, velicina_muve) = " << "(" << zaba.masa << ", " << zaba.gustina_pega << ", " << zaba.velicina_muve;
	return out;
}

istream& operator>>(istream& in, Zaba& zaba) {
	double m, gp, vm;
	in >> m >> gp >> vm;
	if (m < 0 or gp < 0 or vm < 0)
		throw exception("Invalid value for class Zaba");
	zaba.masa = m; zaba.gustina_pega = gp; zaba.velicina_muve = vm;
	return in;
}

