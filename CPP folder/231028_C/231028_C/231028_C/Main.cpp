#include <iostream>
using namespace std;
#include "Student.h"

int main()
{
	Student student("±èÃ¶¼ö", 16, 52);
	Human& refHuman = student;

	// Human human("È«±æµ¿", 20);

	cout << "<student.Show()>" << endl;
	student.Show();
	cout << endl;

	cout << "<refHuman.Show()>" << endl;
	refHuman.Show();
	cout << endl;

	return 0;
}