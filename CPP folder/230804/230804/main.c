#include <stdio.h>

#pragma region 복습
// 함수
// = 기능
// printf() 입력 기능
// scanf_s() 출력 기능.
// main() 
// 
// 1. 함수 선언 : 이러이러한 형식의 함수가 있다!
// [반환 데이터 형식] [함수의 이름] ([매개 변수 목록]);
// 
// 2. 함수 정의 : 함수의 실제 내용을 작성.
// [반환 데이터 형식] [함수의 이름] ([매개 변수 목록])
// {
//		[실행문]들;
//		return [반환 데이터];
// }
// 
// 3. 함수 호출 : 함수를 실행함.
// [함수의 이름]([매개 변수 목록]);
//
#pragma endregion


// 정수를 서로 바꾸는 함수 만들기!
void Swap(int* a, int* b);


void Greeting();
// void : 공허, 텅 빈
// 데이터 형식(= 아무것도 없음을 의미한다.)
// 함수의 [반환 데이터 형식]으로 사용할 경우, 반환 데이터가 없음을 의미한다.
// 또한 해당 함수는 return을 생략할 수 있다.
//
int main()
{

	InputNumberInRange(20,10,11);
	printf("입력한 정수 : %d", InputNumberInRange);
	// Greeting();
	int a = 10, b = 20;
	printf("<변경 전>\n");
	printf("a= %d\n", a);
	printf("b= %d\n", b);

	Swap(a, b);

	printf("<변경 후>\n");
	printf("a= %d\n", a);
	printf("b= %d\n", b);

	return 0;
}

void Swap(int* a, int* b)
{
	int c = a;
	a = b;
	b = c;

	printf("<변경 후>\n");
	printf("a= %d\n", a);
	printf("b= %d\n", b);
}

void Greeting()
{
	printf("안녕하세요!\n");
}


// [최소 값] 이상 ~ [최대 값] 미만의 정수를 입력받고
// 입력받은 정수를 반환하는 함수 만들기!
// 만약에 범위 외의 정수를 입력받으면 반복해서 다시 입력
// 1 ~ 10 57 다시
// InputNumberInPRange

int InputNumberInRange(int a,int b,int c)
{
	
	printf("최대 값을 입력하세요 : ");
	scanf_s("%d", &a);
	printf("최소 값을 입력하세요 : ");
	scanf_s("%d", &b);
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &c);
	while (1)
	{
		if (a <= c && c <= b)
		{
			
			break;
		}
		else
		{
			printf("다시 입력해 주세요.");
			
		}
		return c;
	}
}

// ★★★★
// 함수의 일반적인 매개변수로는
// 다른 함수 안에 있는 변수의 데이터를 변경할 수 없다.