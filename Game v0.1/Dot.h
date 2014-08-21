#ifndef DOT_H
#define DOT_H

#include <fstream>

class Dot
{
public:
	Dot(int, int);

public:
	void setDot(const Dot &);

	int getX() const { return x; }
	int getY() const { return y; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

public:
	bool operator==(const Dot& other) const { return x == other.x && y == other.y; }

	void write(std::ofstream &) const;
	void read(std::ifstream &); 

private:
	int x;
	int y;
};

#endif /// DOT_H INCLUDED
