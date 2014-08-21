#ifndef GOLD_H
#define GOLD_H

#include "Item.h"

class Gold
{
public:
	Gold(int = 0, int = 0, int = 0);

	Gold& operator+=(const Gold &);

public:
	bool serialize(std::ofstream &) const;
	bool deserialize(std::ifstream &);

	int gold;
	int silver;
	int copper;
};


#endif /// GOLD_H INCLUDED
