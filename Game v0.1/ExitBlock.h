#ifndef EXITBLOCK_H
#define EXITBLOCK_H

#include "Block.h"

class ExitBlock : public Block
{
public:
	ExitBlock(char);
	
	virtual bool activate(Game &);
	virtual ExitBlock* clone() const;

};


#endif /// EXITBLOCK_H INCLUDED
