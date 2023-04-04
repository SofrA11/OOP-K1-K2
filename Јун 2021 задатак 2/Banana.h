#pragma once
#include <iostream>
#include <exception>
using namespace std;

class Banana {
private:
	double masa;
	bool trula;
public:
	Banana() {
		masa = 0;
		trula = false;
	}
	Banana(double m) {
		if (m < -1 || masa == 0)
			throw exception("Nije moguce dodati bananu sa neregularnom masom, osim -1 kada je trula");
		masa = m;
		trula = false;
		if (masa == -1)
			trula = true;
	}
	~Banana() {}
	double get_masa() {
		return masa;
	}
	friend ostream& operator<<(ostream& out, const Banana& b);
	friend double& operator+=(double& s, const Banana& b);
	friend bool operator>(const Banana& b, double s);
	friend bool operator<(const Banana& b, double s);
};

bool operator<(const Banana& b, double s) {
	return b.masa < s;
}

bool operator>(const Banana& b, double s) {
	return b.masa > s;
}

double& operator+=(double& s, const Banana& b) {
	s += b.masa;
	return s;
}

ostream& operator<<(ostream& out, const Banana& b) {
	if (b.trula)
		out << " Trula banana" << endl;
	else
		out << "Banana(m = " << b.masa << ")" << endl;
	return out;
}
