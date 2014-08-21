#include "Map.h"
#include "ItemBlock.h"
#include <iostream>
#include <fstream>
#include "Character.h"

///
/// C-tor
///
Map::Map() : map(NULL)
{ }

///
/// ~D-tor
///
Map::~Map()
{
	free();
}

///
/// Създава блокчетата за предметите, извиква се от load
///
bool Map::createItemBlocks(std::ifstream& file)
{
	if(!file)
		throw FILE_ERROR;

	int x = 0;
	int y = 0;
	int id = 0;

	while(!file.eof())
	{
		file >> id;
		file >> x;
		file >> y;
		char buffer[BUFFER_SIZE];

		file >> buffer;
		map[x][y] = new ItemBlock(TREASURE_ICON, buffer, id);
	}
	return true;
}

///
/// Зарежда картата от файл, като зарежда всички  блокчета, 
/// които не са с предмети, а след това зарежда и тези с предметите
///
void Map::load(const char* fileName)
{
	std::ifstream source(fileName, std::ios::in);
	if(!source)
		throw FILE_ERROR;

	source.getline(mapName, 50);

	source >> rows;
	source >> columns;
	source.get();

	allocateMemory();

	char current;
	for(int i=0; i <= rows-1; ++i)
	{
		for(int j=0; j <= columns-1; ++j)
		{
			source.get(current);
			if(current == '\n' || source.eof())
				break;
			if(current == TREASURE_ICON)
				continue;

			map[i][j] = factory.createBlock(j, i, current);
		}
	}

	if(!source.eof())
		createItemBlocks(source);

	/// Vuv faila na kartata, broq na kolonite e zapisan + simvolite za nov red, za po-lesno chetene,
	/// zatova sega se popravq broikata
	--columns;
	source.close();
}

///
/// Заделя памет за масива от блокчета
///
void Map::allocateMemory()
{
	map = new Block**[rows];
	for(int i=0; i <= rows-1; ++i)
		map[i] = new Block*[columns];
}

///
/// Сериализация
///
bool Map::write(std::ofstream& output) const
{
	if(!output)
		throw FILE_ERROR;

	int size = strlen(mapName) + 1;
	output.write(reinterpret_cast<const char*> (&rows), sizeof(int));
	output.write(reinterpret_cast<const char*> (&columns), sizeof(int));
	output.write(reinterpret_cast<const char*> (&size), sizeof(int));
	output.write(mapName, sizeof(char)*size);


	for(int i=0; i<=rows-1; ++i)
		for(int j=0; j <= columns-1; ++j)
			map[i][j]->serialize(output);

	return true;
}

///
/// Десериализация
///
bool Map::read(std::ifstream& input)
{
	if(!input)
		throw FILE_ERROR;

	input.read(reinterpret_cast<char*> (&rows), sizeof(int));
	input.read(reinterpret_cast<char*> (&columns), sizeof(int));

	allocateMemory();

	char sign = 0;
	char buffer[BUFFER_SIZE];
	int size = 0;
	int typeBuffer = 0;
	bool equippedDummy = false;

	input.read(reinterpret_cast<char*> (&size), sizeof(int));
	input.read(buffer, sizeof(char)*size);
	strcpy(mapName, buffer);

	for(int i=0; i<=rows-1; ++i)
		for(int j=0; j <= columns-1; ++j)
		{
			input.read(reinterpret_cast<char *> (&sign), sizeof(char));
			if(sign == TREASURE_ICON)
			{
				input.read(reinterpret_cast<char*> (&typeBuffer), sizeof(int));
				input.read(reinterpret_cast<char*> (&equippedDummy), sizeof(bool));
				input.read(reinterpret_cast<char*> (&size), sizeof(int));
				input.read(buffer, sizeof(char)*size);

				map[i][j] = new ItemBlock(sign, buffer, typeBuffer);
				continue;
			}

			map[i][j] = factory.createBlock(j, i, sign);
			map[i][j]->deserialize(input);
		}

	return true;
}

///
/// Освобождава паметта, заета от картата
///
void Map::free()
{
	for(int i=0; i <= rows-1; ++i)
		for(int j=0; j <= columns-1; ++j)
			delete map[i][j];

	delete[] map;
}

///
/// Изпринтва картата на екрана
///
void Map::print() const
{
	std::cout << "-- <"<< mapName << "> --\n";

	for(int i=0; i <= rows-1; ++i)
	{
		for(int j=0; j <= columns-1; ++j)
			map[i][j]->print();

		std::cout << std::endl;
	}
}

Block* Map::operator[](const Dot& coords)
{
	return const_cast<Block *>(static_cast<const Map &> (*this)[coords]);
}

const Block* Map::operator[](const Dot& coords) const
{
	int x = coords.getX();
	int y = coords.getY();

	if(x < 0 || y < 0 || x > columns || y > rows)
		throw std::out_of_range("Invalid Dot coordinates");

	return map[y][x];
}

///
/// Претърсва текущата карта, за да намери къде е
/// местоположението на героя и го връща като Dot
///
Dot Map::getHeroLocation()
{
	for(int i=0; i <= rows-1; ++i)
	{
		for(int j=0; j <= columns-1; ++j)
		{
			if(map[i][j]->symbol == CHARACTER_ICON)
			{
				Dot heroLocation(j, i);
				return heroLocation;
			}
		}
	}
	
	return Dot(0, 0);
}