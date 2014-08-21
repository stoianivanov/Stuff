#include "Battle.h"
#include "Character.h"
#include "Creep.h"
#include "ExtraStuff.h"
#include <conio.h>

bool Battle::gameOver = false;

Battle::Battle()
{ }

///
/// �������, ����� �������� ������� �� ����� � �������� �� ��� Creep
///
bool Battle::triggerCombat()
{
	std::cout << "-- A wild " << foe->getName() << " appeared --";

	char choice;
	while(true)
	{
		printBattleHitPoints();

		std::cout << "\nWhat does " << player->getName() << " want to do?"
			  << "\nA) Fight " << std::endl;

		std::cin >> choice;

		while(!std::cin || (choice != 'A' && choice != 'B'))
		{
			std::cin.clear();
			std::cin >> choice;
		}

		if(choice == 'A')
		{
			if(meleeFight())
				return true;
		}
	}
}

///
/// ����� �� ������ ���������
///
bool Battle::meleeFight()
{
	std::cout << "\n" << player->getName() << " swings his sword and ..\n";
	return core(player->attackPower);
}

///
/// ���� ������� ����� ���������� ����� � ����� �� ���� (experience)
///
bool Battle::awardExperience()
{
	std::cout << "<" << player->getName() << "> is awarded " 
			  << static_cast<int>(player->neededExperience / 2.6)
			  << " experience points!" << std::endl;

	player->experience += player->neededExperience / 2.6;
	if(player->experience >= player->neededExperience)
		player->triggerLevelUp();

	std::cout << "Press any key to continue..\n";

	pressAnyKey();

	return true;
}

///
/// ������� ����� ��� ����������, ��� ������ �� ����� ��� 0 ����� ������
/// (�.� ������� � ����� ����������)
///
bool Battle::tryToKill(int damageDone)
{
	foe->setCurrentHitPoints(foe->getCurrentHitPoints() - damageDone);
	std::cout << "<" << foe->getName() << "> gets hit for " << damageDone << " damage!\n";

	if(foe->getCurrentHitPoints() <= 0)
		return true;

	return false;
}

///
/// �������� ����� �� ��������, ��� ������ �� ����� ����� ��� 0 ����� ������
/// (�.� ������� ������� � �������� ������)
///
bool Battle::receiveAttack(int damageTaken)
{
	player->currentHitPoints -= damageTaken;
	std::cout << "\n<" << player->getName() << "> gets hit for " << damageTaken << " damage!\n";

	if(player->currentHitPoints <= 0)
		return true;

	return false;
}

///
/// �������� ��, ������ ������ ����, ������ ������ �� (� ������, �� � ������� �����������),
/// ��������� ������ � ���������� ������ � ����
///
bool Battle::creepDown()
{
	foe->setCurrentHitPoints(0);
	printBattleHitPoints();
	std::cout << "\n\n<" << player->getName() << "> has defeated " << "<" << foe->getName() << ">\n\n";
	return awardExperience();
}

///
/// ������ �� �������
///
bool Battle::core(int attackPoints)
{
	int damageDone;
	int damageTaken;

	damageDone = attackPoints - foe->getDefence();
	damageTaken = foe->getAttackPower() - player->defence;

	if(player->level >= foe->getLevel())
	{
		if(tryToKill( damageDone))
			return creepDown();

		if(receiveAttack(damageTaken))
			return triggerGameOver();

		pressAnyKey();
		return false;
	}
	
	
	if(receiveAttack(damageTaken))
		return triggerGameOver();

	if(tryToKill(damageDone))
		return creepDown();

	pressAnyKey();
	return false;
}

///
/// ������ ������� ����� �� ����� � �� ����������
///
void Battle::printBattleHitPoints()
{
	std::cout << "\n<" << player->getName() << ">'s HP: " << player->currentHitPoints
		      << "/" << player->hitPoints << " // <" << foe->getName() << ">'s HP: " << foe->getCurrentHitPoints()
			  << "/" << foe->getHitPoints() << "\n";
}

///
/// ����������� �� ������
///
bool Battle::triggerGameOver()
{
	gameOver = true;
	return true;
}