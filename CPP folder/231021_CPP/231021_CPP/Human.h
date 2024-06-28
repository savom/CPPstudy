#pragma once
#include <iostream>
using namespace std;

// 클래스 상속
// 상속 : 재산, 돈 등을 물려주는 일.
// : 부모 클래스가 자식 클래스에게 모든 데이터와 기능을 물려주는 것.

// class [클래스 이름] : public [부모 클래스 이름]

class Human
{
private:
	char* name;
	int age;

public:
	void Show();

public:
	Human(const char* name, int age);
	~Human();
};

