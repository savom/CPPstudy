#include <stdio.h>

// 함수 포인터
// 함수의 주소를 저장하는 저장 공간.
// 
// <문법>
// [반환 데이터 형식] (*[포인터 이름])([매개 변수 형식]);
// ex. int (*fp)(int,int);
//
int Add(int a, int b);
int Sub(int a, int b);

// void 포인터.
// <문법>
// void *(포인터 이름);
// 데이터 형식이 따로 존재하지 않는 포인터.
// = 아무 데이터 형식의 주소를 저장할 수 있는 포인터.

int main()
{
	#pragma region 함수 포인터
	// 포인터 이름 : fp
	// 반환 데이터 형식이 int이고,
	// 매개 변수가 int 2개인 함수의 주소'만' 저장할 수 있다.
	
	// ★★★★ 함수의 주소 = 함수의 이름.
	/*int (*fp)(int, int);
	fp = Add;
	printf("fp(10,20) = %d\n", fp(10, 20));

	fp = Sub;
	printf("fp(10,20) = %d\n", fp(10, 20));*/
#pragma endregion

	void* vp;
	int a = 10;
	float f = 14.23f;
	char c = 'A';

	// void 포인터를 참조 시
	// 반드시 해당 void 포인터의 데이터 형식을 지정해줘야 한다!

	vp = &a;
	// printf("*vp = %d\n", *vp);
	printf("*vp = %d\n", *(int*)vp);
	vp = &f;
	printf("*vp = %.2f\n", *(float*)vp);
	
	vp = &c;
	printf("*vp = %c\n", *(char*)vp);



	return 0;
}

int Add(int a, int b)
{
	return a+b;
}

int Sub(int a, int b)
{
	return a-b;
}
