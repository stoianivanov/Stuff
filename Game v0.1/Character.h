#ifndef CHARACTER_H
#define CHARACTER_H

#include "Creep.h"
#include "Backpack.h"
#include "Shield.h"
#include "Armor.h"
#include "Weapon.h"

class Character : public Unit
{
public:
	Character();
	~Character();

public:
	Backpack inventory;

public:
	bool equipItem(Item *&);
	bool unEquipItem(Item *&);
	void addExperience(int);
	void print() const;

	virtual void write(std::ofstream &) const;
	virtual void read(std::ifstream &);

private:
	Character(const Character &);
	Character& operator=(const Character &);

	Item* weapon;
	Item* armor;
	Item* shield;

	// Stats variables	
	int experience;
	int neededExperience;

private:
	void triggerLevelUp();
	void calculateAttackPower();
	void calculateDefence();
	void calculateManaPool();
	void setDefaultValues();
	void copyFrom(const Character &);
	void free();

	friend class FountainBlock;
	friend class Battle;
};

#endif /// CHARACTER_H INCLUDED
