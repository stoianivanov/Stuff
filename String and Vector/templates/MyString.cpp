#include "MyString.h"

MyString::MyString()
{
	std::cout << "STR CONSTR @ " << this << std::endl;
	allocate();
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if(this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MyString& MyString::operator=(const char* source)
{
	if(cap <= strlen(source))
		resize(strlen(source));

	strcpy(data, source);

	return *this;
}

MyString::~MyString()
{
	std::cout << "DESTRUCTOR @ " << this << std::endl;
	free();
}

void MyString::allocate()
{
	cap = DEFAULT_SIZE;
	data = new char[cap];
}

void MyString::copyFrom(const MyString& other)
{
	std::cout << "COPY CONSTR @ " << this << std::endl;
	allocate();

	if(strlen(other.data) >= cap)
		resize(strlen(other.data));

	strcpy(data, other.data);
}

void MyString::resize(int new_size)
{
	cap = new_size*2;
	char* _data = new char[cap];
	strcpy(_data, data);

	delete[] data;
	data = _data;
}

void MyString::free()
{
	delete[] data;
}

std::ostream& operator<<(std::ostream& output_stream, const MyString& str)
{
	output_stream << str.data;
	return output_stream;
}