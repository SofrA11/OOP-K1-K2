#pragma once
#include<string.h>
#include <iostream>
using namespace std;
class DeoTela
{private:
	char* naziv;
public:
	DeoTela();
	DeoTela(char*);
	~DeoTela();
	virtual void prikaz(ostream&)=0;
	friend ostream& operator<<(ostream&, DeoTela&);
};

