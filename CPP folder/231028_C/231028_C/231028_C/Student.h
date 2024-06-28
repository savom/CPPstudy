#pragma once
#include "Human.h"

class Student : public Human
{
private:
	int score;

public:
	void Show(); // 부모 클래스의 Show()를 재정의

public:
	Student(const char* name, int age, int score);
	// (생성자) = default 또는
	// (소멸자) = default
	// : 아무것도 실행하지 않는 기본 생성자/소멸자를 사용하겠다! 라는 의미.
	~Student() = default;
};

