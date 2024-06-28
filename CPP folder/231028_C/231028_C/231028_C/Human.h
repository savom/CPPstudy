#pragma once
#include <iostream>
using namespace std;

// 가상 메서드.
// 가상 메서드를 재정의할 경우, '항상' 재정의한 메서드를 호출!
// 메서드 앞에 virtual 키워드를 붙임.

// 추상(순수 가상) 메서드
// 내용이 없는 가상 메서드.
// (가상 메서드) = 0;

// 추상 메서드는 '반드시' 자식 클래스에서 재정의해야 한다.

// 추상 클래스
// 추상 메서드를 1개 이상 가진 클래스.
// 추상 클래스는 완성된 클래스가 아니므로, 객체를 생성할 수 없다!(클래스 변수를 만들 수 없음.)

class Human
{
// private:
protected:
	char* name;
	int age;

public:
	// void Show(); // 일반 메서드
	// virtual void Show(); // 가상 메서드
	virtual void Show() = 0; // 추상 메서드
public:
	Human(const char* name, int age);
	~Human();
};

