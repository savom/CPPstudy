#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma region 복습
// 구조체
// 사용자 정의 자료형
// 복합 자료형
// 
// <문법>
// 1. 구조체 선언
// struct [구조체 이름]
// {
//		[변수]들
// };
// 
// 2. 구조체 변수
// struct [구조체 이름] [변수 이름];
// ex. struct HumanData humanData;
// humanData.height
//
#pragma endregion

// enum
// 정수에 별명을 붙여서 사용하는 데이터 형식.
// 
// <문법>
// 1. enum 선언.
// enum [enum의 이름]
// {
//		[별명 1],
//		[별명 2],
//		....
//		[별명 n],
// }
// 
// 2. enum 변수 선언
// enum [enum의 이름] [변수 이름];
// 
// 작성한 코드의 정수에 의미를 부여하기 위해서 사용.
//

enum TestEnum
{
	ONE,
	TWO,
	THREE,
};

enum Medal
{
	GOLD = 1,
	SILVER = 2,
	BRONZE = 3,
};

// 파일 입출력
// 파일 입력 : 프로그램으로 파일을 들여오는 것.(불러오기. 로드)
// 파일 출력 : 프로그램에서 파일을 내보내는 것.(저장. 새로 만들기)
//

int main()
{
	#pragma region enum
	//// enum 변수(= 정수 변수와 똑같다.)
	//enum TestEnum testEnum;
	//testEnum = TWO;
	///*printf("TestEnum.TWO = %d\n", TWO);*/

	//int rank;
	//printf("등 수를 입력하세요 : ");
	//scanf_s("%d", &rank);
	//switch (rank)
	//{
	//	case GOLD:
	//		printf("금메달입니다!\n");
	//		break;
	//	case SILVER:
	//		printf("은메달입니다!\n");
	//		break;
	//	case BRONZE:
	//		printf("동메달입니다!\n");
	//		break;
	//}
#pragma endregion

	#pragma region 파일 출력
		//// FILE 파일 구조체
		//FILE* fp;

		//// fopen_s() : 파일 열기 함수.
		//// fopen)s([파일 구조체 포인터의 주소], [파일 경로], 열기 모드]);

		//// [파일 경로]
		//// 절대 경로 : "C:\\MyFile.txt". 파일의 절대적인 위치를 나타냄.
		//// 상대 경로 : "..\\MyFile.txt". 현재 폴더를 기준으로하는 위치 
		//// .. : 이전 폴더 

		//// [열기 모드]
		//// "w" : write : 파일 쓰기 모드. 파일이 없으면 생성.
		//// "r" : read : 파일 읽기 모드. 파일이 없으면 오류.(NULL)
		//// "a" : append : 파일 추가 모드(파일을 이어서 작성.) 파일이 없으면 생성
		//// "w+" : 읽기/쓰기. 파일이 없으면 생성.
		//// "r+" : 읽기/쓰기. 파일이 없으면 오류.
		//// "a+" : 읽기/쓰기. 파일이 없으면 생성.

		//fopen_s(&fp, "MyFile.txt", "w");
		//if (fp == NULL)
		//{
		//	printf("파일을 열 수 없습니다\n");
		//	return 1;
		//}

		//// 출력 함수
		//// printf, puts, putchar

		//// 파일 출력 함수
		//// fprintf_s, fputs, fputchar...6
		//// 앞에 [파일 구조체 포인터]가 들어가는 것 외에 일반 출력 함수와 동일하다.
		//fprintf_s(fp, "안녕하세요! 제 이름은 %s입니다.\n", "홍길동");
		//

		//printf("파일을 생성했습니다\n");

		//fclose(fp);
	#pragma endregion

#pragma region 파일 입력
	FILE* fp;
	fopen_s(&fp, "MyData.txt", "r");
	if (fp == NULL)
	{
		printf("파일을 열 수 없습니다\n");
		return 1;
	}

	while (1)
	{
		char name[20];
		int age;
		float height;


		// feof([파일 구조체 포인터]) : 파일의 끝인이 아닌지 확인하는 함수
		// 파일의 끝이 아닐 경우 0을 반환
		// 파일의 끝일 경우 0이 아닌 정수를 반환.
		if (feof(fp)) 
			break;

		fscanf_s(fp, "%s %d %f", name, (int)sizeof(name), &age, &height);
		printf("이름 : %s\n", name);
		printf("나이 : %d세\n", age);
		printf("키 : %.2fcm\n", height);

		
	}
	fclose(fp);

#pragma endregion

	return 0;
}