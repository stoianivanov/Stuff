#include "Block.h"
#include "ExtraStuff.h"
#include <iostream>

///
/// C-tor
///
Block::Block(char sign) : symbol(sign)
{ }

///
/// ������ ������� �� �������� ������ (���������)
///
void Block::print() const
{
	std::cout << symbol;
}

///
/// ������������ (���������)
///
void Block::serialize(std::ofstream& output) const
{
	if(!output)
		throw FILE_ERROR;

	output.write(reinterpret_cast<const char*> (&symbol), sizeof(char));
}

///
/// �������������� (���������)
///
void Block::deserialize(std::ifstream& input)
{
	if(!input)
		throw FILE_ERROR;
}