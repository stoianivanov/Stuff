#ifndef SHIELD_H
#define SHIELD_H

#include "Item.h"

class Shield : public Item
{
public:
	Shield(const char*, bool);

	virtual Shield* clone() const;

	virtual bool readMe(std::ifstream &);
	virtual void printMe() const;
	virtual int getStat() const { return defence; }

private:
	/// Държи бонус защитата
	int defence;
};


#endif /// SHIELD_H INCLUDED
