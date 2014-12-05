#include "LoptaHra.h"
#include "LoptaEngine.h"
#include "Lopta.h"
#include "Plocha.h"

LoptaHra::LoptaHra()
{
	aHraciaPlocha = new Plocha(550,550);
	int cas = aHraciaPlocha->dajCas();
	srand(cas);
	aEngine = new LoptaEngine(aHraciaPlocha);
}


LoptaHra::~LoptaHra()
{
	delete aEngine;
	delete aHraciaPlocha;
}

void LoptaHra::run()
{
	if (aEngine)
		aEngine->start();
}
