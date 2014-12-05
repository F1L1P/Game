#include <cstdlib>
#include "SDL.h"

#include "Plocha.h"

int Plocha::aCitac = 0;

Plocha::Plocha(int sirka, int vyska)
{
	if (aCitac == 0)
		SDL_Init(SDL_INIT_EVERYTHING);
	aCitac++;
	aPlocha = SDL_SetVideoMode(sirka, vyska, 32, SDL_SWSURFACE);
}


Plocha::~Plocha()
{
	if (aPlocha)
		SDL_FreeSurface(aPlocha);

	aCitac--;
	if (aCitac == 0)
		SDL_Quit();
}

int Plocha::sirka()
{
	return aPlocha->w;
}

int Plocha::vyska()
{
	return aPlocha->h;
}

IPlocha *Plocha::citajBMP(const char *menosuboru)
{
	SDL_Surface *gobjekt = SDL_LoadBMP(menosuboru);
	if (gobjekt)
		return new Plocha(gobjekt);
	return NULL;
}

void Plocha::nakresli(IPlocha *objekt, int x, int y)
{
	SDL_Rect zdroj, ciel;
	zdroj.x = zdroj.y = 0;
	zdroj.w = ciel.w = objekt->sirka();
	zdroj.h = ciel.h = objekt->vyska();
	ciel.x = x;
	ciel.y = y;
	SDL_BlitSurface((SDL_Surface *)objekt->plocha(), &zdroj, aPlocha, &ciel);
//	reset();
}

void Plocha::zobrazSkore(const char *text)
{
	SDL_WM_SetCaption(text, NULL);
}

bool Plocha::vstup(int &x, int &y)
{
	x = y = -1;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
				return false;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				x = event.button.x;
				y = event.button.y;
			}
			break;
		case SDL_QUIT:
			return false;
		}
	}
	return true;
}

int Plocha::dajCas()
{
	return SDL_GetTicks();
}

void Plocha::reset()
{
	SDL_UpdateRect(aPlocha, 0, 0, 0, 0);
}

void Plocha::vymaz()
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = sirka();
	rect.h = vyska();
	SDL_FillRect(aPlocha, &rect, SDL_MapRGB(aPlocha->format, 0, 0, 255));
//	reset();
}