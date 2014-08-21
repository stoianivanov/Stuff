#include "ItemBlock.h"
#include "Game.h"

///
/// C-tor - приема пътя до файла и ID на предмета, които са
/// необходими на фабриката, за да го конструира
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
/// Предефиниран Assignment Operator
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
/// Ако има място в инвентара на играча,
/// блокчето прехвърля предмета си в него
///
bool ItemBlock::activate(Game& engine)
{
	if(engine.hero.inventory.isFull())
		return false;

	engine.hero.inventory.addItem(item);
	return true;
}

///
/// Предефинирана сериализация, за да запише данните
/// за предмета, който е в блокчето. Десериализацията
/// става чрез класа ItemFactory в десериализацията на 
/// картата
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