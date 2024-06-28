#include "Goblin.h"

void Goblin::Attack(Monster* monster)
{
	// 60% 확률로 주먹 공격
	// 40% 확률로 던지기 공격
	// Random::Range([최소 값], [최대 값])
	// : [최소 값] 이상 ~ [최대 값] 이하의 랜덤한 실수 반환.
	bool activateSkill = Random::Range(0.0f, 1.0f) < 0.4f;
	int damage = atk;
	if (activateSkill) // 40% 확률로 돌 던지기가 발동되면
	{
		damage *= 1.5f;
		ThrowAttack();
	}
	else
	{
		cout << name << " 은(는) 주먹으로 공격했다!" << endl;
	}
	monster->Damage(damage);

}

void Goblin::ThrowAttack()
{
	cout << name << "은(는) 돌을 던졌다!" << endl;
}

Goblin::Goblin(int hp, int atk, int def)
	: Entity("고블린", hp, atk, def)
{

}
