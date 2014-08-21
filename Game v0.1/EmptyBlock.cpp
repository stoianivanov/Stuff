#include "EmptyBlock.h"
#include "ExtraStuff.h"
#include "Game.h"

///
/// C-tor, ������ � � � �, �� �� ���� �� �������� ������
/// ��������������, �� �� ���� ������ ������ ����� �� ����
/// ������, ��� �� ���� �������� ����� ����
///
EmptyBlock::EmptyBlock(int x, int y, char sign) : Block(sign), location(x, y)
{ }

///
/// ������� ������ ����� �������� ������
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