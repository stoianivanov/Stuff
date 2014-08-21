#include "Game.h"
#include "Weapon.h"

int main()
{
	try
	{
		Game* first = Game::getInstance();
	}
	catch(const char* str)
	{
		if(!strcmp(str, "wrong amount of maps"))
			std::cout << "Error 0001! Please restart the game!\n\a";
		if(!strcmp(str, FILE_ERROR))
			std::cout << "Error 0002! Couldn't open map file";
		if(!strcmp(str, FATAL_ERROR))
			std::cout << "Error 0004! Save file is corrupted!\n\a";
	}
	catch(std::bad_alloc &)
	{
		std::cout << "Not enough memory to complete this operation!\a\n";
	}
	catch(...)
	{
		std::cout << "Unexpected error occured!\a\n";
	}

	return 0;
}