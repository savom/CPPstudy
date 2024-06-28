#include <stdio.h>

	#pragma region 복습
// 포인터
// 저장공간의 주소를 저장하는 저장공간.
// [데이터 형식]* [포인터의 이름];
// pD라는 이름의 8바이트 실수 데이터 저장공간의 주소를 저장할 수 있는 저장공간을 만들어라.
// double* pD;
// 
// * 간접 참조 연산자.
// 해당하는 주소로 찾아가서 그 주소에 있는 저장 공간을 사용한다.
// 
// 어떤 함수의 일반적인 매개 변수로 다른 함수에 있는 변수의 데이터를 변경하려면?
//
#pragma endregion

// 포인터의 특징
// 1. 어떤 데이터 형식의 포인터이던 메모리 크기가 동일하다.
// = 모든 주소는 16진수 정수로 표현되기 때문에!
// 64비트(x64) : 8바이트
// 32비트(x86) : 4바이트.
// 
// 2. 포인터는 포인터 연산이 가능하다.
// 포인터 + 1 => [해당 주소 값] + [포인터가 가리키는 저장 공간의 데이터 형식 메모리 크기]
// ex. double d;
// double* pD = &d;
// pD + 1 => 8바이트 움직인다.
// 
// 배열과 포인터.
// 배열 : 여러 개의 저장공간을 줄을 지어 나열시킨 구조.
// ★★★★★ 배열의 이름 = 배열의 첫번째 저장 공간의 주소.
// 
// arr[0] => *(arr + 0)
// 
// 배열과 함수.
// 정수 배열의 길이(몇 칸인지?)를 반환하는 함수 만들기!
// int GetArrayLength(int arr[]);
// 

// ★★★★ 
// 배열을 함수의 매개변수로 설정할 경우, 자동으로 포인터로 변경된다!
// 이러한 특징 때문에, 함수의 매개 변수로 설정된 배열은 전체 메모리 크기를 알 수 없고,
// 따라서 길이 또한 게산하는 것이 불가능하다.

// 배열을 매개변수로 사용할 경우, 반드시 배열의 길이(크기)도 함께 매개변수로 사용하는 것이 좋다!
int GetArrayLength(int arr[]);


int main()
{
	#pragma region 포인터의 메모리 크기
		//int n, *pN;
		//char c, *pC;
		//double d, *pD;

		//printf("n의 메모리 크기 : %ld\n", sizeof(n)); // 4
		//printf("c의 메모리 크기 : %ld\n", sizeof(c)); // 1
		//printf("d의 메모리 크기 : %ld\n", sizeof(d)); // 8
	
		//printf("pN의 메모리 크기 : %ld\n", sizeof(pN)); // 8
		//printf("pC의 메모리 크기 : %ld\n", sizeof(pC)); // 8
		//printf("pD의 메모리 크기 : %ld\n", sizeof(pD)); // 8
	#pragma endregion 

	#pragma region 포인터 연산
		/*int num;
		int* pNum = &num;

		float f;
		float* pF = &f;

		char c;
		char* pC = &c;

		double d;
		double* pD = &d;

		printf("pNum = %d\n", (int)pNum);
		printf("pNum + 1 = %d\n", (int)(pNum + 1));

		printf("pF = %d\n", (int)pF);
		printf("pF + 1 = %d\n", (int)(pF + 1));
	
		printf("pC = %d\n", (int)pC);
		printf("pC + 1 = %d\n", (int)(pC + 1));

		printf("pD = %d\n", (int)pD);
		printf("pD + 1 = %d\n", (int)(pD + 1));*/
	#pragma endregion

	#pragma region 포인터와 배열
	//int arr[5] = { 1,2,3,4,5 };

	//printf("arr = %d\n", *arr);
	//printf("&arr[0] = %p\n", &arr[0]);

	//// 배열의 2번째 저장 공간의 주소
	//printf("&arr[1] = %p\n", &arr[1]);
	//printf("arr + 1 = %p\n", arr + 1);

	//for (int i = 0; i < 5; i++)
	//{
	//	// ★★★★★ *((배열 이름) + i ) => (배열 이름)[i]
	//	// [] 첨자 연산자.(= 일종의 간접 참조 연산자!)

	//	printf("%d\n", *(arr + i));
	//}

	//// 포인터는 배열처럼 사용할 수 있다!
	//int* pNum = arr;
	//printf("pNum : ");
	//for (int i = 0; i < 5; i++)
	//{
	//	// printf("%d ", pNum[i]);
	//	printf("%d ", *(pNum + i));
	//}
	//printf("\n");
#pragma endregion

	//int arr[10];
	//int length = GetArrayLength(arr);

	//int size = sizeof(arr); // 40
	//printf(" arr의 전체 메모리 크기 : %d\n", size); // 40

	//printf("arr의 길이 : %d\n", size/sizeof(int)); // 10
	//printf("arr의 길이 : %d\n", length); // 2?

	char name[20];

	

	printf("이름을 입력하세요 : ");

	// scanf_s() :
	// name에 &를 안붙이는 이유는 name자체가 배열의 첫 번째 주소를 가지고 있어서다.
	// sizeof를 쓰는 이유는 저장공간의 크기를 알려줘서, 만약에 입력한 내용의 양이 저장 공간보다 많을 경우 (일부러 더 큰 문제가 생기기 전에)오류를 낸다.
	scanf_s("%s", name, sizeof(name));

	return 0;
}

int GetArrayLength(int arr[])
{
	// 40 바이트 /4
	int b = 0;
	int a = sizeof(arr);
	b = a / 4;

	return b;
}
