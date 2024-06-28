#include <stdio.h>

	#pragma region 복습
// 2차원 배열
// 배열 여러 개가 일자로 나열되어 있는 구조.
// (데이터 형식) (배열의 이름)[(줄 수)][(칸 수)];
// float fArr[3][10]; // 10칸짜리 3줄
// ★★★★★ 모든 저장 공간이 한 줄로 나열되어 있다.
// 
// 포인터 배열
// 포인터가 일자로 나열되어 있는 구조.
// (데이터 형식)* (배열의 이름)[(칸 수)];
// ★★★★ 포인터 배열은 2차원 배열처럼 사용할 수 있다.
// 
// 포인터 배열 vs 2차원 배열
// 2차원 배열은 '반드시' 모든 배열이 일자로 나열되어 있다.
// 포인터 배열은 그렇지 않을 수 있다.
// 
// 이중 포인터
// 포인터의 포인터
// 저장 공간의 주소를 저장하는 저장 공간의 주소를 저장하는 저장 공간.
// 
// 이중 포인터 활용 1:
// 함수의 매개 변수를 통해
// 다른 함수에 있는 포인터의 데이터를 변경 시 사용
// 
// 이중 포인터 활용 2
// 이중 포인터는 포인터 배열처럼 사용할 수 있다.
// 따라서 이중 포인터를 경우에 따라 2차원 배열처럼 사용할 수 있다.
// 
#pragma endregion

	#pragma region 이중 포인터 예시
	// 포인터의 주소 값을 서로 변경하는 함수 만들기!
	void Swap_ptr();
	#pragma endregion


int main()
{
	#pragma region 이중 포인터 활용 1
	// 이중 포인터 활용 1:
	// 함수의 매개 변수를 통해
	// 다른 함수에 있는 포인터의 데이터를 변경 시 사용
	// 
	//int a = 10, b = 20;
	//int *pA = &a, *pB = &b;
	//printf("<변경 전>\n");
	//printf("a = %d, b = %d\n", a, b);
	//printf("pA = %d, pB = %d\n", *pA, *pB);

	//// pA <-> pB의 데이터 교환
	//Swap_ptr(&pA, &pB);

	//printf("<변경 후>\n");
	//printf("a = %d, b = %d\n", a, b);
	//printf("pA = %d, pB = %d\n", *pA, *pB);
#pragma endregion

	#pragma region 이중 포인터 활용 2
	// 이중 포인터 활용 2
	// 이중 포인터는 포인터 배열처럼 사용할 수 있다.
	// 따라서 이중 포인터를 경우에 따라 2차원 배열처럼 사용할 수 있다.
	int** ppNum;
	int arr[2][4] = { {1,2,3,4},{5,6,7,8} };

	int* pNum = arr[0]; // arr의 첫번째 줄의 주소
	int* pNum = arr[1];
	ppNum = pNum;

	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			printf("arr[%d][%d] = %d\n", i, k, ppNum[i][k]);
		}
	}
#pragma endregion


	return 0;
}

void Swap_ptr(int** a, int** b)
{
	int* c = 0;
	c= *a;
	*a = *b;
	*b = c;

	
}
