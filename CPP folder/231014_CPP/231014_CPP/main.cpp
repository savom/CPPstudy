#include <iostream>
using namespace std;
#include "Human.h"
// 객체 지향 프로그래밍
// 객체(담당자)를 만들고, 만든 객체들 간의 상호작용을 통해서 프로그램을 만드는 것.
// C++ 언어는 객체 지향 프로그래밍이 가능한 언어.

// 객체를 만들 때 사용하는 문법.
// 
// 콘솔 출력 객체
// 
// 클래스 class
// class의 뜻 : 반, 수준, 캐릭터 직업
// 나누다. 구분하다. 분류하다.
// 객체에 관련된 변수나 함수'만' 따로 분류!

// 클래스 구성
// - 데이터(변수)
// - 기능(함수, 메서드)

// 메서드 = 함수
// 메서드 : '이 클래스가 할 수 있는 일'이라는 의미가 강함.
int main()
{
	// human이라는 이름의 Human 클래스 객체를 생성(= 변수 선언. 저장 공간을 만듦).
	Human human; // human 생성
	
	// human의 멤버 변수에 데이터를 대입.
	/*human.name = "홍길동";
	human.age = 82;*/
	human.SetData("홍길동", 24);

	// human의 멤버 메서드 show()를 호출.
	human.Show();

	human.DeleteData();

	return 0; // human 소멸
}