#include "ExitBlock.h"
#include "Game.h"

///
/// C-tor
///
ExitBlock::ExitBlock(char sign) : Block(sign)
{ }

///
/// При опит за стъпване на това блокче се 
/// зарежда следващата карта от списъка
///
bool ExitBlock::activate(Game& engine)
{
	engine.loadNextMap();
	engine.hero.setCurrentLocation(engine.currentMap.getHeroLocation());

	return false;
}

ExitBlock* ExitBlock::clone() const
{
	return new ExitBlock(*this);
}