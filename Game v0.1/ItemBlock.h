#ifndef ITEMBLOCK_H
#define ITEMBLOCK_H

#include "Block.h"
#include "ItemFactory.h"

class Item;

class ItemBlock : public Block
{
public:
	ItemBlock(char, const char*, int);
	ItemBlock(const ItemBlock &);
	ItemBlock& operator=(const ItemBlock &);
	~ItemBlock();

public:
	virtual bool activate(Game &);
	virtual ItemBlock* clone() const;
	virtual void serialize(std::ofstream &) const;

private:
	/// Държи указател към предмет
	Item* item;
	ItemFactory factory;
};

#endif // ITEMBLOCK_H INCLUDED
