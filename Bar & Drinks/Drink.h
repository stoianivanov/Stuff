#ifndef DRINK_H
#define DRINK_H

#include <iostream>

class Drink
{
public:
	Drink();
	Drink(const char*, int);
	Drink(const Drink &);
	Drink& operator=(const Drink &);
	~Drink();

public:
	const char* getName() const { return pName; }
	int getPercent() const { return percentAlcohol; }

public:
	bool operator>(const Drink &) const;
	bool operator<(const Drink &) const;
	friend std::istream& operator>>(std::istream &, Drink &);
	friend std::ostream& operator<<(std::ostream &, const Drink &);

private:
	char* pName;
	int percentAlcohol;

	void setName(const char*);
	void copyFrom(const Drink &);
	void free();
};


#endif // DRINK_H INCLUDED
