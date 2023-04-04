#include "Rep.h"

Rep::Rep()
{
MaxUdarac=0;
 brKrljustipoM2=0;
}

Rep::Rep(double mu, int brk, char ipv[30], char b[25],char naziv[25])
	:DeoTela(naziv)
{
   MaxUdarac=mu;
    brKrljustipoM2=brk;
    strcpy(imePrvogViteza, ipv);
    strcpy(boja, b);
}

Rep::~Rep()
{

}

void Rep::prikaz(ostream& out)
{
    out << "(snaga, br_krlj_po_m^2, boja) = (" << MaxUdarac << ", " << brKrljustipoM2 << ", " << boja << ") Prvi mlatnuti vitez: " << imePrvogViteza;
}
