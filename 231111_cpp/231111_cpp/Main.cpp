#include <iostream>
#include "ArrayList.h"
using namespace std;


// 배열에 요소를 삽입하는 함수 만들기!
// 1 2 3 4 5 <- 87를 3번째 자리에 삽입.
// 결과 : 1 2 87 3 4 5

// 배열에 요소를 삽입하는 것은
// 컴퓨터 입장에서 매우 어려운 일이다.
// 배열은 나무 서랍장과 비슷하다!
// 배열에 요소 삽입!
// 1. 한 칸 늘린 배열을 새로 할당. -> 나무 서랍장을 새로 구매(비쌈)
// 2. 기존 배열의 데이터를 새로 할당한 배열에 복사 -> 나무 서랍장의 내용물 옮기기(힘듦)
// 3. 요소 삽입
// 4. 기존에 할당한 배열을 메모리에서 해제. -> 나무 서랍장 버리기(힘듦, 비쌈)

// 컴퓨터 입장에서 비싸고 힘듦 => 렉 걸림.

// 배열의 단점
// 배열은 요소를 추가/삭제하는 것이 어렵다.

// 자료 구조.
// 배열 : 기본적인 형태의 자료구조
// 배열 : 여러 개의 저장 공간이 일자로 나열되어 있는 구조

// 템플릿 template
// 클래스나 함수를 찍어내는 틀.
// 데이터 형식을 일반화.

// 넥슨 회원 관리.
// 배열 200만명 + 1 회원
// 1. 200만 + 1칸 짜리 새로운 배열을 할당!
// - 1개의 데이터를 복사하는데 0.00001초라고 가정 20초 걸림
// 2. 기존 배열의 데이터를 새로 할당한 배열에 복사 => 200만의 데이터
// 3. 회원 추가
// 4. 기존의 200만 배열 해제

template<typename T>
void Insert(T** pArr, int length, int index, T value);
//void Insert(int** pArr, int length, int index, int value);


int main()
{
	#pragma region 배열 삽입
		//// arr 안에 동적 할당한 배열 {1,2,3,4,5}의 주소가 있음
		//int* arr = new int[5] {1, 2, 3, 4, 5};
		//cout << "<삽입 전>" << endl;
		//for (int i = 0; i < 5; i++)
		//{
		//	cout << arr[i] << " ";
		//}
		//cout << endl;
		//// &arr은 포인터의 주소를 담고있음.
		//Insert<int>(&arr, 5, 2, 87);

		//cout << "<삽입 후>" << endl;
		//for (int i = 0; i < 6; i++)
		//{
		//	cout << arr[i] << " ";
		//}
		//cout << endl;

		//delete[] arr;

		//char* text = new char[6] {"abcde"};
		//
		//cout << text << endl;
		//
		////Insert(&text, 6, 2, 'A');
		//Insert<char>(&text, 6, 2, 'A');
		//cout << text << endl;

		//delete[] text;
	#pragma endregion	


	// ArrayList 객체 생성
	// count = 0;
	// capacity = 4;
	ArrayList<int> arrayList;
	for (int i = 0; i < 10; i++)
	{
		arrayList.Add(i + 1);
	}

	for (int i = 0; i < arrayList.GetCount(); i++)
	{
		cout << arrayList[i] << " " << endl;
	}

	return 0;
}

//void Insert(int** pArr, int length, int index, int value)
//{	
//	// pArr(부산) = arr의 주소(광주), length = 5, index = 2, value = 87
//
//	// tempArr = 광주
//	int* tempArr = *pArr;
//	// newArr = 서울
//	int* newArr = new int[++length];
//	for (int i = 0; i < length; i++)
//	{
//		// 삽입할 자리가 인덱스보다 작을 경우 그대로 옮김
//		if (i < index)
//			newArr[i] = tempArr[i];
//		// 삽입할 자리가 인덱스와 같을 경우 value값 대입
//		else if (i == index)
//			newArr[i] = value;
//		// 삽입할 자리가 인덱스보다 클 경우 남은 값 대입
//		else
//			newArr[i] = tempArr[i - 1];
//	}
//	
//	 
//	*pArr = newArr;
//	delete[] tempArr;
//	
//}

template<typename T>
void Insert(T** pArr, int length, int index, T value)
{
	// pArr(부산) = arr의 주소(광주), length = 5, index = 2, value = 87

	// tempArr = 광주
	T* tempArr = *pArr;
	// newArr = 서울
	T* newArr = new T[++length];
	for (int i = 0; i < length; i++)
	{
		// 삽입할 자리가 인덱스보다 작을 경우 그대로 옮김
		if (i < index)
			newArr[i] = tempArr[i];
		// 삽입할 자리가 인덱스와 같을 경우 value값 대입
		else if (i == index)
			newArr[i] = value;
		// 삽입할 자리가 인덱스보다 클 경우 남은 값 대입
		else
			newArr[i] = tempArr[i - 1];
	}


	*pArr = newArr;
	delete[] tempArr;

}
