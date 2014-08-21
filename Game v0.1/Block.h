#ifndef BLOCK_H
#define BLOCK_H

#include "Dot.h"

class Game;

class Block
{
public:
	Block(char);

	char symbol;

	/// Функция, която активира блокчето, когато играчът
	/// се опита да стъпи върху него. Връща истина, ако блокчето
	/// трябва да бъде унищожено след използване или лъжа, ако не трябва
	virtual bool activate(Game &) = 0;

	virtual Block* clone() const = 0;
	virtual void serialize(std::ofstream &) const;
	virtual void deserialize(std::ifstream &);

	void print() const;
};


#endif /// BLOCK_H INCLUDED
