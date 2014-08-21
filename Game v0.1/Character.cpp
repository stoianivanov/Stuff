#include "Character.h"
#include <conio.h>
#include <iomanip>

///
/// Default ctor
///
Character::Character() : weapon(NULL), armor(NULL), shield(NULL)
{
	setDefaultValues();
}

///
/// Copy ctor
///
Character::Character(const Character& other) : Unit(other), weapon(NULL), armor(NULL), shield(NULL)
{
	copyFrom(other);
}

///
/// Предефиниран Assignment operator
///
Character& Character::operator=(const Character& other)
{
	if(this != &other)
	{
		free();
		Unit::operator=(other);
		copyFrom(other);
	}

	return *this;
}

///
/// D-tor
///
Character::~Character()
{
	free();
}


///
/// Сетва стойности по подразбиране на герой
///
void Character::setDefaultValues()
{
	level = 1;
	experience = 0;
	neededExperience = 40*level;
	hitPoints = 30;
	currentHitPoints = hitPoints;
	strength = 5;
	agility = 4;
	intellect = 4;

	calculateAttackPower();
	calculateDefence();
	calculateManaPool();
	currentManaPool = manaPool;
}

///
/// Копира член данните от един обект в друг
///
void Character::copyFrom(const Character& other)
{
	experience = other.experience;
	neededExperience = other.neededExperience;
}

///
/// Екипира предмет към героя
///
bool Character::equipItem(Item*& item)
{
	if(item->equipped)
		return false;
	item->equipped = true;
	switch(item->type)
	{
	case WEAPON_ID:
		{
			if(weapon)
				unEquipItem(weapon);
			weapon = item;
			attackPower += item->getStat();
			break;
		}
	case SHIELD_ID:
		{
			if(shield)
				unEquipItem(shield);
			shield = item;
			defence += item->getStat();
			break;
		}
	case ARMOR_ID:
		{
			if(armor)
				unEquipItem(armor);
			armor = item;
			hitPoints += item->getStat();
			currentHitPoints += item->getStat();
		}
	}

	return true;
}

///
/// Де-екипира предмет от героя
///
bool Character::unEquipItem(Item*& item)
{
	if(!item->equipped)
		return false;

	item->equipped = false;
	switch(item->type)
	{
	case WEAPON_ID:
		{
			attackPower -= item->getStat();
			weapon = NULL;
			break;
		}
	case SHIELD_ID:
		{
			defence -= item->getStat();
			shield = NULL;
			break;
		}
	case ARMOR_ID:
		{
			hitPoints -= item->getStat();
			currentHitPoints -= item->getStat();
			armor = NULL;
		}
	}

	return true;
}

///
/// Вдига нивото на играча с 1 и увеличава статсовете му
///
void Character::triggerLevelUp()
{
	level = (level + 1);
	hitPoints = (hitPoints + hitPoints/10);
	currentHitPoints = (hitPoints);
	strength += 2;
	agility += 3;
	defence = (defence + 1);
	intellect += 3;
	neededExperience *= 2;

	calculateAttackPower();
	calculateDefence();
	calculateManaPool();
	currentManaPool = (manaPool);

	std::cout << "<" << getName() << "> has reached level " << level << "!\n";
}

///
/// Смята силата за атака
///
void Character::calculateAttackPower()
{
	attackPower = 2*strength + 1*agility;
}

///
/// Смята защитата
///
void Character::calculateDefence()
{
	defence = (agility*3) / 2;
}

///
/// Смята маната
///
void Character::calculateManaPool()
{
	manaPool = 2*intellect;
}

///
/// Изчиства паметта за предметите, които могат да се носят
///
void Character::free()
{
	delete weapon;
	delete armor;
	delete shield;
}

///
/// Сериализация
///
void Character::write(std::ofstream& output) const
{
	if(!output)
		throw FILE_ERROR;

	Unit::write(output);
	output.write(reinterpret_cast<const char*> (&experience), sizeof(int));
	output.write(reinterpret_cast<const char*> (&neededExperience), sizeof(int));
	inventory.serialize(output);
	serialize(weapon, output);
	serialize(armor, output);
	serialize(shield, output);
}

///
/// Десериализация
///
void Character::read(std::ifstream& input)
{
	if(!input)
		throw FILE_ERROR;

	Unit::read(input);
	input.read(reinterpret_cast<char*> (&experience), sizeof(int));
	input.read(reinterpret_cast<char*> (&neededExperience), sizeof(int));
	inventory.deserialize(input);

	deserialize(weapon, input);
	deserialize(armor, input);
	deserialize(shield, input);
}

///
/// Функция, която добавя опит
///
void Character::addExperience(int xp)
{
	std::cout << "You have been awarded " << xp << " experience points!\n";
	experience += xp;
	if(experience >= neededExperience)
		triggerLevelUp();
}

///
/// Принтене на героя и основните му статистики
///
void Character::print() const
{
	std::cout << "<" << getName() << ">" << std::endl
			  << "Level: " << level << std::endl
			  << "Health: " <<  currentHitPoints << " / " << hitPoints << std::endl
			  << "Mana: " << currentManaPool << " / " << manaPool << std::endl
			  << "Experience: " << experience << " / " << neededExperience << std::endl << std::endl;
}