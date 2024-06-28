#include <stdio.h>
#define 출력 printf
#define CHARACTERNAME "홍일동"
#define MYFLOAT 49.44f
#define ADD(x,y) ((x) + (y))
#define AAA:


//typedef int AAA;

typedef struct Human
{
	char* name;
	int age;
}HUMAN;

enum Menu
{
	GAMESTART = 48,
	SAVE,
	LOAD = 941,
	QUIT,
};

int main()
{
	#ifdef AAA

	HUMAN human;
	출력("GAMESTART + 20 = %d\n", GAMESTART + 20);
	출력("%s\n", CHARACTERNAME);
	출력("ADD(10,20) = %d\n", ADD(10, 20));
	
	#endif
	return 0;
}

// typedef(type definition 형식 정의)
// 데이터 형식을 정의. (데이터 형식에 별명을 붙이는 것)
// <문법>
// typedef [데이터 형식] [별명], [별명 2], *[별명 3];
// ex. typedef int INT, *PINT;
// PINT == int*
// 
// typedef를 구조체에 사용할 수 있다!
// typedef를 구조체에 사용할 경우, struct를 생략할 수 있다!
// 
// 
// enum : 정수에 별명을 붙이는 데이터 형식.
// <문법>
// enum [enum의 이름]
// {
//		[별명 1] = [정수 값],
//		[별명 2],
// }
// 
// enum 변수 : enum [enum의 이름] [변수 이름];
// 
// 
// 전처리 지시자
// 코드를 빌드하기 '전'에 무언가를 처리하는 지시자.
// #include
// 헤더(.h) 파일을 포함시키는 전처리 지시자.
// (헤더 파일 안에 있는 내용을 복사/붙여넣기함.)
// 
// #define
// 코드에 별명을 붙이는 전처리 지시자.
// #define [별명] [코드]
// 
// #define 함수(= 매크로 함수)
// #define [함수 이름] ([매개 변수]들) [코드]
// 매크로 함수는 코드를 그대로 대체하므로, 연산 순서가 바뀔 수 있다.
// 따라서, 매개 변수, 결과 값에 괄호를 붙이는 것이 좋다.
// 
// #ifdef, #ifndef, #endif
// #define에 정의되어 있는지 확인!
// 
// #ifdef [별명]
// : #define으로 정의된 [별명]이 존재할 경우,
// #endif까지의 코드를 빌드에 포함시킨다.
// 
// #ifndef [별명]
// : #define으로 정의된 [별명]이 존재하지 않을 경우,
// #endif까지의 코드를 빌드에 포함시킨다.
// 
// #pragma : 여러가지 지시하는 지시자.
// 
// 분할 컴파일.
// : 코드를 여러 개의 파일로 나눠서 작성. 
// 
// <파일의 종류>
// 헤더 파일 : 선언부.함수, 구조체 등을 선언.
// 소스 파일 : 구현부. 함수 정의(함수의 실제 내용을 작성하는 곳).
// 
// 전역 변수
// 프로그램 전체에서 접근할 수 있는 변수.
// 프로그램이 시작할 때 생성. 프로그램이 종료될 때 해제.
// 
// extern : 다른 파일에 있는 전역 변수를 가져와서 사용하겠다! 라는 의미.
// ex. extern int number; // main.c에 있는 전역 변수 number를 가져옴.
// static : 다른 파일에서 현재 파일에 있는 전역 변수에 접근할 수 없도록 하는 한정자.