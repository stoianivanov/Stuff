#include "MyString.h"
#include "DArray.hpp"

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

	arr.print(std::cout);

	return 0;
}