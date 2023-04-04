#pragma once
#include "Figura.h"
class Kvadrat :
    public Figura
{
private:
    double stranica;
public:
    Kvadrat(double s, double x, double y);
    virtual double povrsina();


};

