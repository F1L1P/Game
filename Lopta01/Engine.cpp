#include "Engine.h"


Engine::Engine(PohyblivyObjekt *objekt)
: aObjekt(objekt), aSkore(0)
{
}


Engine::~Engine()
{
}

void Engine::start()
{
	int x{ -1 }, y{ -1 };
	zobrazSkore();
	while (vstup(x, y))
	{
		spracujVstup(x, y);
		aktualizujsa();
		reset();
	}
}

void Engine::spracujVstup(int x, int y)
{
	if (aObjekt && x >= 0)
	{
		if (aObjekt->zasah(x, y))
			aSkore += aObjekt->dajBody();
		else
			aSkore -= aObjekt->dajBody();
	}
}

void Engine::aktualizujsa()
{
	zobrazSkore();
	if (aObjekt)
	{
		if (aObjekt->aktualizujsa(dajCas()))
		{
			vymaz();
			aObjekt->nakreslisa();
		}
	}
}
