#include "Drink.h"

Drink::Drink() : pName(NULL), percentAlcohol(-1)
{ }

Drink::Drink(const char* newName, int percent) : pName(NULL), percentAlcohol(percent)
{
	setName(newName);
}

Drink::Drink(const Drink& rhs) : pName(NULL)
{
	copyFrom(rhs);
}

Drink& Drink::operator=(const Drink& rhs)
{
	if(this != &rhs)
	{
		free();
		copyFrom(rhs);
	}

	return *this;
}

Drink::~Drink()
{
	free();
}

void Drink::setName(const char* newName)
{
	free();
	pName = new char[strlen(newName) + 1];
	strcpy(pName, newName);
}

void Drink::free()
{
	delete[] pName;
}

void Drink::copyFrom(const Drink& rhs)
{
	setName(rhs.pName);
	percentAlcohol = rhs.percentAlcohol;
}

bool Drink::operator>(const Drink& rhs)
{
	return strcmp(pName, rhs.pName) < 0;
}

bool Drink::operator<(const Drink& rhs)
{
	return strcmp(pName, rhs.pName) > 0;
}

std::istream& operator>>(std::istream& stream, Drink& rhs)
{
	std::cout << "Enter drink name: ";

	char buffer[1024];
	stream.getline(buffer, 1024);
	rhs.setName(buffer);

	std::cout << "\nEnter percentage: ";
	stream >> rhs.percentAlcohol;

	return stream;
}

std::ostream& operator<<(std::ostream& stream, const Drink& rhs)
{
	stream << "Drink name: " << rhs.pName << std::endl
			  << "Percentage Alcohol: " << rhs.percentAlcohol
			  << std::endl;

	return stream;
}