#include "Ruza.h"
#include <math.h>

void Ruza::IzracunajCenu()
{
	_cena = _cenaBeleRuze / pow(float((255 - _r) * (255 - _g) * (255 - _b)), 1.00 / 4.00);
}