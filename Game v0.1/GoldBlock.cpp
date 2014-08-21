#include "GoldBlock.h"
#include "Game.h"
#include <ctime>

///
/// C-tor - ���� ������ �������� �� ������� � ���� ��
/// 
GoldBlock::GoldBlock(char sign) : Block(sign)
{
	srand(time(NULL));
	gold.copper = rand() % 50;
	gold.silver = rand() % 20;
	gold.gold = rand() % 2;
}

///
/// ��������� ������� �� � ������� �� ������
///
bool GoldBlock::activate(Game& engine)
{
	engine.hero.inventory.gold += gold;

	return true;
}

GoldBlock* GoldBlock::clone() const
{
	return new GoldBlock(*this);
}