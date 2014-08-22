#include "DecimalToOctal.h"
#include <iostream>

DecimalToOctal::DecimalToOctal(const char* numberToConvert) : NumberConverter(numberToConvert)
{
	std::cout << convert() << std::endl;
}

char* DecimalToOctal::convert()
{
	int numberToConvert = atoi(pNumberToConvert);

	int step = 0;

	for(; numberToConvert > 0; ++step)
	{
		converted[step] = numberToConvert % 8 + '0';
		numberToConvert /= 8;
	}

	converted[step] = '\0';

	int len = strlen(converted);
	char temp = 0;

	for(int i=0; i<=(len-1)/2; ++i)
	{
		temp = converted[i];
		converted[i] = converted[len-i-1];
		converted[len-i-1] = temp;
	}

	return converted;
}