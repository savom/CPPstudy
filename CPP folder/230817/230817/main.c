#include <stdio.h>
#include <stdlib.h> // 동적 할당 함수를 사용하기 위해 필요한 헤더 파일.
#include <string.h>
	#pragma region 복습
// 이중 포인터
// 포인터의 포인터
// 1. 함수의 매개 변수를 통해서, 다른 함수에 있는 포인터의 데이터를 변경할 때
// 2. 이중 포인터는 포인터 배열처럼 사용할 수 있다.
// 포인터 배열은 2차원 배열처럼 사용할 수 있으므로,
// 이중 포인터 또한 2차원 배열처럼 사용할 수 있다.
// 
// 함수 포인터
// 함수의 주소를 저장하는 저장공간.
// [반환 데이터 형식 (*[포인터의 이름])([매개 변수 형식])
// void (*vp)();
// vp라는 이름의 반환 데이터가 없고 
// 매개 변수도 없는 함수의 주소를 저장하는 포인터를 만들어라!
// 함수의 주소 => 함수의 이름.
// 
// void 포인터
// 아무 데이터 형식의 주소를 저장할 수 있는 포인터.
// void* [포인터 이름];
// 참조할 때 반드시 데이터 형식을 지정해 줘야한다.
//
#pragma endregion

// 동적 할당
// 할당 -> 메모리 할당(저장 공간을 만드는 것, 변수)
// = 유동적으로 메모리를 할당.
// 프로그램에서 필요한 메모리가 정확히 얼마나 될 지 알기 어렵다.
// 프로그램을 실행하는 도중,
// 필요한 만큼만 유동적으로 메모리를 할당할 필요가 있다.
// 
// <C 언어의 동적 할당>
// 동적 할당 함수를 사용!
// <stdlib.h> 필요!

// malloc()
// m(memory) + alloc(allocation 할당)
// malloc([메모리 크기])
// [메모리 크기]의 크기만큼의 저장 공간을 새로 생성.
// 반환 데이터 : 새로 생성한 메모리의 주소.
// 동적 할당에 실패하는 경우, NULL(= (void*)0)을 반환.
// 
// free() : 메모리 해제(메모리 삭제) 함수.
// ★★★★★
// 동적 할당한 메모리는 '직접' 해제하기 전에는 해제되지 않는다.
// 따라서, 동적 할당한 메모리는 '반드시' free()를 통해서 해제해야 한다!
// free([메모리 주소])
// [메모리 주소]에 해당하는 동적 할당 메모리를 해제 
//

char* InputName();

int main()
{
	#pragma region 동적 할당
	// 이름을 입력받는 코드 작성!
	/*char name[10];
	printf("이름을 입력하세요 : ");
	gets_s(name, sizeof(name));

	printf("입력한 이름 : %s\n", name);*/


	//// 4바이트 크기의 메모리를 동적 할당.
	//// 동적 할당한 메모리의 주소를 pNum이라는 이름의 정수 포인터에 저장.
	//int *pNum = (int*)malloc(4);
	//*pNum = 10;
	//printf("*pNum = %d\n", *pNum);
	//float *pF = (float*)pNum;
	//*pF = 65.24f;
	//printf("*pF = %.2f\n", *pF);

	//free(pF);

#pragma endregion

	#pragma region 배열 동적 할당
	// 정수 10칸짜리 배열을 동적 할당하고,
	// 해당 배열에 1 ~ 10까지 대입한 후, 모든 요소를 출력할 것.

	/*int* pNum = (int*)malloc(40);
	if (pNum == NULL)
		return 0;

	for (int i = 0; i < 10; i++)
	{
		pNum[i] = i + 1;
		printf("pNum = %d\n", pNum[i]);
	}

	free(pNum);*/
#pragma endregion

	#pragma region 학생 점수 입력
		// 학생 수를 입력받습니다.
		// 학생 수 만큼 점수를 입력받습니다.
		// 모든 학생의 점ㅈ수를 입력 받은 후 각 학생의 점수를 출력해 주새요.

		// ex 학생 수를 입력하세요 : 4
		// 학생 1의 점수를 입력하세요 : 100
		// 학생 2의 점수를 입력하세요 : 100
		// 학생 3의 점수를 입력하세요 : 100
		// 학생 4의 점수를 입력하세요 : 100

		// 학생 1의 점수 : 100점
		// 학생 2의 점수 : 100점
		// 학생 3의 점수 : 100점
		// 학생 4의 점수 : 100점

		/*int num;
		printf("학생 수를 입력하세요 : ");
		scanf_s("%d", &num);

		int* score = (int*)malloc(num * sizeof(int));

		for (int i = 0; i < num; i++)
		{
			printf("학생%d의 점수를 입력하세요 : ", i+1);
			scanf_s("%d", (score+i));
		}
	
		for (int i = 0; i < num; i++)
		{
			printf("학생%d의 점수 : %d\n", i + 1, score[i]);
		}

		free(score);*/
	#pragma endregion

	// 이름을 입력받는 함수 만들기!
	// InputName
	// 동적 할당을 활용해서, 입력받은 이후 동적할당한 메모리에
	// 입력받은 이름이 남아 있도록 할 것.
	
	
	/*char name = "heeseock";*/
 	
	
	// name에 값을 반환받음.
	/*char* name = InputName();
	printf("입력한 이름 : %s\n", name);
	free(name);*/
	
	// --------- 내가한거-----------------------------
	// 회원 수를 입력받습니다.
	// 입력받은 회원 수 만큼 회원 이름을 입력받습니다.
	// 그 후, 입력받은 회원의 이름을 모두 출력합니다.
	/*int number;
	printf("회원 수를 입력해 주세요 : ");
	scansf("%d", &number);
	char** c = (char**)malloc(sizeof(char*) * number);
	
	for (int i = 0; i < number; i++)
	{

		printf("%d번 회원의 이름을 입력하세요 : ", i + 1);
		c[i] = InputName();
	}

	for (int i = 0; i < number; i++)
	{
		printf("%d번 회원의 이름 : %s\n", i + 1, c[i]);
	}
	

	free(c);*/
	// -----------------------------------------------
// 회원수 입력받기
	int count;
	printf("회원 수를 입력하세요 : ");
	scanf_s("%d", &count);
	// 문자 포인터를 count만큼 동적 할당
	char** nameArr = (char**)malloc(sizeof(char*) * count);
	// nameArr이라는 문자열 포인터 배열의 i칸에 함수 대입
	for (int i = 0; i < count; i++)
	{
		printf("회원 %d의 ", i + 1);
		nameArr[i] = InputName();
	}
	// nameArr의 i번째 칸에 있는 것을 출력;
	puts("\n--------<회원 목록>----------");
	for (int i = 0; i < count; i++)
	{
		printf("회원 %d : %s\n", i + 1, nameArr[i]);
	}
	// nameArr의 안에 있는 i번째 있는 동적 할당을 해제
	for (int i = 0; i < count; i++)
	{
		// nameArr을 먼저 지우면 nameArr[i]번째 칸에 있는 동적 할당을 지우지 못함
		// ★★★★ 
		// 동적 할당한 메모리를 해제할 경우,
		// 반드시 동적 할당한 순서의 역순으로 해제할 것!
		// (가장 나중에 할당한 메모리를 가장 먼저 해제!)

		free(nameArr[i]);
	}

	free(nameArr);


	return 0;
	
}

char* InputName()
{
	// 저장 공간 만들고
	char buffer[255];
	printf("이름을 입력하세요 : ");
	// 입력 받기
	// gets_s(buffer, sizeof(buffer)); // 입력버퍼 문제!
	scanf_s("%s", buffer, sizeof(buffer));

	// 널 문자를 포함한 문자열 길이 측정.
	int length = strlen(buffer) + 1; // 문자열 길이 + 1(널 문자 포함)
	// 저장 공간의 크기 계산
	int size = sizeof(char) * length;
	// 동적 할당 / name에 동적 할당 주소 저장.
	char* name = (char*)malloc(size);
	// name에 size의 크기만큼 buffer에 입력한 값을 name에 복사.
	strcpy_s(name, size, buffer);

	// name을 반환
	return name;



	//------ 내가한거-------
	/*char* name[100] = {'a', };
	printf("이름을 입력하세요 : ");
	scanf_s("%s", name, sizeof(name));
	char* namelen = (char*)malloc(sizeof(name));
	namelen = name;
	
	
	
	free(namelen);
	return namelen;*/
	

	
	
	
	
}
