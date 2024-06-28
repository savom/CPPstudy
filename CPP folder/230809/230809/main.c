#include <stdio.h>

	#pragma region 복습
// 포인터의 특징
// 1. 어떤 데이터 형식의 포인터이던 메모리 크기는 동일하다.
// 64비트 : 8바이트
// 32비트 : 4바이트
// 
// 2. 포인터는 포인터 연산이 가능하다.
// (한 칸씩 이동한다.)
// float f
// float* pF = &f // 100
// pF = pF + 1; // 104
// 
// 배열과 포인터
// ★★★★★ 배열의 이름 = 배열의 첫번째 저장 공간의 주소.
// int arr[5] = {1,2,3,4,5}
// arr[0] => *(arr + 0)
// arr // 배열의 첫번째 저장 공간의 주소
// [] 첨자 연산자. (일종의 간접 참조 연산자)
// 포인터에 있는 주소를 찾아가서 쓴다.
// 포인터를 배열처럼 사용할 수 있다.
// 
// 배열과 함수
// 배열을 함수의 매개변수로 사용할 경우, 자동으로 포인터로 변경된다.
// 배열을 함수의 매개 변수로 사용할 때는, 꼭 배열의 길이(크기) 또한 매개변수로 사용하는 것이 좋다.
// 
// scanf_s() :
// name에 &를 안붙이는 이유는 name자체가 배열의 첫 번째 주소를 가지고 있어서다.
// sizeof를 쓰는 이유는 저장공간의 크기를 알려줘서, 만약에 입력한 내용의 양이 저장 공간보다 많을 경우 (일부러 더 큰 문제가 생기기 전에)오류를 낸다.
//

#pragma endregion

// 문자와 문자열
// char 
//
// 입력 버퍼(buffer) : 임시 저장 공간인데 비워야함

void ClearInputBuffer();

// 문자열의 길이를 계산하는 함수 만들기!
int GetStringLength();

int main()
{
	#pragma region 문자
	// 문자 상수(변하지 않는 수)를 작성할 경우, ''작은 따옴표 사용.
	// 문자 데이터 형식은 사실 정수이다!
	// 문자 데이터 형식은 '아스키 코드'로 되어 있다.
	// 아스키(ASCII) 코드 : A(America 미국)SCII : 미국 표준
	// 
	// char : 문자 데이터 형식. 1바이트 정수 데이터 형식.
	//char c = 'A';
	//printf("c = %c\n", c);
	//printf("c = %d\n", c);
	//printf("c + 10 = %c\n", c + 10); // K
	//printf("c + 10 = %d\n", c + 10); // 75
#pragma endregion

	#pragma region 문자 전용 입출력 함수
	// 문자 전용 입출력 함수.
	// (문자 한정으로 기존 입출력 함수보다 빠르다!)
	// getchar() : 문자 전용 입력 함수
	// 반환 값 : 입력한 문자.
	// 
	// putchar([출력할 문자]) : 문자 전용 출력 함수

	/*printf("문자를 입력하세요 : ");
	int c = getchar();
	printf("입력한 문자 : ");
	putchar(c);
	putchar('\n');*/
#pragma endregion 
	
	#pragma region 입력 버퍼
		/*for (int i = 0; i < 4; i++)
		{	
			printf("<%d번째 입력>\n", i + 1);
			printf("문자를 입력하세요 : ");
			int c = getchar();
			printf("입력한 문자 : %c\n\n", c);
			ClearInputBuffer();
		}*/
	#pragma endregion

	#pragma region 문자열의 특징
		// ★★★★★
		// 문자열의 끝에는 항상 'null 문자(\0)'가 들어간다.
		// 'null 문자(\0)'는 말 그대로 문자열의 끝을 의미한다.
		// ('null 문자'가 없다면, 컴퓨터는 문자열의 끝을 확인할 수 없다.)

		/*char textBuffer[5];
		printf("텍스트를 입력하세요 : ");
		scanf_s("%s", textBuffer, (int)sizeof(textBuffer));

		printf("입력한 텍스트 : %s\n", textBuffer);*/
	#pragma endregion 
	
	

	return 0;
}

// 입력 버퍼의 \n을 비우는 함수
void ClearInputBuffer()
{
	int c;
	do
	{
		c = getchar();
	} 
	while (c != '\n');
}

int GetStringLength()
{
	int string[100];
	do
	{
		string = ;
	} while (string != '\0');


	return 
}
