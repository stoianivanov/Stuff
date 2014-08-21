#ifndef FROM_DECIMAL_H
#define FROM_DECIMAL_H

class NumberConverter
{
public:
	NumberConverter(char*);
	~NumberConverter();
		
protected:
	virtual char* convert() = 0;
	char* pNumberToConvert;
};

#endif