#ifndef BLOCK_H
#define BLOCK_H

#include "Dot.h"

class Game;

class Block
{
public:
	Block(char);

	char symbol;

	/// �������, ����� �������� ��������, ������ �������
	/// �� ����� �� ����� ����� ����. ����� ������, ��� ��������
	/// ������ �� ���� ��������� ���� ���������� ��� ����, ��� �� ������
	virtual bool activate(Game &) = 0;

	virtual Block* clone() const = 0;
	virtual void serialize(std::ofstream &) const;
	virtual void deserialize(std::ifstream &);

	void print() const;
};


#endif /// BLOCK_H INCLUDED
