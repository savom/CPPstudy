#pragma once
#include "Entity.h"
#include "Goblin.h"

class Goblin;

class Monster : public Entity
{
public:
	virtual void Attack(Goblin* goblin) = 0;

public:
	Monster(const char* name, int hp, int atk, int def);
};

