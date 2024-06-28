#include "Human.h"

void Human::SetData(const char* name, int age)
{
	// this : 이것
	// 나 자신 객체의 포인터.
	
	int length = strlen(name) + 1;
	
	// this->name : 나 자신 객체의 name(멤버 변수 name)

	this->name = new char[length];
	strcpy_s(this->name, sizeof(char) * length, name);

	this->age = age;

	
}

void Human::DeleteData()
{
	// nullptr : null + ptr(pointer 포인터) 널 포인터
	// = (void*)0. 주소 값으로서의 0
	// 포인터에 "아무것도 없음"이라는 의미를 가진다.

	// name 안에 저장된 주소가 "아무것도 없음"이 아니면
	// = name에 동적 할당이 정상적으로 이루어 졌다면
	if (name != nullptr)
	{
		// name에 해당하는 주소에 있는 메모리 해제.
		delete[] name;
		name = nullptr;
	}
	
}

void Human::Show()
{
	cout << "이름 : " << name << endl;
	cout << "나이 : " << age << "세" << endl;

}
