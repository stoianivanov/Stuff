#include "ItemFactory.h"
#include "ExtraStuff.h"
#include "Weapon.h"
#include "Shield.h"
#include "Armor.h"

///
/// Създава обект от тип Item* в зависимост ID-то му и го връща
///
Item* ItemFactory::createItem(int id, const char* fileToItem, bool equipped) const
{
	switch(id)
	{
	case WEAPON_ID:
		{
			return new Weapon(fileToItem, equipped);
		}
	case SHIELD_ID:
		{
			return new Shield(fileToItem, equipped);
		}
	case ARMOR_ID:
		{
			return new Armor(fileToItem, equipped);
		}
	default:
		{
			return NULL;
		}
	}
}