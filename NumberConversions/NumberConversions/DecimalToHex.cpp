#include "DecimalToHex.h"
#include <iostream>

DecimalToHex::DecimalToHex(const char* numberToConvert) : NumberConverter(numberToConvert)
{
	std::cout << convert() << std::endl;
}

char* DecimalToHex::convert()
{
	int leftover = 0;
	int step = 0;

	int numberToConvert = atoi(pNumberToConvert);

	for(; numberToConvert > 0; ++step)
	{
		leftover = numberToConvert % 16;
		numberToConvert /= 16;

		switch(leftover)
		{
		case 10: 
			{ 
				converted[step] = 'A';
				break; 
			}
		case 11:
			{
				converted[step] = 'B';
				break;
			}
		case 12:
			{
				converted[step] = 'C';
				break;
			}
		case 13:
			{
				converted[step] = 'D';
				break;
			}
		case 14:
			{
				converted[step] = 'E';
				break;
			}
		case 15:
			{
				converted[step] = 'F';
				break;
			}
		default:
			{
				converted[step] = (char)(leftover + '0');
				break;
			}
		}
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