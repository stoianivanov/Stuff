#include "Weapon.h"
#include "ExtraStuff.h"
#include <iostream>
#include "Character.h"

///
/// C-tor
///
Weapon::Weapon(const char* filePath, bool isEquipped) : Item(filePath, WEAPON_ID, isEquipped)
{
	readItem(filePath);
}

///
/// Предефинирана, за да чете в атакуващата сила от файл
/// 
bool Weapon::readMe(std::ifstream& file)
{
	if(!file)
		throw FILE_ERROR;

	file >> attackPower;
	return true;
}

///
/// Предефинирана, за да изпринтва атакуващата сила
///
void Weapon::printMe() const
{
	if(attackPower)
		std::cout << "+ " << attackPower << " Attack Power\n";
}

Weapon* Weapon::clone() const
{
	return new Weapon(*this);
}