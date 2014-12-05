#pragma once
#include "IPlocha.h"

struct SDL_Surface;

class Plocha : public IPlocha
{
private:
	SDL_Surface *aPlocha;
	static int aCitac;
	Plocha(SDL_Surface *gobjekt) : aPlocha(gobjekt)
	{
		aCitac++;
	}

public:
	Plocha(int sirka, int vyska);

	Plocha(const Plocha &zdroj)
	{
		aCitac++;
	}
	~Plocha();
	virtual int sirka();
	virtual int vyska();
	virtual IPlocha *citajBMP(const char *menosuboru);
	virtual void nakresli(IPlocha *objekt, int x, int y);
	virtual void zobrazSkore(const char *text);
	virtual bool vstup(int &x, int &y);
	virtual int dajCas();
	virtual void reset();
	virtual void vymaz();
	void *plocha() { return aPlocha; }
};

