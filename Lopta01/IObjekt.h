#pragma once
class IObjekt
{
public:
	virtual void nakreslisa() = 0;
	virtual bool aktualizujsa(int cas) = 0;
	virtual bool zasah(int x, int y) = 0;
	virtual int dajBody() = 0;
};

