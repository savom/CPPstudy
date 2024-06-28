#include "Human.h"

void Human::Setdata(const char* name, int age)
{
	int length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, sizeof(char) * length, name);

	this->age = age;
}

void Human::DeleteData()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}

void Human::Show()
{
	cout << "이름 : " << name << endl;
	cout << "나이 : " << age << "세" << endl;
}

Human& Human::operator=(const Human& copyHuman)
{
	if (name != nullptr) // 현재 내 이름에  무언가 할당되어 있다면
		delete[] name; // 내 이름 메모리 해제.
	
	// 깊은 복사 내용 작성
	// 1. 새로운 메모리를 동적 할당.
	int length = strlen(copyHuman.name) + 1;
	name = new char[length];

	// 2. 할당한 메모리에 실제 데이터 복사.
	strcpy_s(name, sizeof(char) * length, copyHuman.name);

	age = copyHuman.age;
	return *this;
}

Human::Human()
{
	cout << "Human 생성자 호출!" << endl;
}

// 멤버 이니셜라이저 Member Initializer
// Initialize : 초기화.
// <문법> 생성자만 가능
// [생성자] : [멤버 1]([데이터]), [멤버 2]([데이터]) ...
// [멤버]에 [데이터]를 대입.
Human::Human(const char* name, int age) : age(age) // 멤버 이니셜라이저
{
	int length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, sizeof(char) * length, name);

	
}

Human::Human(const Human& copyHuman) : age(copyHuman.age)
{
	// 깊은 복사 내용 작성
	// 1. 새로운 메모리를 동적 할당.
	int length = strlen(copyHuman.name) + 1;
	name = new char[length];
	
	// 2. 할당한 메모리에 실제 데이터 복사.
	strcpy_s(name, sizeof(char) * length, copyHuman.name);

}

Human::~Human()
{
	// cout << "Human 소멸자 호출!" << endl;
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}
