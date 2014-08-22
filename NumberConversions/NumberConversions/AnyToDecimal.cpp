#include "AnyToDecimal.h"
#include <iostream>

AnyToDecimal::AnyToDecimal(const char* numberToConvert, int fromWhichSystem) : NumberConverter(numberToConvert), from(fromWhichSystem)
{
	std::cout << convert() << std::endl;
}

char* AnyToDecimal::convert()
{
	int dec = 0;
	int len = strlen(pNumberToConvert);

	for(size_t i=0; i<=len-1; ++i)
	{
		switch(pNumberToConvert[len-1-i])
		{
		case 'A':
			{
				dec = dec + 10*(pow(from, i));
				break;
			}
		case 'B':
			{
				dec = dec + 11*(pow(from, i));
				break;
			}
		case 'C':
			{
				dec = dec + 12*(pow(from, i));
				break;
			}
		case 'D':
			{
				dec = dec + 13*(pow(from, i));
				break;
			}
		case 'E':
			{
				dec = dec + 14*(pow(from, i));
				break;
			}
		case 'F':
			{
				dec = dec + 15*(pow(from, i));
				break;
			}
		default:
			{
				dec = dec + (pNumberToConvert[len-1-i] - '0')*(pow(from, i));
				break;
			}
		}
	}

	itoa(dec, converted, 10);

	return converted;
}