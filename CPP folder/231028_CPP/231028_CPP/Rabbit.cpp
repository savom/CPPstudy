#include "Rabbit.h"



void Rabbit::Attack(Goblin* goblin)
{
	bool activateSkill = Random::Range(0.0f, 1.0f) < 0.4f;
	int damage = atk;
	if (activateSkill) // 40%
	{
		damage *= 1.5f;
		Bite();
	}
	else
	{
		Slam();
	}
	goblin->Damage(damage);
}

void Rabbit::Damage(int damage)
{
	float defParam = def * 0.01f;
	if (defParam > 0.5f) // 최대 50%는 넘어가지 않도록 설정.
		defParam = 0.5f;
	bool defendSuccess = Random::Range(0.0f, 0.1f) < 0.1f + (def * 0.01f);
	if (defendSuccess)
	{
		bool escapeSuccess = Random::Range(0.0f, 0.1f) < 0.3f;
		if (escapeSuccess)
		{
			Escape();
			return;
		}
		else
		{
			damage *= 0.1f;
			Defend();
		}

	}
	cout << name << "은(는) " << damage
		<< "만큼의 대미지를 입었다." << endl;
}

void Rabbit::Escape()
{
	cout << name << "은(는) 빠르게 도망쳤다!" << endl;
}

void Rabbit::Bite()
{
	
	cout << name << "은(는) 깨물기를 시전했다!" << endl;
}

void Rabbit::Slam()
{
	cout << name << "은(는) 몸통 박치기를 시전했다!" << endl;
}

Rabbit::Rabbit(int hp, int atk, int def)
	:Monster("토끼", hp, atk, def)
{

}
