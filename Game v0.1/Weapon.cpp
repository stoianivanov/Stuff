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
/// �������������, �� �� ���� � ����������� ���� �� ����
/// 
bool Weapon::readMe(std::ifstream& file)
{
	if(!file)
		throw FILE_ERROR;

	file >> attackPower;
	return true;
}

///
/// �������������, �� �� ��������� ����������� ����
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