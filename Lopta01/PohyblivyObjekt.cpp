#include <cstdlib>
#include "PohyblivyObjekt.h"

const int DELTA = 3;
const int IMIN = 10;
const int IMAX = 20;

PohyblivyObjekt::PohyblivyObjekt(int sirkaplocha, int vyskaplocha, int sirka, int vyska)
:aSirkaPlocha(sirkaplocha), aVyskaPlocha(vyskaplocha),
aSirka(sirka), aVyska(vyska),
aX(0), aY(0),
aDeltaX(0), aDeltaY(0),
aCas(0), aInterval(0)
{
	reset();
}

void PohyblivyObjekt::reset()
{
	aX = grand(0, aSirkaPlocha - aSirka);
	aY = grand(0, aVyskaPlocha - aVyska);
	aDeltaX = grand(-DELTA, DELTA);
	aDeltaY = grand(-DELTA, DELTA);
	aInterval = grand(IMIN, IMAX);
}

int PohyblivyObjekt::grand(int minval, int maxval)
{
	if (maxval - minval != 0)
		return rand() % (maxval - minval) + minval;
	return 0;
}

PohyblivyObjekt::~PohyblivyObjekt()
{
}

bool PohyblivyObjekt::aktualizujsa(int cas)
{
	if ((cas - aCas) >= aInterval)
	{
		aX += aDeltaX;
		aY += aDeltaY;
		if (aX <= 0 || aX >= (aSirkaPlocha - aSirka))
		{
			aDeltaX = -aDeltaX;
			aX += aDeltaX;
		}
		if (aY <= 0 || aY >= (aVyskaPlocha - aVyska))
		{
			aDeltaY = -aDeltaY;
			aY += aDeltaY;
		}
		aCas = cas;
		return true;
	}
	return false;
}

bool PohyblivyObjekt::zasah(int x, int y)
{
	bool ret = x >= aX && x <= aX + aSirka && y >= aY && y <= aY + aVyska;
	if (ret)
		reset();
	return ret;
}

int PohyblivyObjekt::dajBody()
{
	return 0;
}
