#include "Armor.h"
#include "ExtraStuff.h"
#include <iostream>

///
/// C-tor
///
Armor::Armor(const char* filePath, bool isEquipped) : Item(filePath, ARMOR_ID, isEquipped)
{ 
	readItem(filePath);
}

///
/// �������������, �� �� ���� � ������ �� ����
///
bool Armor::readMe(std::ifstream& file)
{
	if(!file)
		throw FILE_ERROR;

	file >> hitPoints;

	return true;
}

///
/// �������������, �� �� ��������� ������
///
void Armor::printMe() const
{
	if(hitPoints)
		std::cout << "+ " << hitPoints << " Hit Points\n";
}

Armor* Armor::clone() const 
{
	return new Armor(*this);
}