#include "Kvadrat.h"

Kvadrat::Kvadrat(double s, double x, double y)
{
    stranica = s;
Figura:x = x;
Figura:y = y;
}

double Kvadrat::povrsina()
{
    return stranica*stranica;
}
