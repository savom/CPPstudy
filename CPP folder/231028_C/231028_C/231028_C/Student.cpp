#include "Student.h"

void Student::Show()
{
	/*Human::Show();*/
	cout << "이름 : " << name << endl;
	cout << "나이 : " << age << "세" << endl;
	cout << "점수 : " << score << "점" << endl;
}

Student::Student(const char* name, int age, int score)
	: Human(name, age), score(score)
{
}
