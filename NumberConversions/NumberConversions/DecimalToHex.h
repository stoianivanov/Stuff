#ifndef DEC_TO_HEX
#define DEC_TO_HEX

#include "NumberConverter.h"

class DecimalToHex : public NumberConverter
{
public:
	DecimalToHex(const char*);

private:
	virtual char* convert();
};

#endif