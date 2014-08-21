#include "Unit.h"

///
/// Default ctor - Нулира член данните
///
Unit::Unit() : currentLocation(0, 0), pName(NULL)
{
	level = 0;
	hitPoints = 0;
	currentHitPoints = 0;
	strength = 0;
	agility = 0;
	intellect = 0;
	defence = 0;
	attackPower = 0;
	manaPool = 0;
	currentManaPool = manaPool;
}

///
/// Copy ctor
///
Unit::Unit(const Unit& other) : currentLocation(0, 0)
{
	copyFrom(other);
}

///
/// Функция, копираща един обект в друг
///
void Unit::copyFrom(const Unit& other)
{
	setName(other.pName);

	currentLocation = other.currentLocation;
	level = (other.level);
	hitPoints = (other.hitPoints);
	currentHitPoints = (other.currentHitPoints);
	strength = (other.strength);
	agility = (other.agility);
	intellect = (other.intellect);
	defence = (other.defence);
	attackPower = (other.attackPower);
	manaPool = (other.manaPool);
	currentManaPool = (other.currentManaPool);
}

///
/// Предефиниран Assignment operator
///
Unit& Unit::operator=(const Unit& other)
{
	if(this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

///
/// ~Dtor
///
Unit::~Unit()
{
	std::cout << "Destructor on Unit " << this << std::endl;
	free();
}

///
/// Алокира памет за името по подаден размер
///
void Unit::allocateMemory(int size)
{
	pName = new char[size + 1];
}

///
/// Оразмерява името при подаден нов размер или ако не е подаден, удвоява размера 
///
void Unit::resize(int newSize = 0)
{
	char* newName = NULL;

	if(newSize)
		newName = new char[newSize + 1];
	else
		newName = new char[strlen(pName) * 2 + 1];

	strcpy(newName, pName);
	delete[] pName;
	pName = newName;
}

///
/// Изчиства паметта за името
///
void Unit::free()
{
	delete[] pName;
}

///
/// Сетва името по подадено ново име
///
void Unit::setName(const char* enteredName)
{
	free();
	allocateMemory(strlen(enteredName));

	strcpy(pName, enteredName);
}

///
/// Сериализация
///
void Unit::write(std::ofstream& output) const
{
	if(!output)
		throw FILE_ERROR;

	int nameSize = strlen(pName) + 1;

	output.write(reinterpret_cast<const char*> (&nameSize), sizeof(int));
	output.write(reinterpret_cast<const char*> (pName), sizeof(char)*nameSize);
	output.write(reinterpret_cast<const char*> (&hitPoints), sizeof(int));
	output.write(reinterpret_cast<const char*> (&currentHitPoints), sizeof(int));
	output.write(reinterpret_cast<const char*> (&attackPower), sizeof(int));
	output.write(reinterpret_cast<const char*> (&defence), sizeof(int));
	output.write(reinterpret_cast<const char*> (&level), sizeof(int));
	output.write(reinterpret_cast<const char*> (&strength), sizeof(int));
	output.write(reinterpret_cast<const char*> (&agility), sizeof(int));
	output.write(reinterpret_cast<const char*> (&intellect), sizeof(int));
	output.write(reinterpret_cast<const char*> (&manaPool), sizeof(int));
	output.write(reinterpret_cast<const char*> (&currentManaPool), sizeof(int));

	currentLocation.write(output);
}

///
/// Десериализация
///
void Unit::read(std::ifstream& input)
{
	if(!input)
		throw FILE_ERROR;

	int nameSize;
	input.read(reinterpret_cast<char*> (&nameSize), sizeof(int));

	char buffer[512];
	input.read(reinterpret_cast<char*> (buffer), sizeof(char)*nameSize);
	setName(buffer);
	
	input.read(reinterpret_cast<char*> (&hitPoints), sizeof(int));
	input.read(reinterpret_cast<char*> (&currentHitPoints), sizeof(int));
	input.read(reinterpret_cast<char*> (&attackPower), sizeof(int));
	input.read(reinterpret_cast<char*> (&defence), sizeof(int));
	input.read(reinterpret_cast<char*> (&level), sizeof(int));
	input.read(reinterpret_cast<char*> (&strength), sizeof(int));
	input.read(reinterpret_cast<char*> (&agility), sizeof(int));
	input.read(reinterpret_cast<char*> (&intellect), sizeof(int));
	input.read(reinterpret_cast<char*> (&manaPool), sizeof(int));
	input.read(reinterpret_cast<char*> (&currentManaPool), sizeof(int));

	currentLocation.read(input);
}

///
/// Сетва местоположението на обекта по друго от тип Dot
///
void Unit::setCurrentLocation(const Dot& coords)
{
	currentLocation = coords;
}