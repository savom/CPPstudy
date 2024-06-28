#include <stdio.h>

#pragma region 복습
// 문자열 전용 입출력 함수
// gets_s() : gets_s([저장 공간의 주소], [저장 공간의 크기]) 
// puts() : puts([출력할 문자열])
// 
// 문자열 함수.
// str : string 문자열
// - strcmp : str + cmp(comparison) 문자열 비교 함수.
// - strlen : str + len(length) 문자열 길이 함수.
// - strcpy_s : str + cpy(copy) 문자열 복사 함수.
// - strcat_s : str + cat(concatenate) 문자열 더하기 함수.
// 
// strcpy_s([목적지 주소], [목적지 저장 공간의 크기], [복사할 문자열]);
// strcat_s([목적지 주소], [목적지 저장 공간의 크기], [더하기 할 문자열]);
// strlen([문자열])
// strcmp([문자열 1], [문자열 2])
// 사전 순(아스키 코드 순) 비교.
// 1이 2보다 앞에 있음 : -1
// 1과 2의 순서가 동일 : 0
// 1이 2보다 뒤에 있으면 : 1
#pragma endregion

// 2차원 배열
// 배열 여러 개가 일자로 나열되어 있는 구조.
// 배열 : (데이터 형식) (배열의 이름)[칸 수(길이)]
// 2차원 배열 : (데이터 형식) (배열의 이름) [줄 수] [칸수(길이)]
// 
// int arr[3][6]; // 정수 데이터 저장 공간 6칸짜리 3줄 2차원 배열을 만들어라!
// 
// 포인터 배열
// 포인터가 여러 개 나열되어 있는 구조.
// (데이터 형식)* (배열의 이름) [칸 수(길이)]
// 


int main()
{
	#pragma region _2차원 배열
		//// 2차원 배열 또한 중괄호 초기화가 가능하다
		///*int arr[3][5] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15} };*/

		///*printf("arr[2][3] = %d\n", arr[2][3]);*/

		//// 78칸짜리 52줄의 2차원 배열을 만들고
		//// 첫번째 줄 첫번째 칸부터 순서대로 1 ~4056까지 대입해 주세요.
		//// 그 후 해당 2차원 배열의 모든 요소를 출력해 주세요.
		//
		//int c = 1;
		//int arr[52][78];
		///*for (int a = 0; a < 52; a++)
		//{
		//	for (int b = 0; b < 78; b++)
		//	{
		//		arr[a][b] = c;
		//		c++;
		//		
		//	}
		//}*/

		//int number = 1;
		//for (int j = 0; j < 52; j++)
		//{
		//	for (int i = 0; i < 78; i++)
		//	{
		//		arr[j][i] = number;
		//		number++;
		//	}
		//}

		//for (int j = 0; j < 52; j++)
		//{
		//	for (int i = 0; i < 78; i++)
		//	{
		//		arr[j][i] = j * 78 + i + 1;
		//	}
		//}

		//for (int j = 0; j < 52; j++)
		//{
		//	for (int i = 0; i < 78; i++)
		//	{
		//		printf("arr[%d][%d] :  = %d\n", j, i, arr[j][i]);
		//	}
		//}
		//

		///*{{1,2,3,4,5,6 ...}, {}}*/
	#pragma endregion

	#pragma region _2차원 배열의 특징
	// 2차원 배열의 특징
	// 다차원 배열은 모든 저장 공간이 일자로 나열되어 있다.
	//int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	//int* pNum = arr;
	//
	//for (int i = 0; i < 12; i++)
	//{
	//	printf("pNum[%d] = %d\n", i, pNum[i] /* => *(pNum + i) */);
	//}
#pragma endregion

	#pragma region 포인터 배열
	int* pArr[3];
	int arr1[3] = { 1,2,3 };
	int arr2[5] = { 4,5,6,7,8 };
	int arr3[4] = { 9,10,11 };

	pArr[0] = arr1;
	pArr[1] = arr2;
	pArr[2] = arr3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("pArr[%d][%d] = %d\n", i, j, pArr[i][j]);
		}
	}
#pragma endregion

	#pragma region 이중 포인터
	// 포인터의 포인터
	// 저장 공간의 주소를 저장하는 저장 공간의 포인터
	// 일반적인 매개 변수 : 다른 함수에 있는 변수에 데이터를 변경할 수 없다.
	// 포인터 매개 변수 : 다른 함수에 있는 변수에 데이터를 변경할 수 있다.
	// 다른 함수의 포인터를 변경할 때 변경할 때 사용한다.
	// 이중 포인터를 포인터 배열처럼 쓸 수 있고, 포인터 배열을 2차원 배열처럼 쓸 수 있다.
	// => 이중 포인터는 2차원 배열처럼 쓸 수 있다.

	int** ppNum;
	int arr[2][4] = { {1,2,3,4},{5,6,7,8} };

	int* pNum = arr;
	ppNum = &pNum;
	
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