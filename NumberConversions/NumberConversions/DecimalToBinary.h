#ifndef DECTOBIN
#define DECTOBIN

#include "NumberConverter.h"

class DecimalToBinary : public NumberConverter
{
public:
	DecimalToBinary(const char*);

private:
	virtual char* convert();
};

#endif