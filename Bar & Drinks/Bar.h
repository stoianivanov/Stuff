#ifndef BAR_H
#define BAR_H

#include "Drink.h"

class Bar
{
public:
	Bar();
	~Bar();

public:
	bool addDrink(const Drink &);
	bool removeDrink(const Drink &);
	void sortByName();

public:
	Drink& operator[](int);
	const Drink& operator[](int) const;

	double getAveragePercentage() const;

private:
	Bar(const Bar &);
	Bar& operator=(const Bar &);

private:
	Drink* drinks;
	int currentDrink;
	int capacity;
};


#endif // BAR_H INCLUDED
