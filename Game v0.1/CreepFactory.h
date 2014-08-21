#ifndef CREEPFACTORY_H
#define CREEPFACTORY_H

class Creep;

class CreepFactory
{
public:
	Creep* createCreep(char) const;
};

#endif /// CREEPFACTORY_H INCLUDED
