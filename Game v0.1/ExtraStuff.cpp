#include <iostream>
#include <conio.h>
#include "ExtraStuff.h"

void clearScreen()
{
	system("cls");
}

void popUpMenu(const char* string)
{
	clearScreen();
	std::cout << string;
	pressAnyKey();
}

void pressAnyKey()
{
	_getch();
	clearScreen();
}