#ifndef CREEP_H
#define CREEP_H

#include "Unit.h"

class Creep : public Unit
{
public:
	Creep(const char*);

public:
	int getCurrentHitPoints() const { return currentHitPoints; }
	int getHitPoints() const { return hitPoints; }
	int getLevel() const { return level; }
	int getDefence() const { return defence; }
	int getAttackPower() const { return attackPower; }

	void setHitPoints(int hp) { hitPoints = hp; }
	void setCurrentHitPoints(int chp) { currentHitPoints = chp; } 

public:
	virtual void write(std::ofstream &) const;
	virtual void read(std::ifstream &);
};

#endif /// CREEP_H INCLUDED
