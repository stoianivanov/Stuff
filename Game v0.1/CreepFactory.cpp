#include "CreepFactory.h"
#include "Creep.h"
#include "ExtraStuff.h"

///
/// ������� ����� �� ��� Creep* � ���������� �� ������� � �� �����
///
Creep* CreepFactory::createCreep(char symbol) const
{
	switch(symbol)
	{
	case TROLL_ICON:
		{
			return new Creep("creeps/WinterTroll.ini");
		}
	case ORC_ICON:
		{
			return new Creep("creeps/OrcWarlord.ini");
		}
	case HIGH_ELF_ICON:
		{
			return new Creep("creeps/Highelf.ini");
		}
	case ILLIDARI_ICON:
		{
			return new Creep("creeps/Illidari.ini");
		}
	default:
		{
			return NULL;
		}
	}
}