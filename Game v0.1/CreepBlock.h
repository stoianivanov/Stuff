#ifndef CREEPBLOCK_H
#define CREEPBLOCK_H

#include "Block.h"
#include "CreepFactory.h"
#include "Battle.h"

class Creep;

class CreepBlock : public Block
{
public:
	CreepBlock(char);
	~CreepBlock();
	
	virtual bool activate(Game &);
	virtual CreepBlock* clone() const;

private:
	CreepBlock(const Creep &);
	CreepBlock& operator=(const Creep &);
	/// Класът държи указател към чудовище
	Creep* creep;
	CreepFactory factory;

	Battle battle;

};


#endif /// CREEPBLOCK_H INCLUDED
