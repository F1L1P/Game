#include <sstream>
#include "LoptaEngine.h"


LoptaEngine::LoptaEngine(IPlocha *plocha)
:aHraciaPlocha(plocha)
{
	Lopta *lopta = new Lopta(plocha);
	aObjekt = lopta;
}


LoptaEngine::~LoptaEngine()
{
	delete aObjekt;
}

void LoptaEngine::zobrazSkore()
{
	if (aHraciaPlocha)
	{
		std::ostringstream text;
		text << "Pocet bodov: " << aSkore;
		if (aHraciaPlocha)
			aHraciaPlocha->zobrazSkore(text.str().c_str());
	}
}

bool LoptaEngine::vstup(int &x, int &y)
{
	if (aHraciaPlocha)
		return aHraciaPlocha->vstup(x, y);
	return false;
}


int LoptaEngine::dajCas()
{
	if (aHraciaPlocha)
		return aHraciaPlocha->dajCas();
	return 0;
}

void LoptaEngine::reset()
{
	if (aHraciaPlocha)
		aHraciaPlocha->reset();
}

void LoptaEngine::vymaz()
{
	if (aHraciaPlocha)
		aHraciaPlocha->vymaz();
}
