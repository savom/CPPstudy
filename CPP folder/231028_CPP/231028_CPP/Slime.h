#pragma once
#include "Monster.h"

// 슬라임
// - 체력
// - 공격력
// - 방어력
// - 공격()
// - 죽음()
// - 튀어오르기() 
// - 맞기() (대미지) - (방어력)만큼 피해를 입음.

class Slime : public Monster
{

public:
	void Attack(Goblin* goblin);
	void Bounce();
	
public:
	Slime(int hp, int atk, int def);
};