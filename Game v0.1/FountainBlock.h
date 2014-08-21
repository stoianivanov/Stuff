#ifndef FOUNTAINBLOCK_H
#define FOUNTAINBLOCK_H

#include "Block.h"

class FountainBlock : public Block
{
public:
	FountainBlock(char);
	
	virtual bool activate(Game &);
	virtual FountainBlock* clone() const;

	virtual void serialize(std::ofstream &) const;
	virtual void deserialize(std::ifstream &);
private:
	bool used;
};


#endif /// FOUNTAINBLOCK_H INCLUDED
