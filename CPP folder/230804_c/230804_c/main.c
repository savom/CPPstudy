#include <stdio.h>

// 포인터.
// = 저장 공간의 주소를 저장하는 변수
// [데이터 형식]* [포인터 이름];
// ex. float* pF;
// pF라는 이름의 실수 데이터 저장 공간의 주소를 저장하는 저장 공간을 만들어라!
//

// 어떤 데이터 형식의 저장 공간의 주소던 항상 16진수 정수로 되어 있다.
void Swap(int* pA, int* pB);


int main()
{
	#pragma region 포인터
		int number = 10, number1 = 20;
		int* pNum = &number;

		printf("<변경 전>\n:");
		printf("number = %d\n", number); //10
		printf("number1 = %d\n", number1); //20
		printf("pNum = %p\n", pNum); // 주소
		printf("*pNum = %d\n", *pNum); // 10

		// * 간접 참조 연산자
		// 해당 주소로 찾아가, 그 주소에 있는 저장공간을 사용하는 연산자.

		*pNum = 48; 
		pNum = &number1;
		*pNum = 99;
		// pNum에 해당하는 주소로 찾아가서
		// 그 주소에 있는 저장 공간에 48을 대입한다.

		printf("<변경 후>\n:");
		printf("number = %d\n", number); // 48
		printf("number1 = %d\n", number1); // 99
		printf("pNum = %p\n", pNum); // 주소
		printf("*pNum = %d\n", *pNum); // 99
	#pragma endregion

		int a = 10, b = 20;
		printf("<변경 전>\n");
		printf("a = %d\n", a);
		printf("b= %d\n", b);

		// 변경
		Swap(&a, &b);

		printf("<변경 후>\n");
		printf("a = %d\n", a);
		printf("b= %d\n", b);

	return 0;
}

void Swap(int* pA, int* pB)
{
	int c = *pA;
	*pA = *pB;
	* pB = c;
}
