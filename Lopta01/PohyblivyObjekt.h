#pragma once
#include "IObjekt.h"

class PohyblivyObjekt : public IObjekt
{
private:
	int aDeltaX, aDeltaY;
	int aInterval;
	int aCas;
	int aSirkaPlocha, aVyskaPlocha;
	void reset();
	int grand(int minval, int maxval);
protected:
	int aX, aY;
	int aSirka, aVyska;
public:
	PohyblivyObjekt(int sirkaplocha, int vyskaplocha, int sirka, int vyska);
	~PohyblivyObjekt();
	virtual bool aktualizujsa(int cas);
	virtual bool zasah(int x, int y);
	virtual int dajBody();
};

