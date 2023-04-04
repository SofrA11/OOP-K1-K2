#pragma once
#include <iostream>
using namespace std;
class Figura
{
private:
	double x;
	double y;
public:
 virtual friend istream& operator>> (istream& ulaz, Figura& F);
 virtual friend ostream& operator<< (ostream& izlaz, Figura& F);
 virtual double povrsina();
};

