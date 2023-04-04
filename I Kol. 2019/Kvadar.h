#pragma once
#include "Figura.h"
class Kvadar :
    public Figura
{
private:
    double stranicaA;
    double stranicaB;
public:
    Kvadar(double a, double b, double x, double y);
    virtual double povrsina();
};

