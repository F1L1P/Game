#pragma once
#include <cstdlib>
#include "IEngine.h"
#include "PohyblivyObjekt.h"

class Engine : public IEngine
{
protected:
	int aSkore;
	PohyblivyObjekt *aObjekt;
public:
	Engine(PohyblivyObjekt *objekt = NULL);
	~Engine();

	virtual void start();
	virtual void spracujVstup(int x, int y);
	virtual void aktualizujsa();
};

