#pragma once
class IEngine
{
public:
	virtual void start() = 0;
	virtual void zobrazSkore() = 0;
	virtual bool vstup(int &x, int &y) = 0;
	virtual int dajCas() = 0;
	virtual void reset() = 0;
	virtual void vymaz() = 0;
};

