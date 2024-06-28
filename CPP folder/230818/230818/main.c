#include <stdio.h>
#include <stdlib.h>

#pragma region 복습
// 동적 할당
// 유동적으로 메모리를 할당(= 저장 공간을 만든다.
// 프로그램에 필요한 메모리의 크기를 정확히 알기 어렵다.
// 
// C 언어의 동적 할당
// <stdlib.h> 필요!
// malloc(), free()
// malloc() : m(memory) + alloc(allocation 할당)
// malloc([메모리 크기]) : [메모리 크기]의 크기만큼 새로운 저장 공간을 만든다.
// 반환 데이터 : 생성한 저장 공간의 주소.
// 
// 동적 할당한 메모리는 직접 해제하기 전까지는 해제되지 않는다!
// 따라서, 반드시 직접 해제해야 한다.
// 
// free([메모리 주소])
// [메모리 주소]에 해당하는 저장 공간을 해제.
//
#pragma endregion

// 사용자 정의 자료형(구조체)
// 개발자가 직접 만드는 자료형(데이터 형식)
// 다른 데이터 형식을 여러 개 가지고 있는 복합 데이터 형식.

// <문법>
// 1. 구조체 선언 : 이러이러한 형식의 구조체가 있다!라고 얘기함.
// struct [구조체 이름]
// {
//		[변수]들
// }
// 구조체 안에 있는 변수를 멤버 변수라고 한다.
// 
// 
// 2. 구조체 변수
// struct [구조체 이름] [변수 이름]
//

struct HumanData
{
	char* name;
	int age;
	float height;
	float weight;
	char* sex;
};

// HumanData의 이름, 나이, 키, 몸무게를 입력받는 함수 만들기!
void InputHumanData(struct HumanData* humanData);
// Humandata의 이름, 나이, 키, 몸무게를 출력하는 함수 만들기!
void OutputHumanData(struct HumanData* humanData);
int main()
{
	// 2. 구조체 변수 선언.
	//
	// 구조체 안에 있는 멤버 변수를 사용하기!
	// : [변수 이름].[멤버 변수 이름]

	struct HumanData human;
	human.name = "김희석";
	human.age = 24;
	human.weight = 60.03f;
	human.height = 167.4f;
	
	struct HumanData humanData;
	InputHumanData(&humanData);
	OutputHumanData(&humanData);

	/*printf("이름 : %s\n", human.name);
	printf("나이 : %d\n", human.age);
	printf("키 : %.2f\n", human.height);
	printf("몸무게 : %.2f\n", human.weight);*/
	

	return 0;
}

void InputHumanData(struct HumanData* humanData)
{
	printf("이름을 입력하세요 : "); 
	scanf_s("%s", humanData->name, sizeof(humanData->name));// ★★★★★ 숙제 고쳐오기

	printf("나이를 입력하세요 : ");
	scanf_s("%d", humanData->age);

	printf("키를 입력하세요 : ");
	scanf_s("%.2f", humanData->height);

	printf("몸무게를 입력하세요 : ");
	scanf_s("%.2f", humanData->weight);
}

void OutputHumanData(struct HumanData* humanData)
{
	printf("이름 : %s\n", humanData->name);
	printf("나이 : %d\n", humanData->age);
	printf("키 : %.2f\n", humanData->height);
	printf("몸무게 : %.2f\n", humanData->weight);
}
