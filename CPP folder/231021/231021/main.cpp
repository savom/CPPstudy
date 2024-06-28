#pragma region 복습
// C++ 동적 할당
// new(동적 할당), delete(메모리 해제)연산자.
// 
// new (데이터 형식); << 데이터 저장공간 1개를 동적 할당.
// new (데이터 형식)[(칸수)] << 데이터 저장 공간을 (칸 수)만큼 동적 할당.
// 
// float 실수 데이터 저장 공간 1개를 동적 할당
// float* pF = new float;
// 
// int 10칸 짜리 배열을 동적 할당.
// int* arr = new int[10];
// 
// delete 또는 delete[] (동적 할당한 메모리의 주소)
// 
// A::number -> 네임스페이스 A에 있는 number사용
// 
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
// 
// using namespace [네임스페이스 이름]
// [네임스페이스 이름]을 생략할 수 있음.
// 
// 인라인 함수
// 매크로 함수 : #define으로 만드는 함수.
// C++의 매크로 함수
// 함수 앞에 inline을 붙임.
// 컴파일러(visual studio)가 판단해서 자동으로 inline으로 변경하거나 하지 않음.
// 
// 클래스
// C++에서 객체를 만들 때 사용하는 문법
// 구분하다. 나누다. 분류하다.
// 객체 : 담당자.
// C++에서 객체를 만들 떄 사용하는 문법.
// 
// 클래스
// - 데이터(변수)
// - 기능(함수. 메서드)
// 
// 접근 제어 지시자
// private : 클래스 내에서'만' 접근 가능. 
// public : 클래스 내/외부 전부 접근 가능.
// 
// 원칙적으로 클래스 멤버 변수의 접근 제어 지시자는 private으로 설정해야 한다!
// 클래스 외부에서 임의로 멤버 변수의 데이터를 변경할 수 없도록 하기 위함.
// 대신, 멤버 메서드를 통해서 간접적으로 멤버 변수의 데이터를 변경할 수 있다.
//
#pragma endregion
#include <iostream>
using namespace std;
#include "Human.h"

int main()
{
	#pragma region 생성자/소멸자
		// 기존 코드
		/*Human human;
		human.Setdata("홍길동", 24);
		human.Show();
		human.DeleteData();*/

		// 생성자, 소멸자 활용
		//Human human("홍길동", 24); // 생성자 호출!
		//human.Show();

		// 생성자, 소멸자 활용(동적 할당)
		//Human* pHuman = new Human("홍길동", 24); // 생성자 호출
		//pHuman->Show();

		//delete pHuman; // 소멸자 호출!
	#pragma endregion

	// C++의 연산자는 함수와 똑같다!
	//cout << 10;
	// operator<<([매개 변수]) : << 연산자 메서드
	//cout.operator<<(10);

	Human human("홍길동", 24);
	// Human human2(human); // 기본 복사 생성자 호출! => 얕은 복사
	Human human2 = human; // 단순 대입 => 얕은 복사
	human2 = human;

	cout << "< human >" << endl;
	human.Show();
	cout << "< human2 >" << endl;
	human2.Show();



	return 0;
}