#pragma once
#include <iostream>
using namespace std;


// 일반적인 클래스
//class Human
//{
//protected:
//	const char* name;
//
//public:
//	void Show();
//
//public:
//	Human(const char* name);
//	~Human();
//};

// 인터페이스 클래스
class Human
{
public:
	virtual void Show() = 0;


};

