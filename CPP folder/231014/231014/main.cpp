#include <iostream>
using namespace std;

#pragma region 복습
// C+++ 입력/출력
// C 언어 : <stdio.h> : 표준 입출력 헤더 파일.
// C++ : <iostram> : 입출력 관련 헤더 파일.
// 
// cout : 콘솔 출력을 담당하는 객체(=담당자).
// 변환 문자를 사용할 필요가 없음.
// ex. cout << "홍길동" << endl;
// 
// cin : 콘솔 입력을 담당하는 객체
// ex. cin >> [변수 이름] 
// 
// bool : 논리 값 데이터 형식.
// bool b = true(1) 또는 false(0);
// 
// 참조자
// 저장 공간에 별명을 붙이는 것.
// [데이터 형식]& [참조자 이름] = [변수 이름]
// [변수]에 [참조자 이름]이라는 별명을 붙인다!
// 
// float f;
// float& refFloat = f;
// : f라는 저장 공간에 refFloat라는 별명을 붙인다.
// 
// 포인터를 대체하기 위해서 나온 문법.
// 참조자 매개변수를 통해서 다른 함수에 있는 변수의 데이터를 변경할 수 있다.
// 
// 함수 오버로딩
// 같은 이름을 가진 함수를 사용할 수 있다.
// 조건 : 함수의 매개변수 형식이 달라야 한다.
//
#pragma endregion

// 매크로 함수 : #define으로 만든 함수.
// 장점 : 일반적인 함수보다 훨씬 빠르다.

// 인라인 함수 
// C++의 매크로 함수.
// 함수 선언부 앞에 inline을 붙임.
// inline이 붙은 함수는 자동으로 매크로 함수로 변경된다.
// 단, inline이 붙은 모든 함수가 매크로 함수로 변경되는 것은 아니고,
// 매크로 함수로 변경하기 적합한 함수'만' 컴파일러(Visual Studio)가 판단하여 변경.

inline int Mul(int a, int b);
 
// namespace 네임스페이스
// : 코드를 나누는 공간.
// 코드(변수, 함수 등)를 공간 별로 나눠서
// 같은 이름을 가진 변수 또는 함수를 구분할 수 있음.

// <문법>
// namespace [이름]
//{
//		[변수]들
//		[함수]들
//}

// [네임스페이스 이름]::[변수] 또는 [메서드]
// : 해당 [네임 스페이스] 안에 있는 [변수] 또는 [메서드]
// [네임스페이스 이름]을 쓰지 않고 ::만 쓸 경우
// 전역 공간(전역 네임스페이스)을 의미한다.

// using namespace [이름]
// : [이름]에 해당하는 네임스페이스를 사용하겠다!
// 해당 네임스페이스 안에 있는 변수, 메서드를 사용할 때
// [네임스페이스 이름]을 생략할 수 있다.
// 만약에 이름이 겹칠 경우에는, '반드시' [네임스페이스 이름]을 명시해야 한다.(생략 불가)

// std::cout : std안에 있는 cout을 사용하겠다.(::)


// 전역 변수 : 프로그램 전체에서 사용할 수 있는 변수.
//int number;

namespace AAA
{
	int number = 10;
}

namespace BBB
{
	int number = 20;
}
using namespace AAA;
using namespace BBB;
int number = 30;

int main()
{
	// cout << "number = " << number << endl;
	cout << "number = " << ::number << endl; // :: 전역 공간(전역 네임스페이스)
	cout << "AAA::number = " << AAA::number << endl;
	cout << "BBB::number = " << BBB::number << endl;
	return 0;
}

inline int Mul(int a, int b)
{
	return a * b;
}
