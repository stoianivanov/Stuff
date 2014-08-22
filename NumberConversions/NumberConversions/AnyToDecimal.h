#ifndef TODECIMAL_H
#define TODECIMAL_H

#include "NumberConverter.h"

class AnyToDecimal : public NumberConverter
{
public:
	AnyToDecimal(const char*, int);

private:
	virtual char* convert();
	int from;
};

#endif