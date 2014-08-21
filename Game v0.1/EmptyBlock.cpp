#include "EmptyBlock.h"
#include "ExtraStuff.h"
#include "Game.h"

///
/// C-tor, приема и х и у, за да може да определи своето
/// местоположение, за да може когато героят стъпи на това
/// блокче, той да бъде поставен върху него
///
EmptyBlock::EmptyBlock(int x, int y, char sign) : Block(sign), location(x, y)
{ }

///
/// Поставя героят върху текущото блокче
///
bool EmptyBlock::activate(Game& engine)
{
	symbol = CHARACTER_ICON;

	engine.currentMap[engine.hero.getLocation()]->symbol = EMPTY_ICON;
	engine.hero.setCurrentLocation(location);

	return false;
}

EmptyBlock* EmptyBlock::clone() const
{
	return new EmptyBlock(*this);
}