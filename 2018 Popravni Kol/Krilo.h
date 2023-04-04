#pragma once
#include "DeoTela.h"
class Krilo :
    public DeoTela
{
private:
    char boja[25];
    double duzina;
    double sirina;
    double nosivost;
    double maxFrekvencijaMahanja;
public:
    Krilo();
    Krilo(char b[25], double, double, double, double,char ime[30]);
    ~Krilo();
    void prikaz(ostream&);
};

