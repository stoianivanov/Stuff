#ifndef WALLBLOCK_H
#define WALLBLOCK_H

#include "Block.h"

class WallBlock : public Block
{
public:
	WallBlock(char);
	
	virtual bool activate(Game &);
	virtual WallBlock* clone() const;

	virtual void serialize(std::ofstream &) const;
};


#endif /// WALLBLOCK_H INCLUDED
