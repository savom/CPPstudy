#include "Entity.h"

void Entity::Damage(int damage)
{
	float defParam = def * 0.01f;
	if (defParam > 0.5f) // 최대 50%는 넘어가지 않도록 설정.
		defParam = 0.5f;
	bool defendSuccess = Random::Range(0.0f, 1.0f) < 0.1f + defParam;
	if (defendSuccess)
	{
		damage *= 0.1f; // 방어에 성공하면 대미지의 10%만 받음.
		Defend();
	}
	cout << name << "은(는) "<< damage
		<< "만큼의 대미지를 입었다." << endl;
	hp -= damage;
	cout << "남은 체력: " << hp << "/" << maxHp << endl;
}

void Entity::Defend()
{
	cout <<name <<"은(는) 방어에 성공했다!" << endl;
}

Entity::Entity(const char* name, int hp, int atk, int def)
	:hp(hp),maxHp(hp),atk(atk),def(def)
{
	int length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

Entity::~Entity()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}
