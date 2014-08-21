#include "Creep.h"
#include "Character.h"

///
/// Ctor - ������� �������� �� ������� ��� ��� ����
///
Creep::Creep(const char* filePath)
{
	std::ifstream creepFile(filePath, std::ios::in);
	if(!creepFile)
		throw FILE_ERROR;

	char buffer[1024];
	creepFile.getline(buffer, 1024);
	creepFile >> hitPoints;
	creepFile >> attackPower;
	creepFile >> defence;
	creepFile >> level;

	setName(buffer);
	currentHitPoints = hitPoints;

	creepFile.close();
}

///
/// ������������
///
void Creep::write(std::ofstream& output) const
{
	if(!output)
		throw FILE_ERROR;

	Unit::write(output);
}

///
/// ��������������
///
void Creep::read(std::ifstream& input)
{
	if(!input)
		throw FILE_ERROR;

	Unit::read(input);
}