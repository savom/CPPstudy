#pragma once
#include "Entity.h"
#include "Monster.h"
#include "Random.h"
using namespace std;

// - 주인공(고블린)
// 고블린
// - 체력
// - 이름
// - 공격력
// - 방어력
// - 공격()
// - 맞기() (대미지) - (방어력)만큼 피해를 입음.
// - 방어()
// - 돌 던지기()
class Monster;

class Goblin : public Entity
{
private:
	void ThrowAttack();


public :
	void Attack(Monster* monster);
public:
	Goblin(int hp, int atk, int def);
	

};

