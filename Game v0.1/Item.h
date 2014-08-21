#ifndef ITEM_H
#define ITEM_H

#include "Dot.h"

class Character;

class Item
{
public:
	Item(const char*, int, bool);
	Item(const Item &);
	Item& operator=(const Item &);
	virtual ~Item();

public:
	const char* getSource() const { return pSource; }
	const char* getName() const { return pName; }

	bool operator==(const Item &);

public:
	/// Тип на предмета - 1 за Оръжие, 2 за броня, 3 за щит -> погледни ExtraStuff.h
	int type;
	/// Държи статуса дали предметът е екипиран или не
	bool equipped;

	bool readItem(const char*);
	void print() const;

	/// Функцията връща стойността на атрибута,
	/// който е увеличен от предмета
	virtual int getStat() const = 0;
	virtual Item* clone() const = 0;

protected:
	virtual bool readMe(std::ifstream &) = 0;
	virtual void printMe() const = 0;

private:
	/// Държи името на предмета
	char* pName;
	/// Държи името на файла към предмета
	char* pSource;

	void setString(char*&, const char*);
	void copyFrom(const Item &);
	void free();
};

bool serialize(const Item*, std::ofstream &);
bool deserialize(Item *&, std::ifstream &);

#endif // ITEM_H INCLUDED
