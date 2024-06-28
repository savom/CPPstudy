#include <stdio.h>

#pragma region 복습
// break, continue
// 반복문에서의 break : 실행문을 실행하는 도중 break를 만나면 즉시 반복문 종료.
// 
// 반복문에서의 continue
// while문 continue : 실행문을 실행하는 도중 continue를 만나면 [논리 값]으로 이동.
// for문 continue : 실행문을 실행하는 도중 continue를 만나면 [실행문 2]으로 이동.
// 
// do ~ while
// <문법>
// do
//  [실행문] 1개.
// while([논리 값]);
// 
// 1. [실행문] 실행
// 2. [논리 값] 확인
// 3. [논리 값]이 참이면 1.로 돌아가 반복. 거짓이면 종료.
// 
// 배열
// 여러 개의 저장 공간이 줄을 지어 나열되어 있는 구조.
// <문법>
// (데이터 형식) (배열의 이름)[(칸수)];
// ex. float fArr[48]; 
// fArr이라는 실수 데이터 저장 공간 48칸짜리 배열을 만들어라!
// 배열은 {}중괄호 초기화가 가능하다.
// {}중괄호 초기화 시, 초기화 하지 않은 부분은 전부 0으로 초기화된다.
// float fArr[48] = {1,2,3};
// 
// 배열의 저장 공간 번호는 0부터 시작한다.
// fArr[2]
// fArr의 3번째 저장공간
//
#pragma endregion

// 함수.
// 함(상자) + 수(숫자) = 상자(기계 장치) 숫자.
// function 기능
// 
// 그동안 사용했던 기능(=함수)들
// printf() : 출력 기능
// scanf_s() : 입력 기능
// main() : 
// 
// <문법>
// 1. 함수 선언 :이러이러한 형식의 함수가 있다! 라고 말하는 것.
// [반환 데이터 형식] [함수의 이름]([매개 변수 목록]);
// 
// 2. 함수 정의 : 함수의 실제 내용을 작성.
// [반환 데이터 형식] [함수의 이름]([매개 변수 목록]);
// {
//		[실행문]들
//		return [반환 데이터];
// }
// 
// 3. 함수 호출(= 함수 실행)
// [함수의 이름]([매개 변수들]);
//

// 1. 함수 선언
int Add(int a, int b);

// 빼기(Sub), 곱하기(Mul), 나누기(Div) 함수 만들기
int Sub(int a, int b);
float Mul(float a, float b);
float Div(float a, float b);

// 정수를 입력받고, 입력받은 정수를 반환하는 함수 만들기!
// InputNumber
int InputNumber();

// [최소 값] 이상 ~ [최대 값] 미만의 정수를 입력받고
// 입력받은 정수를 반환하는 함수 만들기!
// 만약에 범위 외의 정수를 입력받으면 반복해서 다시 입력
// 1 ~ 10 57 다시
// InputNumberInPRange
int InputNumberInRange();

int main() 
{
#pragma region 사칙연산 함수
	// 3. 함수 호출
	/*int result = Add(10, 20);
	printf("Add(10, 20) = %d\n", result);
	
	int sub = Sub(20, 10);
	printf("sub(20, 10) = %d\n", sub);

	float mul = Mul(5, 2);
	printf("mul(5, 2) = %.2f\n", mul);
	
	float div = Div(20, 4);
	printf("div(20, 4) = %.2f\n", div);*/
#pragma endregion
	
	//int a = 0;
	//// 만든 함수로 정수를 입력 받은 후, 그 정수를 출력
	//int inputNum = InputNumber();
	//printf("출력한 정수 : %d", inputNum);

	int number = InputNumberInRange(0, 100);
	printf("입력한 정수 : %d\n", number);

	return 0;
}

// 2. 함수 정의
int Add(int a, int b)
{
	int result = a + b;

	return result;
}

int Sub(int a, int b)
{
	int result = a - b;

	return result;
}

float Mul(float a, float b)
{
	float result = a * b;
	return result;
}

float Div(float a, float b)
{
	// return이  실행되면, 함수의 결과가 반환되면서 종료.
	if (b == 0)
	{
		// 예외처리!
		printf("0으로 나눌 수 없습니다!\n");
		return 0;
	}
	float result = a / b;
	return result;
}

int InputNumber()
{
	int a;
	printf("정수를 입력해 주세요 : ");
	scanf_s("%d", &a);
	return a;
}

// [최소 값] 이상 ~ [최대 값] 미만의 정수를 입력받고
// 입력받은 정수를 반환하는 함수 만들기!
// 만약에 범위 외의 정수를 입력받으면 반복해서 다시 입력
// 1 ~ 10 57 다시
// InputNumberInPRange

int InputNumberInRange(int min, int max)
{
	/*int a = 0; 다시 풀어보기!!
	int b = 0;
	int c = 0;
	printf("최대 값을 입력하세요 : ");
	scanf_s("%d", &a);
	printf("최소 값을 입력하세요 : ");
	scanf_s("%d", &b);
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &c);
	while (a <= c && c <= b)
	{
		if (a <= c && c <= b)
			printf("입력한 정수 : %d", c);
			break;
		case 0:
			printf("다시 입력해 주세요.");

	}*/

	int number;
	while (1)
	{
		printf("정수를 입력하세요(%d ~ %d) : ", min, max);
		scanf_s("%d", &number);
		if (min <= number && number <= max)
		{
			break;
		}
		else
		{
			printf("잘못된 입력입니다.\n");
		}
		return number;
	}
	
	
	
	return 0;
}
