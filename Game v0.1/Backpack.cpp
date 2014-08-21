#include "Backpack.h"
#include <iostream>
#include <conio.h>
#include "Character.h"
#include "ItemFactory.h"
#include "Item.h"

///
/// C-tor
///
Backpack::Backpack() : currentItems(0)
{
	allocateItemsMemory();
}

///
/// Copy C-tor
///
Backpack::Backpack(const Backpack& other)
{
	copyFrom(other);
}

///
/// Предефиниран Assignment operator
///
Backpack& Backpack::operator=(const Backpack& other)
{
	if(this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

///
/// ~D-tor
///
Backpack::~Backpack()
{
	free();
}

///
/// Създава масива от указатели с размер на раницата
///
void Backpack::allocateItemsMemory()
{
	items = new Item*[backpackSize];
}

///
/// Копира член данните на един обект от тип раница в друг
///
void Backpack::copyFrom(const Backpack& other)
{
	allocateItemsMemory();
	currentItems = other.currentItems;
	gold = other.gold;

	for(int i=0; i <= currentItems-1; ++i)
		*items[i] = *other.items[i]->clone();
}

///
/// Освобождава заетата памет от предметите
///
void Backpack::free()
{
	for(int i=0; i <= currentItems-1; ++i)
		delete items[i];

	delete[] items;
}

///
/// Добавя предмет в раницата
///
bool Backpack::addItem(const Item* newItem)
{
	if(currentItems >= backpackSize)
		return false;

	return items[currentItems++] = newItem->clone();
}

///
/// Премахва предмет от раницата
///
bool Backpack::removeItem(const Item* item)
{
	for(int i=0; i <= currentItems-1; ++i)
	{
		if(*items[i] == *item)
		{
			delete items[i];
			for(int j=currentItems-1; j > i; --j)
				items[j-1] = items[j];

			--currentItems;
			return true;
		}
	}

	return false;
}

///
/// Принтира раницата, като селектира със стрелка предметът
/// с подаден номер като аргумент
/// 
void Backpack::printWithAccentOn(int selectedItem) const
{
	std::cout << "Backpack:" << std::endl;
	for(int i=0; i <= currentItems-1; ++i)
	{
		if(!items[i])
			continue;
		if(i == selectedItem)
			std::cout << "-> ";
		if(items[i]->equipped)
			std::cout << "[Equipped] - ";
		items[i]->print();
	}
	std::cout << "\nGold: " << gold.gold << ", Silver: " << gold.silver << ", Copper: " << gold.copper
			  << "\n\n\n\n[W] - Move up\n[S] - Move Down\n[E] - Equip item]\n[U] - Unequip item\n[R] - Leave Backpack";
}

///
/// Функция, която принтира цялата инвентория и взема 
/// действия, в зависимост от натиснатото копче
///
void Backpack::use(Character& hero)
{
	clearScreen();

	int itemNumber = 0;
	char selected = 0;
	while(true)
	{
		printWithAccentOn(itemNumber);
		selected = _getch();
		switch(selected)
		{
		case MOVE_BACKWARDS: 
			{
				if(itemNumber < currentItems-1) 
					printWithAccentOn(++itemNumber);
				break;
			}
		case MOVE_FORWARD:
			{
				if(itemNumber > 0) 
					printWithAccentOn(--itemNumber);
				break;
			}
		case EQUIP_KEY:
			{
				hero.equipItem(items[itemNumber]);
				break;
			}
		case UNEQUIP_KEY:
			{
				hero.unEquipItem(items[itemNumber]);
				break;
			}
		case 'r':
			{
				clearScreen();
				return;
			}
		default: break;
		}
		clearScreen();
	}
}

///
/// Сериализация
///
bool Backpack::serialize(std::ofstream& output) const
{
	if(!output)
		throw FILE_ERROR;

	output.write(reinterpret_cast<const char*> (&currentItems), sizeof(int));
	gold.serialize(output);

	for(int i=0; i <= currentItems-1; ++i)
		::serialize(items[i], output);

	return true;
}

///
/// Десериализация
///
bool Backpack::deserialize(std::ifstream& input)
{
	if(!input)
		throw FILE_ERROR;

	input.read(reinterpret_cast<char*> (&currentItems), sizeof(int));
	gold.deserialize(input);

	for(int i=0; i <= currentItems-1; ++i)
		::deserialize(items[i], input);

	return true;
}