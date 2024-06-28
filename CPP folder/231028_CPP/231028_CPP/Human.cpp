#include "Human.h"

void Human::Attack(Goblin* goblin)
{
	bool activateSkill = Random::Range(0.0f, 1.0f) < 0.4f;
	int damage = atk;
	if (activateSkill) // 40%
	{
		damage *= 1.5f;
		Kick();
	}
	else
	{
		Punch();
	}
	goblin->Damage(damage);
}



void Human::Kick()
{
	cout << name << "은(는) 헥토파스칼 킥을 시전했다!" << endl;
}

void Human::Punch()
{
	cout << name << "은(는) 주먹공격을 시전했다!" << endl;
}

Human::Human(int hp, int atk, int def)
	:Monster("인간", hp, atk, def)
{
}
