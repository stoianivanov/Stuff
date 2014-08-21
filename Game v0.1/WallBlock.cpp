#include "WallBlock.h"
#include "ExtraStuff.h"

///
/// C-tor - �� ������� �������� �� �� ������������
/// �� c-tor-a �� Block, � ������� ����� �� ��-����� ������
///
WallBlock::WallBlock(char sign) : Block(WALL_GUI_CHAR)
{ }

///
/// ��������� �� ����� ����, ����������� ���
/// ������� �� ���� �� ���� ���� �������
///
bool WallBlock::activate(Game &)
{
	return false;
}

///
/// ������������ ������������, ����� ������� ��������
/// �� �������, �� ���� '#', � �� �������� �� ������������
///
void WallBlock::serialize(std::ofstream& output) const
{
	output.write(reinterpret_cast<const char*> (&WALL_ICON), sizeof(char));
}

WallBlock* WallBlock::clone() const
{
	return new WallBlock(*this);
}