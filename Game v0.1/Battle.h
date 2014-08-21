#ifndef BATTLE_H
#define BATTLE_H

class Creep;
class Character;

class Battle
{
public:
	Battle();

public:
	bool triggerCombat();

public:
	static bool getGameStatus() { return gameOver; }

	void setCharacter(Character& hero) { player = &hero; }
	void setCreep(Creep& creep) { foe = &creep; }
private:
	/// Държи указател към играчът и противника 
	/// за по-лесно извикване на функциите
	Character* player;
	Creep* foe;

	static bool gameOver;

	bool core(int);
	bool meleeFight();
	bool tryToKill(int);
	bool receiveAttack(int);
	bool creepDown();

	bool triggerGameOver();
	bool awardExperience();
	void printBattleHitPoints();
};

#endif // BATTLE_H INCLUDED
