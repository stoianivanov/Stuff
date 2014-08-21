#include "Item.h"
#include "ExtraStuff.h"
#include "ItemFactory.h"
#include <iostream>

///
/// C-tor - приема път до файла на предмета, номер на ID-то
/// и дали е екипиран (в случай на десериализация)
///
Item::Item(const char* filePath, int id, bool isEquipped) : pName(NULL), pSource(NULL), type(id), equipped(isEquipped)
{
	setString(pSource, filePath);
}

///
/// Copy c-tor
///
Item::Item(const Item& other) : pName(NULL), pSource(NULL)
{
	copyFrom(other);
}

///
/// Предефиниран Assignment operator
///
Item& Item::operator=(const Item& other)
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
Item::~Item()
{
	free();
}

///
/// Чете предмет от файл, вика виртулната функция
/// readMe, която е предефинирана с наследниците
///
bool Item::readItem(const char* fileToItem)
{
	std::ifstream file(fileToItem, std::ios::in);
	if(!fileToItem)
		throw FILE_ERROR;

	char buffer[BUFFER_SIZE];
	file.getline(buffer, BUFFER_SIZE);
	setString(pName, buffer);

	readMe(file);

	file.close();
	return true;
}

///
/// Сетва стринг по даден нов
///
void Item::setString(char*& dest, const char* newString)
{
	delete[] dest;
	dest = new char[strlen(newString) + 1];

	strcpy(dest, newString);
}

///
/// Копира член данните на един обект в друг
///
void Item::copyFrom(const Item& other)
{
	setString(pName, other.pName);
	setString(pSource, other.pSource);
	type = other.type;
	equipped = other.equipped;
}

///
/// Изчиства паметта за името на предмета и 
/// пътя до файла
///
void Item::free()
{
	delete[] pName;
	delete[] pSource;
}

///
/// Оператор за сравнение, връща истина, ако
/// имената на предметите са едни и същи
/// 
bool Item::operator==(const Item& other)
{
	return !strcmp(pName, other.pName);
}

///
/// Принтира предмета, извиква виртуалната
/// printMe, която трябва да бъде предефинирана
///
void Item::print() const 
{
	std::cout << "[" << pName << "] ";
	printMe();
}

///
/// Сериализация
///
bool serialize(const Item* item, std::ofstream& output)
{
	if(!output)
		throw FILE_ERROR;
	if(!item)
	{
		int errType = 0;
		output.write(reinterpret_cast<const char*> (&errType), sizeof(int));
		return true;
	}

	output.write(reinterpret_cast<const char*> (&item->type), sizeof(int));
	output.write(reinterpret_cast<const char*> (&item->equipped), sizeof(bool));

	int size = strlen(item->getSource()) + 1;
	output.write(reinterpret_cast<const char*> (&size), sizeof(int));
	output.write(item->getSource(), sizeof(char)*size);
	return true;
}

///
/// Десериализация
///
bool deserialize(Item*& item, std::ifstream& input)
{
	int typeBuffer = 0;
	input.read(reinterpret_cast<char*> (&typeBuffer), sizeof(int));
	if(!typeBuffer)
		return true;

	int fileNameSize = 0;
	bool equipped = false;
	char sign = 0;
	char buffer[BUFFER_SIZE];

	ItemFactory factory;
	input.read(reinterpret_cast<char*> (&equipped), sizeof(bool));
	input.read(reinterpret_cast<char*> (&fileNameSize), sizeof(int));
	input.read(buffer, sizeof(char)*fileNameSize);
	item = factory.createItem(typeBuffer, buffer, equipped);

	return item;
}