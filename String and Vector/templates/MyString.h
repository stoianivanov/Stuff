#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
public:
	MyString();
	MyString(const MyString &);
	~MyString();

public:
	static const int DEFAULT_SIZE = 5;

public:
	MyString& operator=(const MyString &);
	MyString& operator=(const char*);
	friend std::ostream& operator<<(std::ostream &, const MyString &);


private:
	char* data;

	void allocate();
	void copyFrom(const MyString &);
	void free();
	void resize(int);

	int cap;

};

#endif