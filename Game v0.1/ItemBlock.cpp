#include "ItemBlock.h"
#include "Game.h"

///
/// C-tor - ������ ���� �� ����� � ID �� ��������, ����� ��
/// ���������� �� ���������, �� �� �� ����������
///
ItemBlock::ItemBlock(char symbol, const char* fileToItem, int id) : Block(symbol), item(factory.createItem(id, fileToItem))
{ }

///
/// Copy C-tor
///
ItemBlock::ItemBlock(const ItemBlock& other) : Block(other)
{
	item = other.item->clone();
}

///
/// ������������ Assignment Operator
///
ItemBlock& ItemBlock::operator=(const ItemBlock& other)
{
	if(this != &other)
	{
		delete item;
		Block::operator=(other);
		item = other.item->clone();
	}

	return *this;
}

///
/// ~D-tor
///
ItemBlock::~ItemBlock()
{
	delete item;
}

///
/// ��� ��� ����� � ��������� �� ������,
/// �������� ��������� �������� �� � ����
///
bool ItemBlock::activate(Game& engine)
{
	if(engine.hero.inventory.isFull())
		return false;

	engine.hero.inventory.addItem(item);
	return true;
}

///
/// ������������� ������������, �� �� ������ �������
/// �� ��������, ����� � � ��������. ����������������
/// ����� ���� ����� ItemFactory � ���������������� �� 
/// �������
///
void ItemBlock::serialize(std::ofstream& output) const
{
	Block::serialize(output);
	::serialize(item, output);
}

ItemBlock* ItemBlock::clone() const
{
	return new ItemBlock(*this);
}