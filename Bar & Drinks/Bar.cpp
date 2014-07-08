#include "Bar.h"

Bar::Bar() : currentDrink(0), capacity(50)
{
	drinks = new Drink[capacity];
}

Bar::~Bar()
{
	delete[] drinks;
}

bool Bar::addDrink(const Drink& rhs)
{
	/// Check for resize

	drinks[currentDrink] = rhs;
	++currentDrink;

	return true;
}

bool Bar::removeDrink(const Drink& rhs)
{
	for(int i=0; i <= currentDrink-1; ++i)
	{
		if(!strcmp(drinks[i].getName(), rhs.getName()))
		{
			for(int j = currentDrink-1; j > i; --j)
				drinks[j-1] = drinks[j];

			--currentDrink;
			return true;
		}
	}

	return false;
}

void Bar::sortByName()
{
	
	for(int i=0; i <= currentDrink-1; ++i)
	{
		for(int j = currentDrink-1; j > i; --j)
		{
				if(drinks[j-1] > drinks[j])
				{
					Drink tempDrink(drinks[j-1]);
					drinks[j-1] = drinks[j];
					drinks[j] = tempDrink;
				}
		}
	}
}

double Bar::getAveragePercentage() const
{
	double percentageSum = 0;

	for(int i=0; i <= currentDrink-1; ++i)
		percentageSum += drinks[i].getPercent();

	return percentageSum/(currentDrink-1);
}

const Drink& Bar::operator[](int position) const
{
	if(position < 0 || position >= currentDrink)
		throw std::out_of_range("Invalid index");

	return drinks[position];
}

Drink& Bar::operator[](int position)
{
	return const_cast<Drink &>(static_cast<const Bar &> (*this)[position]);
}