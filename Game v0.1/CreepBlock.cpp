#include "CreepBlock.h"
#include "Game.h"

///
/// C-tor
///
CreepBlock::CreepBlock(char sign) : Block(sign), creep(factory.createCreep(sign))
{ }

///
/// D-tor
///
CreepBlock::~CreepBlock()
{
	delete creep;
}

///
/// ������� ����� � ���������� �� ��������� � �����
///
bool CreepBlock::activate(Game& engine)
{
	battle.setCharacter(engine.hero);
	battle.setCreep(*creep);
	battle.triggerCombat();

	return true;
}

CreepBlock* CreepBlock::clone() const
{
	return new CreepBlock(*this);
}