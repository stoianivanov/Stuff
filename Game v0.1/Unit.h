#ifndef UNIT_H
#define UNIT_H

#include "ExtraStuff.h"
#include "Dot.h"
#include <iostream>
#include <fstream>

class Unit
{
public:
	Unit();
	Unit(const Unit &);
	Unit& operator=(const Unit &);
	virtual ~Unit();

public:
	const char* getName() const { return pName; }
	Dot getLocation() const { return currentLocation; }
	void setName(const char*);
	void setCurrentLocation(const Dot &);

public:
	virtual void write(std::ofstream &) const;
	virtual void read(std::ifstream &);

protected:
	/// Статсове
	int hitPoints;
	int currentHitPoints;
	int attackPower;
	int defence;
	int level;
	int strength;
	int agility;
	int intellect;
	int manaPool;
	int currentManaPool;
	Dot currentLocation;

protected:
	void resize(int);
	void copyFrom(const Unit &);
	void allocateMemory(int);
	void free();

private:
	char* pName;
};

#endif /// UNIT_H INCLUDED
