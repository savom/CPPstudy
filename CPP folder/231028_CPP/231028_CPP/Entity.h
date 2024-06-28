#pragma once
#include <iostream>
using namespace std;
#include "Random.h"

class Entity
{
protected:
	char* name;
	int hp;
	int maxHp;
	int def;
	int atk;

public:
	
	virtual void Damage(int damage);
	void Defend();

public:
	Entity(const char* name, int hp, int atk, int def);
	~Entity();
};

