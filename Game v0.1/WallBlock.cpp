#include "WallBlock.h"
#include "ExtraStuff.h"

///
/// C-tor - не предава иконката си по подразбиране
/// на c-tor-a на Block, а предава друга за по-хубав дизайн
///
WallBlock::WallBlock(char sign) : Block(WALL_GUI_CHAR)
{ }

///
/// Функцията не прави нищо, симулирайки как
/// играчът не може да мине през стената
///
bool WallBlock::activate(Game &)
{
	return false;
}

///
/// Предефнирана сериализация, която записва иконката
/// на стената, но като '#', а не иконката по подразбиране
///
void WallBlock::serialize(std::ofstream& output) const
{
	output.write(reinterpret_cast<const char*> (&WALL_ICON), sizeof(char));
}

WallBlock* WallBlock::clone() const
{
	return new WallBlock(*this);
}