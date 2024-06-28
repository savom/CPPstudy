#include "Human.h"

//void Human::Show()
//{
//	cout << "이름 : " << name << endl;
//	cout << "나이 : " << age << "세" << endl;
//}

Human::Human(const char* name, int age) : age(age)
{
	int length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, sizeof(char) * length, name);
}

Human::~Human()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}
