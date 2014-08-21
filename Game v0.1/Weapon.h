#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(const char*, bool);

public:
	int getAttackPower() { return attackPower; }

	virtual Weapon* clone() const;
	virtual void printMe() const;
	virtual int getStat() const { return attackPower; }

private:
	/// Оръжието носи бонус атакуваща сила
	int attackPower;

	virtual bool readMe(std::ifstream &);
};


#endif /// WEAPON_H INCLUDED
