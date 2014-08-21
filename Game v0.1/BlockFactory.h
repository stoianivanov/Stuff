#ifndef BLOCKFACTORY_H
#define BLOCKFACTORY_H

#include "Block.h"

class BlockFactory
{
public:
	Block* createBlock(int, int, char) const;
};


#endif /// BLOCKFACTORY_H INCLUDED
