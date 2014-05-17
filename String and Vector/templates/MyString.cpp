#include "MyString.h"

MyString::MyString()
{
	std::cout << "STR CONSTR @ " << this << std::endl;
	cap = DEFAULT_SIZE;
	data = NULL;
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
	if(strlen(source) >= cap)
		resize(strlen(source));
	else
		allocate();

	strcpy(data, source);

	return *this;
}

bool MyString::operator==(const MyString& other) const
{
	return data == other.data;
}

bool MyString::operator==(const char* source) const
{
	return !strcmp(data, source);
}

MyString& MyString::operator+=(const char c)
{
	if(strlen(data) + 1 >= cap)
		resize(strlen(data) + 2);

	data[strlen(data)] = c;
	data[strlen(data) + 1] = '\0';

	return *this;
}

MyString& MyString::operator+=(const char* source)
{
	if(strlen(data) + strlen(source) >= cap)
		resize(strlen(data) + strlen(source) + 1);

	strcat(data, source);

	return *this;
}



char& MyString::operator[](int position)
{
	return const_cast<char &>(static_cast<const MyString &> (*this)[position]);
}

const char& MyString::operator[](int position) const
{
	if(position < 0 || position > cap)
		throw std::out_of_range("Invalid index");

	return data[position];
}


MyString::~MyString()
{
	std::cout << "DESTRUCTOR @ " << this << std::endl;
	free();
}

void MyString::allocate()
{
	data = new char[cap];
}

void MyString::copyFrom(const MyString& other)
{
	std::cout << "COPY CONSTR @ " << this << std::endl;

	if(strlen(other.data) >= cap)
		resize(strlen(other.data));
	else
		allocate();

	strcpy(data, other.data);
}

void MyString::resize(int new_size)
{
	cap = new_size*2;
	char* _data = new char[cap];
	if(data)
	{
		strcpy(_data, data);
		delete[] data;
	}

	data = _data;
}

bool MyString::find(const char* source)
{
	return strstr(data, source);
}

bool MyString::find(const MyString& other)
{
	return (*this).find(other.data);
}

void MyString::free()
{
	delete[] data;
	data = NULL;
}

std::ostream& operator<<(std::ostream& output_stream, const MyString& str)
{
	output_stream << str.data;
	return output_stream;
}