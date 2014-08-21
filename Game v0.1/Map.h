#ifndef MAP_H
#define MAP_H

#include <fstream>
#include "BlockFactory.h"

class Map
{
public:
	Map();
	~Map();

public:
	const char* getName() const { return mapName; }
	Dot getHeroLocation();

public:
	Block* operator[](const Dot &);
	const Block* operator[](const Dot &) const;

	void load(const char*);
	bool write(std::ofstream &) const;
	bool read(std::ifstream &);
	void print() const;

private:
	Map(const Map &);
	Map& operator=(const Map &);

private:
	/// Двумерен масив от указатели към блокчета
	Block*** map;
	BlockFactory factory;
	int rows;
	int columns;

	char mapName[50];

	bool createItemBlocks(std::ifstream &);
	void allocateMemory();
	void free();

	friend class Game;
};

#endif // MAP_H INCLUDED
