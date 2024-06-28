#pragma once
#include "Monster.h"


// 인간
// - 체력
// - 공격력
// - 방어력
// - 공격()
// - 방어()
// - 발차기()
// - 죽음()
// - 맞기() (대미지) - (방어력)만큼 피해를 입음.

class Human : public Monster
{
public:
	void Attack(Goblin* goblin);
	
public:
	
	void Kick();
	void Punch();

public:
	Human(int hp, int atk, int def);
};

