#pragma once
#include "IPlocha.h"

class LoptaEngine;
class Lopta;
class LoptaHra
{
private:
	IPlocha *aHraciaPlocha;
	LoptaEngine *aEngine;
public:
	LoptaHra();
	~LoptaHra();
	void run();
};

