#include "AnyToDecimal.h"
#include "DecimalToBinary.h"
#include "DecimalToHex.h"
#include "DecimalToOctal.h"

int main()
{
	char dec[] = "255";

	DecimalToBinary a(dec);
	DecimalToHex b(dec);
	DecimalToOctal c(dec);

	AnyToDecimal d("FF", 16);
	AnyToDecimal e("11111111", 2);
	AnyToDecimal o("377", 8);

}