#include <iostream>
#include "Goblin.h"
#include "Rabbit.h"
#include "Human.h"
#include "Slime.h"
using namespace std;

// 간단한 TextRPG 만들기
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
// - 
// 
// - 몬스터 3종류 
// 토끼
// - 체력
// - 공격력
// - 방어력
// - 공격()
// - 맞기() (대미지) - (방어력)만큼 피해를 입음.
// - 깨물기()
// - 도망치기() : 확률적으로 도망침!
// - 죽음()

// 인간
// - 체력
// - 공격력
// - 방어력
// - 공격()
// - 방어()
// - 발차기()
// - 죽음()
// - 맞기() (대미지) - (방어력)만큼 피해를 입음.

// 슬라임
// - 체력
// - 공격력
// - 방어력
// - 공격()
// - 죽음()
// - 튀어오르기() 
// - 맞기() (대미지) - (방어력)만큼 피해를 입음.

int main()
{
	Goblin goblin(200, 10, 5);
	// 몬스터를 랜덤으로  10마리 생성! 
	Monster* monsters[10];
	for (int i = 0; i < 10; i++)
	{

		// Random::Range([최소 값], [최대 값])
		// (정수) ; [최소 값]이상 ~ [최대 값] 미만의 랜덤한 정수 반환.
		
		int index = Random::Range(0, 3); // 0 1 2
		switch (index)
		{
			case 0:
				monsters[i] = new Rabbit(50, 4, 3);
				break;
			case 1:
				monsters[i] = new Human(100, 5, 2);
				break;
			case 2:
				monsters[i] = new Slime(150, 0, 0);
				break;
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		printf("< %d번째 전투 >\n", i + 1);
		goblin.Attack(monsters[i]);
		monsters[i]->Attack(&goblin);
		printf("--------------------------\n");
		cout << "계속하려면 Enter를 눌러주세요" << endl;
		getchar(); // Enter용
		system("cls"); // 화면을 지우는 기능.
	}

	for (int i = 0; i < 10; i++)
	{
		delete monsters[i];
	}



	return 0;
}