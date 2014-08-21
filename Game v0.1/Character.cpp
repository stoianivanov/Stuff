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
/// ������������ Assignment operator
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
/// ����� ��������� �� ������������ �� �����
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
/// ������ ���� ������� �� ���� ����� � ����
///
void Character::copyFrom(const Character& other)
{
	experience = other.experience;
	neededExperience = other.neededExperience;
}

///
/// ������� ������� ��� �����
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
/// ��-������� ������� �� �����
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
/// ����� ������ �� ������ � 1 � ��������� ���������� ��
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
/// ����� ������ �� �����
///
void Character::calculateAttackPower()
{
	attackPower = 2*strength + 1*agility;
}

///
/// ����� ��������
///
void Character::calculateDefence()
{
	defence = (agility*3) / 2;
}

///
/// ����� ������
///
void Character::calculateManaPool()
{
	manaPool = 2*intellect;
}

///
/// �������� ������� �� ����������, ����� ����� �� �� �����
///
void Character::free()
{
	delete weapon;
	delete armor;
	delete shield;
}

///
/// ������������
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
/// ��������������
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
/// �������, ����� ������ ����
///
void Character::addExperience(int xp)
{
	std::cout << "You have been awarded " << xp << " experience points!\n";
	experience += xp;
	if(experience >= neededExperience)
		triggerLevelUp();
}

///
/// �������� �� ����� � ��������� �� ����������
///
void Character::print() const
{
	std::cout << "<" << getName() << ">" << std::endl
			  << "Level: " << level << std::endl
			  << "Health: " <<  currentHitPoints << " / " << hitPoints << std::endl
			  << "Mana: " << currentManaPool << " / " << manaPool << std::endl
			  << "Experience: " << experience << " / " << neededExperience << std::endl << std::endl;
}