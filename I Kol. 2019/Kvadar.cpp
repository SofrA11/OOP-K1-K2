#include "Kvadar.h"

Kvadar::Kvadar(double a, double b, double x,double y)
{
    stranicaA = a;
    stranicaB = b;
Figura:x = x;
Figura:y = y;
}

double Kvadar::povrsina()
{
    return stranicaA*stranicaB;
}
