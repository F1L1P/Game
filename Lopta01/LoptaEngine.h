#pragma once
#include "Engine.h"
#include "IPlocha.h"
#include "Lopta.h"

class LoptaEngine : public Engine
{
private:
	IPlocha *aHraciaPlocha;
public:
	LoptaEngine(IPlocha *plocha = NULL);
	~LoptaEngine();

	virtual void zobrazSkore();
	virtual bool vstup(int &x, int &y);
	virtual int dajCas();
	virtual void reset();
	virtual void vymaz();
};

