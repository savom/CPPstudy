#pragma once
#include "Monster.h"

// 토끼
// - 체력
// - 공격력
// - 방어력
// - 공격()
// - 맞기() (대미지) - (방어력)만큼 피해를 입음.
// - 깨물기()
// - 도망치기() : 확률적으로 도망침!
// - 죽음()

class Rabbit : public Monster
{
public:
	virtual void Damage(int damage);
	void Attack(Goblin* goblin);

private:
	void Escape();
	void Bite();
	void Slam();
	
public:
	Rabbit(int hp, int atk, int def);
};

