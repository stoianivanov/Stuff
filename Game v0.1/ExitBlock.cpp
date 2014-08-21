#include "ExitBlock.h"
#include "Game.h"

///
/// C-tor
///
ExitBlock::ExitBlock(char sign) : Block(sign)
{ }

///
/// ��� ���� �� �������� �� ���� ������ �� 
/// ������� ���������� ����� �� �������
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