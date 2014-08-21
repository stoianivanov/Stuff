#include "Game.h"
#include "EmptyBlock.h"
#include "Battle.h"
#include <conio.h>
#include <ctime>

bool Game::exists = false;
Game* Game::object = NULL;

///
/// Създава обект от класа
///
Game* Game::getInstance()
{
	if(!exists)
	{
		object = new Game();
		exists = true;
	}

	return object;
}

///
/// C-tor - стартира играта
///
Game::Game() : currentMapNumber(0)
{
	loadMapNames();

	play();
}

///
/// ~D-tor
///
Game::~Game()
{
	delete object;
	exists = false;
}

///
/// Зарежда имената на картите в масива mapFileNames
///
void Game::loadMapNames()
{
	std::ifstream input("maps.ini", std::ios::in);
	char buffer[12];

	for(int i=0; i <= DEFAULT_MAP_COUNT-1; ++i)
	{
		if(input.eof())
			throw MAP_COUNT_ERROR;

		input.getline(buffer, 12);
		strcpy(mapsFileNames[i], buffer);
	}
	input.close();
}

///
/// Приготвя обекта за нова игра
///
void Game::initNewGame()
{
	char buffer[DEFAULT_NAME_SIZE];
	std::cout << "Enter a name for your character: \n";
	std::cin.sync();
	std::cin.getline(buffer, DEFAULT_NAME_SIZE);
	hero.setName(buffer);

	popUpMenu("Use the [W] [A] [S] [D] keys to move.\nPress H if you need help!\n");

	currentMap.load(mapsFileNames[currentMapNumber]);
	hero.setCurrentLocation(currentMap.getHeroLocation());
}

///
/// Решава какво да се случи като се натисне копче
///
void Game::activateKey(char key)
{
	switch(key)
	{
	case MOVE_FORWARD:
		{
			moveTo(MOVE_FORWARD, 1, 0);
			break;
		}
	case MOVE_LEFT:
		{		
			moveTo(MOVE_LEFT, 0, -1);
			break;
		}
	case MOVE_BACKWARDS:
		{
			moveTo(MOVE_BACKWARDS, -1, 0);
			break;
		}
	case MOVE_RIGHT:
		{
			moveTo(MOVE_RIGHT, 0, 1);
			break;
		}
	case HELP_KEY: 
		{
			printHelp();
			break;
		}
		
	case BACKPACK_KEY:
		{
			hero.inventory.use(hero);
			break;
		}
	case SAVE_KEY:
		{
			std::cout << "Do you want to save the data?\n";
			char a;
			std::cin >> a;
			if(a == 'y')
			{
				char filename[_MAX_PATH];
				std::cout << "Enter file name: \n";
				std::cin >> filename;
				save(filename);
				clearScreen();
			}
		}
	default : break;
	}
}

///
/// Придвижва героя
///
void Game::moveTo(const char choice, int x, int y)
{
	Dot location(hero.getLocation().getX() + x, hero.getLocation().getY() + y);

	clearScreen();

	if(currentMap.map[location.getY()][location.getX()]->activate(*this))
	{

		delete currentMap.map[location.getY()][location.getX()];
		currentMap.map[location.getY()][location.getX()] = new EmptyBlock(location.getX(), location.getY(), EMPTY_ICON);
	}
}

///
/// Главната функция, която контролира играта
///
int Game::play()
{
	std::cout << "Welcome to HEROES OF THE FALLEN EARTH\nDo you want to:\n1) Start a new game 2) Load from file\n";
	int c;

	do
	{
		std::cin.clear();
		std::cin.sync();
		std::cin >> c;
	}
	while(!std::cin || c < 1 || c > 2);

	if(c == 1)
		initNewGame();
	else
	{
		char buffer[_MAX_PATH];
		std::cin >> buffer;
		load(buffer);
	}

	char key;
	while(!Battle::getGameStatus())
	{
		hero.print();
		currentMap.print();

		key = _getch();
		activateKey(key);
	}

		
	return 0;
}

///
/// Зарежда следващата карта от списъка
///
void Game::loadNextMap()
{
	if(currentMapNumber+1 >= DEFAULT_MAP_COUNT)
		return;
	currentMap.free();
	++currentMapNumber;
	currentMap.load(mapsFileNames[currentMapNumber]);
	currentMap.getHeroLocation();
}

///
/// Сериализация
///
bool Game::save(const char* filePath)
{
	try
	{
		std::ofstream output(filePath, std::ios::out | std::ios::binary);
		if(!output)
			throw FILE_ERROR;

		hero.write(output);

		output.write(reinterpret_cast<const char*> (&currentMapNumber), sizeof(int));
		currentMap.write(output);

		output.flush();
		int checkSum = getCheckSum(filePath);

		output.write(reinterpret_cast<const char*> (&checkSum), sizeof(int));
		output.close();
	}
	catch(const char*)
	{
		std::cerr << "Error 0003! Couldn't open file";
	}
	return true;
}

///
/// Десериализация
///
bool Game::load(const char* filePath)
{
	try
	{
		std::ifstream input(filePath, std::ios::in | std::ios::binary);
		if(!input)
			throw FILE_ERROR;

		hero.read(input);
		input.read(reinterpret_cast<char*> (&currentMapNumber), sizeof(int));
		currentMap.read(input);

		int writtenCheckSum = 0;
		input.read(reinterpret_cast<char*> (&writtenCheckSum), sizeof(int));
		int realCheckSum = getCheckSum(filePath, true);
		if(realCheckSum != writtenCheckSum)
			throw FATAL_ERROR;

		input.close();
	}
	catch(const char* str)
	{
		if(!strcmp(str, FILE_ERROR))
			std::cerr << "Error 0003! Couldn't open file";
		else
			throw;
	}

	return true;
}

///
/// Help меню
/// 
void Game::printHelp() const
{
	popUpMenu("Help Menu:\n[W][A][S][D] - Movement keys\n[B] - Backpack\n[0] - save game");
}

///
/// Функция, която извлича CheckSum за даден файл
///
int Game::getCheckSum(const char* filePath, bool reading)
{
	std::ifstream file(filePath, std::ios::binary);
	if(!file)
		throw FILE_ERROR;

	file.seekg(0, std::ios::end);
	int size = file.tellg();
	file.seekg(0, std::ios::beg);
	if(reading)
		size -= 4;

	char* bytes = new char[size+1];
	file.read(bytes, sizeof(char)*size);

	int checksum = 0;
	for(int i=0; i <= size-1; ++i)
		if(bytes[i])
			checksum *= bytes[i];

	file.close();
	delete[] bytes;
	return checksum;
}