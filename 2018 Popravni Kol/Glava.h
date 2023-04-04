#pragma once
#include "DeoTela.h"
class Glava :
    public DeoTela
{
private:
    int ID_Glave;
    int brojRogova;
    int brojTetovaza;
public:
    Glava();
    Glava(int,int,int,char* c);
    ~Glava();
    void prikaz(ostream&);
};

