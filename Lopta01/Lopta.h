#pragma once
#include "PohyblivyObjekt.h"
#include "IPlocha.h"

class Lopta : public PohyblivyObjekt
{
private:
	IPlocha *aHraciaPlocha;
	IPlocha *aLopta;
public:
	Lopta(IPlocha *aHraciaPlocha);
	~Lopta();
	virtual void nakreslisa();
	virtual int dajBody();
};

