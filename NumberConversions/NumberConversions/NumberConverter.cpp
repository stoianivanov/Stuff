#include "NumberConverter.h"
#include <iostream>

NumberConverter::NumberConverter(char* numberString) : pNumberToConvert(NULL)
{
	pNumberToConvert = new char[strlen(numberString) + 1];
	strcpy(pNumberToConvert, numberString);
}

NumberConverter::~NumberConverter()
{
	delete[] pNumberToConvert;
}