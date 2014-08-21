#include "Gold.h"
#include "ExtraStuff.h"

///
/// C-tor
///
Gold::Gold(int g, int s,int c) : gold(g), silver(s), copper(c)
{ }

///
/// Предефиниран += за удобство
///
Gold& Gold::operator+=(const Gold& other)
{
	this->copper += other.copper;
	this->silver += other.silver;
	this->gold += other.gold;

	return *this;
}

///
/// Сериализация
///
bool Gold::serialize(std::ofstream& output) const
{
	if(!output)
		throw FILE_ERROR;

	output.write(reinterpret_cast<const char*> (&copper), sizeof(int));
	output.write(reinterpret_cast<const char*> (&silver), sizeof(int));
	output.write(reinterpret_cast<const char*> (&gold), sizeof(int));

	return true;
}

///
/// Десериализация
///
bool Gold::deserialize(std::ifstream& input)
{
	if(!input)
		throw FILE_ERROR;

	input.read(reinterpret_cast<char*> (&copper), sizeof(int));
	input.read(reinterpret_cast<char*> (&silver), sizeof(int));
	input.read(reinterpret_cast<char*> (&gold), sizeof(int));

	return true;
}