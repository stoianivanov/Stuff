#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

class Armor : public Item
{
public:
	Armor(const char*, bool);

public:
	virtual int getStat() const { return hitPoints; }
	virtual void printMe() const;
	virtual Armor* clone() const;

private:
	/// Държи бонус кръвта
	int hitPoints;

	virtual bool readMe(std::ifstream &);
};


#endif /// ARMOR_H INCLUDED
