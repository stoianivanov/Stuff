#include "DecimalToBinary.h"
#include <iostream>

DecimalToBinary::DecimalToBinary(char* numberToConvert) : NumberConverter(numberToConvert)
{
	std::cout << convert();
}

char* DecimalToBinary::convert()
{
	char* bin = new char[16];

	int numberToConvert = atoi(pNumberToConvert);
	int step = 0;

	for(; numberToConvert > 0; step++)
	{
		if(numberToConvert % 2 == 0)
			bin[step] = '0';
		else
			bin[step] = '1';

		numberToConvert /= 2;
	}
	
	bin[step] = '\0';
	int len = strlen(bin);
	char temp = 0;

	for(int i=0; i <= (len-1)/2; i++)
	{
		temp = bin[i];
		bin[i] = bin[len-1-i];
		bin[len-1-i] = temp;
	}

	return bin;
}

int main()
{
	DecimalToBinary converter("255");
	
}