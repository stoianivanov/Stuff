#ifndef DARRAY_H
#define DARRAY_H

template<class TYPE>

class DArray
{
public:
	DArray(int);
	~DArray();

public:
	void push(TYPE &);
	void print(std::ostream &);

public:
	TYPE& operator[](int);
	const TYPE& operator[](int) const;

private:
	TYPE* arr;

	void resize(int);

	int used_size;
	int cap;
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
void DArray<TYPE>::resize(int new_size)
{
	cap = new_size;

	TYPE* _arr = new TYPE[new_size];
	for(int i=0; i <= used_size-1; ++i)
		_arr[i] = arr[i];

	delete[] arr;
	arr = _arr;
}

template<typename TYPE>
void DArray<TYPE>::print(std::ostream& output)
{
	for(int i=0; i <= used_size - 1; ++i)
		output << arr[i];
}

template<typename TYPE>
const TYPE& DArray<TYPE>::operator[](int position) const
{
	if(position < 0 || position > used_size)
		throw std::out_of_range("Invalid index");

	return arr[position];
}

template<typename TYPE>
TYPE& DArray<TYPE>::operator[](int position)
{
	return const_cast<TYPE &>(static_cast<const DArray &> (*this)[position]);
}


#endif // DARRAY_H INCLUDED
