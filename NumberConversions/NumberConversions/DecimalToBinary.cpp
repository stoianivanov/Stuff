#include "DecimalToBinary.h"
#include <iostream>

DecimalToBinary::DecimalToBinary(const char* numberToConvert) : NumberConverter(numberToConvert)
{
	std::cout << convert() << std::endl;
}

char* DecimalToBinary::convert()
{
	int numberToConvert = atoi(pNumberToConvert);
	int step = 0;

	for(; numberToConvert > 0; ++step)
	{
		if(numberToConvert % 2 == 0)
			converted[step] = '0';
		else
			converted[step] = '1';

		numberToConvert /= 2;
	}
	
	converted[step] = '\0';
	int len = strlen(converted);
	char temp = 0;

	for(int i=0; i <= (len-1)/2; ++i)
	{
		temp = converted[i];
		converted[i] = converted[len-1-i];
		converted[len-1-i] = temp;
	}

	return converted;
}