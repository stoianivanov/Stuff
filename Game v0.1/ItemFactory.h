#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

class Item;

class ItemFactory
{
public:
	Item* createItem(int, const char*, bool = false) const;
};


#endif // ITEMFACTORY_H INCLUDED
