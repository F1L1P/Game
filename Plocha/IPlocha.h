#pragma once
class IPlocha
{
public:
	virtual int sirka() = 0;
	virtual int vyska() = 0;
	virtual IPlocha *citajBMP(const char *menosuboru) = 0;
	virtual void nakresli(IPlocha *objekt, int x, int y) = 0;
	virtual void zobrazSkore(const char *text) = 0;
	virtual bool vstup(int &x, int &y) = 0;
	virtual int dajCas() = 0;
	virtual void reset() = 0;
	virtual void *plocha() = 0;
	virtual void vymaz() = 0;
};

