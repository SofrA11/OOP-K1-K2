#pragma once
#include "DeoTela.h"
class Rep :
    public DeoTela
{
private:
    double MaxUdarac;
    int brKrljustipoM2;
    char imePrvogViteza[30];
    char boja[25];
public:
    Rep();
    Rep(double, int,char x[30],char y[25],char z[25]);
    ~Rep();
    void prikaz(ostream& out);
   
};

