#include "FountainBlock.h"
#include "Game.h"

///
/// C-tor
///
FountainBlock::FountainBlock(char sign) : Block(sign), used(false)
{ }

///
/// Когато играчът стъпи на блокчето, кръвта и маната му
/// се пълнят до край. Този ефект е еднократен
///
bool FountainBlock::activate(Game& engine)
{
	if(!used)
	{
		std::cout << "The magical waters of " << engine.currentMap.getName() << " replenish "
				  << engine.hero.getName() << "'s powers .. \n" << std::endl;

		engine.hero.currentHitPoints = engine.hero.hitPoints;
		engine.hero.currentManaPool = engine.hero.manaPool;

		used = true;
	}
	else
		std::cout << "The fountain is empty.." << std::endl;

	return false;
}

///
/// Предефинирана сериализация, за да запише състоянието
/// на фонтана (използван, неизползван)
///
void FountainBlock::serialize(std::ofstream& output) const
{
	Block::serialize(output);
	output.write(reinterpret_cast<const char*> (&used), sizeof(bool));
}

///
/// Предефинирана десериализация, за да прочете състоянието
/// на фонтана
///
void FountainBlock::deserialize(std::ifstream& input)
{
	Block::deserialize(input);
	input.read(reinterpret_cast<char*> (&used), sizeof(bool));
}

FountainBlock* FountainBlock::clone() const
{
	return new FountainBlock(*this);
}