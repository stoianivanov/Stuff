#include "Shield.h"
#include "ExtraStuff.h"
#include  <iostream>

///
/// C-tor
///
Shield::Shield(const char* fileToItem, bool isEquipped) : Item(fileToItem, SHIELD_ID, isEquipped)
{
	readItem(fileToItem);
}

///
/// �������������, �� �� ���� � �������� �� ����
/// 
bool Shield::readMe(std::ifstream& file)
{
	if(!file)
		throw FILE_ERROR;

	file >> defence;
	return true;
}

///
/// �������������, �� �� ��������� ��������
///
void Shield::printMe() const
{
	if(defence)
		std::cout << "+ " << defence << " Defence\n";
}

Shield* Shield::clone() const
{
	return new Shield(*this);
}