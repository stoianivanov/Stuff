#ifndef COCKTAIL_H
#define COCKTAIL_H

#include "Drink.h"

class Cocktail : public Drink
{
public:
	Cocktail(const char*, int, int);

public:
	int getTimesBought() const { return timesBought; }
	double createPrice(const Drink &);

private:
	int timesBought;
};


#endif // COCKTAIL_H INCLUDED
