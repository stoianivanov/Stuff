#ifndef DECIMAL_TO_OCTAL_H
#define DECIMAL_TO_OCTAL_H

#include "NumberConverter.h"

class DecimalToOctal : public NumberConverter
{
public:
	DecimalToOctal(const char*);

private:
	virtual char* convert();
};

#endif