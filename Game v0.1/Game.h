#ifndef GAME_H
#define GAME_H

/// -----------------------------HEROES OF THE FALLEN EARTH v0.1 --------------------------------
/// ----------------------------------------------------------------------------------------------
///	COMPILED AND BUILT ON 
///					WINDOWS 8.1 ENTERPRISE (x86) // VISUAL STUDIO ULTIMATE 2012
///-----------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------


#include "Character.h"
#include "Map.h"

class Game
{
public:
	static Game* getInstance();
	~Game();

	Character hero;
	Map currentMap;
	void loadNextMap();

private:
	/// Game е синглетон
	Game();
	static Game* object;
	static bool exists;

private:
	/// Държи текущия номер на картата
	int currentMapNumber;
	static const int DEFAULT_MAP_COUNT = 5;

private:
	/// Масив от стрингове, в който се пазят имената на картите
	char mapsFileNames[DEFAULT_MAP_COUNT][DEFAULT_NAME_SIZE];
	int play();
	int getCheckSum(const char*, bool = false); 
	void loadMapNames();
	void initNewGame();
	void activateKey(char);
	void moveTo(char, int, int);

	bool save(const char*);
	bool load(const char*);

	void printUI() const;
	void printHelp() const;

};

#endif /// GAME_H INCLUDED
