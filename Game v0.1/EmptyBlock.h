#ifndef EMPTYBLOCK_H
#define EMPTYBLOCK_H

#include "Block.h"

class EmptyBlock : public Block
{
public:
	EmptyBlock(int, int, char);
	
	virtual bool activate(Game &);
	virtual EmptyBlock* clone() const;

private:
	Dot location;

};


#endif /// EMPTYBLOCK_H INCLUDED
