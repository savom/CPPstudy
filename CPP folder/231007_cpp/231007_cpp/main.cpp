#include <iostream>
// <iostream> : io(input, output)stream 입출력 관련 헤더.

using namespace std;
// std라는 이름의 네임스페이스(namespace)를 사용하겠다.
// namespace : name(이름) + space(공간)
// = 코드를 나누는 공간.

// 숫자 바꾸기 함수 swap

// 함수 오버로딩(Overloading)
// 똑같은 이름을 가진 함수를 여려 개 만들 수 있다!
// ★★★단, 각 함수의 매개 변수 형식이 반드시 달라야 한다.

// 똑같은 이름을 가진 함수가 여러 개 있을 경우
// 컴퓨터는 일단 똑같은 이름을 가진 모든 함수를 불러온다.
// 그 후, 형식을 비교해서 해당 형식과 똑같은 함수를 호출!

// 매개 변수로 구분할 수 없는 경우, 함수 오버로딩이 불가능.

void Swap(int *a, int *b);
void Swap(int& refA, int& refB);
void Swap(int a, int b);

int main()
{
#pragma region CPP 출력
	//// C언어 스타일
	//// printf("Hello world");

	//// cout : c(console 콘솔(도스 창)) + out(output 출력)
	//// : 콘솔 출력을 담당하는 '객체'(= 담당자)

	//// cout에게 "hello world와 endl를 출력하라고 보냄.
	//// cout은 콘솔 출력 담당자이므로, 해당 내용을 출력.

	//// endl : end + l(line) 줄의 끝. \n
	//cout << "Hello World!";
	//cout << "Hello World!" << endl;
#pragma endregion

#pragma region C vs C++ 출력
//// 변수 출력
//// char* name = "홍길동";
//// const : 상(항상 상)수. 변하지 않는 숫자.
//// const로 표시된 변수는 초기화 이후, 데이터를 변경할 수 없음!

//// C++부터는 상수/변수의 구분이 엄격하므로,
//// 해당 데이터가 상수일 경우 반드시 const를 붙여야 한다.
//// "홍길동" => 문자열 상수.

//const char* name = "홍길동";
//// name[0] = 'A'; (x)

//int age = 24;
//float height = 175.34f;

//// C언어 스타일
//// 변수를 출력할 경우, 변환 문자를 사용해야 한다!
///*printf("이름 : %s\n", name);
//printf("나이 : %d세\n", age);
//printf("키 : %.2fcm\n", height);*/

//// C++ 스타일
//// 변수를 출력할 경우, 변환 문자를 사용할 필요가 없다.
//// cout은 콘솔 출력 담당자이므로,
//// 변수를 출력할 경우, '알아서' 데이터 형식에 맞춰 출력.
//cout << "이름 : " << name << endl;
//cout << "나이 : " << age << "세" << endl;
//cout << "키 : " << height << "cm" << endl;
#pragma endregion

#pragma region C vs C++ 입력
//// 변수 입력
//// 이름을 입력받는 코드 작성!
//char name[30];
//
//// C언어 스타일
///*printf("이름을 입력하세요 : ");
//scanf_s("%s", name, sizeof(name));
//printf("입력한 이름 : %s\n", name);*/

//// C++ 스타일
//cout << "이름을 입력하세요 :";
//
//// cin : c(console) + in(input)
//// : 콘솔 입력을 담당하는 객체.
//// cin이 입력받은 내용을 name으로 보냄.
//// 변환 문자, 주소 연산자를 사용할 필요가 없음.
//cin >> name;
//cout << "입력한 이름 : " << name << endl;
#pragma endregion


	// C++의 추가/변경점.

#pragma region bool
	// 논리 값 데이터 형식 bool
	// 논리 값(true, false)을 저장할 수 있음.
	// true = 1;
	// false = 0;
	/*bool b = true;
	cout << "b = " << b << endl;

	b = false;
	cout << "b = " << b << endl;*/
#pragma endregion

#pragma region 참조자
	// 참조자
	// 저장 공간에 별명을 붙이는 것.
	// <문법>
	// [데이터 형식]& [참조자 이름] = [변수 이름];
	// : [변수]에 [참조자 이름]이라는 별명을 붙임.
	// 이후로, [변수 이름] 대신 [참조자 이름]을 사용할 수 있음.

	//int a = 10;

	//// a라는 저장 공간에 refNum이라는 별명을 붙인다.
	//int& refNum = a;
	//refNum = 20;
	//cout << "<변경 전>" << endl;
	//cout << "a = " << a << endl; // 10
	//cout << "refNum = " << refNum << endl; // 10
	//
	//refNum = 78;
	//
	//cout << "<변경 후>" << endl;
	//cout << "a = " << a << endl; // 78
	//cout << "refNum = " << refNum << endl; // 78

#pragma endregion

#pragma region 참조자 활용
//int a = 10, b = 20;
//cout << "<변경 전>" << endl;
//cout << "a = " << a << endl;
//cout << "b = " << b << endl;

//////Swap(&a, &b); // 포인터 활용
//Swap(a, b); // 참조자 활용
//
//// ★★★★★★
//// 포인터와 비슷하게,
//// 참조자 매개 변수를 사용할 경우
//// 다른 함수에 있는 변수의 데이터를 변경할 수 있다.!
//// ex. cin의 입력 기능.	

//cout << "<변경 후>" << endl;
//cout << "a = " << a << endl;
//cout << "b = " << b << endl;

/*int a;
cin >> a;*/

#pragma endregion 

// C++의 동적 할당.
// 
// 이름을 입력받는 코드 작성!(동적 할당)

#pragma region C언어 동적할당
//// C언어 스타일
//// malloc()
//// 반환 데이터 : 방금 새로 할당한 메모리의 주소.
//	char* nameBuffer = (char*)malloc(200); // 임시 저장 공간
//	printf("이름을 입력하세요 : ");
//	scanf_s("%s", nameBuffer, 200); //
//
//	int len = strlen(nameBuffer) + 1;
//	char* name = (char*)malloc(sizeof(char) * len);
//	strcpy_s(name, sizeof(char)* len, nameBuffer);
//
//	free(nameBuffer);
//
//	printf("입력한 이름 : %s\n", name);
//
//	free(name);
#pragma endregion


// C++ 스타일
// new : 메모리를 동적 할당하는 연산자.
// new (데이터 형식)[(칸 수)]; - 배열 동적 할당
// 또는
// new (데이터 형식); - 변수 동적 할당

// delete : 동적 할당한 메모리를 해제하는 연산자.
// delete[] : 동적 할당한 배열을 해제.
// delete : 동적 할당한 변수를 해제.

	char* nameBuffer = new char[200];
	// char* nameBuffer = (char*)malloc(sizeof(char) * 200);


	cout << "이름을 입력하세요 : ";
	cin >> nameBuffer;

	int length = strlen(nameBuffer) + 1;
	char* name = new char[length];
	strcpy_s(name, sizeof(char)* length, nameBuffer);

	delete[] nameBuffer;

	cout << "입력한 이름 : " << name << endl;

	delete[] name;

	return 0;
}

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void Swap(int& refA, int& refB)
{
	int c = refA;
	refA = refB;
	refB = c;
}
