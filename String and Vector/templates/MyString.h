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
	static const int DEFAULT_SIZE = 128;
	bool find(const char*);
	bool find(const MyString &);

	const char* getData() const { return data; }
	char* getData() { return data; }

public:
	MyString& operator=(const MyString &);
	MyString& operator=(const char*);
	bool operator==(const MyString &) const;
	bool operator==(const char*) const;
	MyString& operator+=(const char);
	MyString& operator+=(const char*);
	char& operator[](int);
	const char& operator[](int) const;
	friend std::ostream& operator<<(std::ostream &, const MyString &);


private:
	char* data;

	void allocate();
	void copyFrom(const MyString &);
	void free();
	void resize(int);

	int cap;

};

#endif // MYSTRING_H INCLUDED
