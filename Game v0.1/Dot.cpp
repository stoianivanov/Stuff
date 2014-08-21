#include "Dot.h"

///
/// C-tor
///
Dot::Dot(int nX, int nY) : x(nX), y(nY)
{ }

///
/// Мутатор за точката
///
void Dot::setDot(const Dot& dot)
{
	x = dot.x;
	y = dot.y;
}

///
/// Сериализация
///
void Dot::write(std::ofstream& output) const
{
	output.write(reinterpret_cast<const char*> (&x), sizeof(int));
	output.write(reinterpret_cast<const char*> (&y), sizeof(int));
}

///
/// Десериализация
///
void Dot::read(std::ifstream& input)
{
	input.read(reinterpret_cast<char*> (&x), sizeof(int));
	input.read(reinterpret_cast<char*> (&y), sizeof(int));
}