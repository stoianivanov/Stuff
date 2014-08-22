#ifndef FROM_DECIMAL_H
#define FROM_DECIMAL_H

class NumberConverter
{
public:
	NumberConverter(const char*);
	virtual ~NumberConverter();
		
protected:
	virtual char* convert() = 0;
	char* pNumberToConvert;
	char converted[16];
};

#endif