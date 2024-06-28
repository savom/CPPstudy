#pragma once
#include <iostream>
using namespace std;

// 템플릿으로 구현한 '동적 배열' 클래스.
// 동적 배열 : 유동적으로 길이가 증가하는 배열.
// 저장 공간에 여유를 두는 배열.

// 배열 vs 동적 배열
// 장점 : 동적 배열은 메모리 할당 횟수가 비교적 적다.
// 단점 : 동적 배열은 사용하지 않는 메모리가 생길 수 있음.


// ArrayList 객체 생성
template<typename T>
class ArrayList
{
private:
	T* data;

private :
	int count;
	int capacity;

public:
	void Add(const T& item);
	T& operator[](int index); // [] 첨자 연산자 오버로딩.

public:
	int GetCount();
	int	GetCapacity();

public:
	ArrayList();
	~ArrayList();

};

// 템플릿 클래스의 메서드는
// 반드시 헤더 파일에 정의해야 한다!!

template<typename T>
inline void ArrayList<T>::Add(const T& item) // 배열에 요소를 추가하는 메서드
{
	if (count >= capacity)
	{
		capacity <<= 1; // capacity *= 2;
		// capacity = capacity << 1
		T* newArr = new T[capacity];
		// memcpy_s() : mem(memory) + cpy(copy) 메모리 목사 함수.
		// memcpy_s([목적지], [목적지 크기], [원본], [원본 크기])
		memcpy_s(newArr, sizeof(T) * capacity, data, sizeof(T) * count);
		delete[] data;
		data = newArr;
	}
	data[count++] = item;
	
}
// ArrayList 객체 생성

template<typename T>
inline T& ArrayList<T>::operator[](int index)
{
	if (index >= count || index < 0) // 예외 처리.
	{
		cout << "index의 범위가 벗어났습니다.(index : " << index << ")" << endl;
		exit(1);
	}
	return data[index];
}

template<typename T>
inline int ArrayList<T>::GetCount()
{
	return count;
}

template<typename T>
inline int ArrayList<T>::GetCapacity()
{
	return capacity;
}

// count = 0;
// capacity = 4;
template<typename T>
inline ArrayList<T>::ArrayList()
	: count(0), capacity(4)
{
	data = new T[capacity];
}

template<typename T>
inline ArrayList<T>::~ArrayList()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}
