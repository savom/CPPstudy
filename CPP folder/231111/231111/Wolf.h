#pragma once
#include <iostream>
using namespace std;

// 일반적인 클래스
//class Wolf
//{
//protected:
//	const char* name;
//
//public:
//	void Show();
//
//public:
//	Wolf(const char* name);
//	~Wolf();
//};

// 인터페이스 클래스
class Wolf
{
public:
	virtual void Show() = 0;
};

