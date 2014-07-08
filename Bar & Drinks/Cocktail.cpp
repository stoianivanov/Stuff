#include "Cocktail.h"

Cocktail::Cocktail(const char* name, int percent, int times) : Drink(name, percent), timesBought(times)
{ }

double Cocktail::createPrice(const Drink& rhs)
{
	if(rhs.getPercent() > 40)
		return 50.0;
	if(rhs.getPercent() < 3)
		return 2.0;

	return rhs.getPercent() * 1.2;
}