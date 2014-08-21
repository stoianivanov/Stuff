#include "BlockFactory.h"
#include "ExtraStuff.h"
#include "EmptyBlock.h"
#include "WallBlock.h"
#include "CreepBlock.h"
#include "ExitBlock.h"
#include "FountainBlock.h"
#include "GoldBlock.h"

///
/// Създава обект от тип Block* в зависимост от знакът и го връща
///
Block* BlockFactory::createBlock(int x, int y, char sign) const
{
	switch(sign)
	{
	case EMPTY_ICON:
		{
			return new EmptyBlock(x, y, sign);
		}
	case WALL_GUI_CHAR:
	case WALL_ICON:
		{
			return new WallBlock(sign);
		}
	case EXIT_ICON:
		{
			return new ExitBlock(sign);
		}
	case FOUNTAIN_ICON:
		{
			return new FountainBlock(sign);
		}
	case GOLD_ICON:
		{
			return new GoldBlock(sign);
		}
	case TROLL_ICON:
	case ORC_ICON:
	case HIGH_ELF_ICON:
	case ILLIDARI_ICON:
		{
			return new CreepBlock(sign);
		}
	default:
		{
			return new EmptyBlock(x, y, sign);
		}
	}
}