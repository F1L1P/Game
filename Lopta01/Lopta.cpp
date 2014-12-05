#include <cstdlib>
#include "Lopta.h"


Lopta::Lopta(IPlocha *hraciaplocha)
: PohyblivyObjekt(hraciaplocha ? hraciaplocha->sirka() : 0, hraciaplocha?hraciaplocha->vyska():0, 
					0, 0),
aHraciaPlocha(hraciaplocha),
aLopta(NULL)
{
	if (aHraciaPlocha)
		aLopta = aHraciaPlocha->citajBMP("ball.bmp");
	if (aLopta)
	{
		aSirka = aLopta->sirka();
		aVyska = aLopta->vyska();
	}
}


Lopta::~Lopta()
{
}

void Lopta::nakreslisa()
{
	if (aHraciaPlocha)
		aHraciaPlocha->nakresli(aLopta, aX, aY);
}

int Lopta::dajBody()
{
	return 1;
}
