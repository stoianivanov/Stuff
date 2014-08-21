#ifndef BACKPACK_H
#define BACKPACK_H

#include "Item.h"
#include "Gold.h"

class Character;

class Backpack
{
public:
	Backpack();
	Backpack(const Backpack &);
	Backpack& operator=(const Backpack &);
	~Backpack();

public:
	/// � �������� ��� ���� � ����
	Gold gold;

	bool isFull() const { return currentItems >= backpackSize; }
	bool addItem(const Item *);
	bool removeItem(const Item *);

	void use(Character &);
	void printWithAccentOn(int) const;

	bool serialize(std::ofstream &) const;
	bool deserialize(std::ifstream &);

private:
	/// ���������� ������ �� ��������
	static const int backpackSize = 5;
	/// ����� �� ��������� ��� ���������� � ��������
	Item** items;
	/// ���� �� �������� ��������
	int currentItems;

	void allocateItemsMemory();
	void copyFrom(const Backpack &);
	void free();
};


#endif /// BACKPACK_H INCLUDED
