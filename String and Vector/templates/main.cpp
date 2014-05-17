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
	void resize(unsigned);

	unsigned cap;

};

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

void MyString::resize(unsigned new_size)
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

template<class TYPE>

class DArray
{
public:
	DArray(int);
	~DArray();

public:
	void push(TYPE &);


private:
	TYPE* arr;

	void resize(unsigned);

	unsigned used_size;
	unsigned cap;
};

template<class TYPE>
DArray<TYPE>::DArray(int size)
{
	arr = new TYPE[size];

	cap = size;
	used_size = 0;
}

template<class TYPE>
DArray<TYPE>::~DArray()
{
	delete[] arr;
}

template<class TYPE>
void DArray<TYPE>::push(TYPE& element)
{
	if(used_size >= cap)
		resize(cap*2);

	arr[used_size] = element;
	++used_size;
}

template<class TYPE>
void DArray<TYPE>::resize(unsigned new_size)
{
	cap = new_size;

	TYPE* _arr = new TYPE[new_size];
	for(unsigned i=0; i <= used_size-1; ++i)
		_arr[i] = arr[i];

	delete[] arr;
	arr = _arr;
}

int main()
{
	std::cout << "CREATING DARRAY\n";
	DArray<MyString> arr(3);
	std::cout << "CREATING FIVE STRING MEMBERS!\n";
	MyString one, two, three, four, five;
	one = "hello";
	two = "world";
	three = "one";
	four = "five";
	five = "pro";


	arr.push(one);
	arr.push(two);
	arr.push(three);
	arr.push(four);
	arr.push(five);

	return 0;
}