#include "Slime.h"

void Slime::Attack(Goblin* goblin)
{
	Bounce();
	
}

void Slime::Bounce()
{
	cout << name << "Àº(´Â) Æ¢¾î¿Ã¶ú´Ù." << endl;
}

Slime::Slime(int hp, int atk, int def)
	:Monster("½½¶óÀÓ", hp, atk, def)
{
}
