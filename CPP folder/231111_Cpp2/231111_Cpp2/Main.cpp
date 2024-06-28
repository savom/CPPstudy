#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

// 자료구조 클래스
// - vector<T> : 동적 배열 클래스
// 
// - queue<T> 큐 : 선입선출 자료구조
// 선입선출 : 먼저 들어온 요소가 먼저 나감.
// 
// - stack<T> : 선입후출 자료구조.
// stack 스택 : 쌓다.
// 선입후출 : 먼저 들어온 요소가 가장 나중에 나감.
// 
// queue나 stack도 capacity가 늘어날 수 있음.
// 
// - map<TKey, TValue>
// : Key와 Value의 쌍으로 이루어진 요소를 저장하는 자료구조.
//
int main()
{
	#pragma region vector 클래스
		//vector<int> myVector;
		//for (int i = 0; i < 10; i++)
		//{
		//	// vector<T>.push_back() : 동적 배열에 요소를 추가하는 메서드.
		//	myVector.push_back(i + 1);
		//	cout << "요소의 개수 : " << myVector.size() << endl;
		//	cout << "실제 배열의 길이 : " << myVector.capacity() << endl;
		//}
		//
		//// vector<T>.size() : 요소의 개수를 반환하는 메서드.
		//for (int i = 0; i < myVector.size(); i++)
		//{
		//	cout << myVector[i] << " ";
		//}
		//cout << endl;
	#pragma endregion 

	#pragma region queue 클래스
		queue<char> myQueue;
		for (char c = 'A'; c <= 'D'; c++)
		{
			// queue<T>.push([요소]) : [요소]를 추가하는 메서드.
			myQueue.push(c);
		}
	
		// queue<T>.size() : 요소의 개수를 반환하는 메서드.
		while (myQueue.size() > 0)
		{
			// queue<T>.front() : front(앞). 맨 앞에 있는 요소를 반환.
			cout << "꺼낸 요소 : " << myQueue.front() << endl;

			// queue<T>.pop() : 맨 앞에 있는 요소를 꺼내는 메서드.
			myQueue.pop();
		}

		// myQueue[0] = 'c'; <- 안됌.
	#pragma endregion	

	#pragma region stack 클래스
			stack<float> myStack;

			// stack<T>.push() : 요소를 추가하는메서드.
			myStack.push(25.41f);
			myStack.push(-52.10f);
			myStack.push(100.17f);

			while (myStack.size() > 0)
			{
				// stack<T>.top() : 맨 위(맨 마지막)의 요소를 반환하는 메서드.
				cout << "꺼낸 요소 : " << myStack.top() << endl;
				myStack.pop();
			}

	#pragma endregion

	#pragma region map 클래스
		map<char, int> myMap;
		// map<TKey, TValue>.insert() : 요소를 추가하는 메서드
		// ※ 요소를 추가할 시, Key가 중복되어서는 안된다!
		myMap.insert({ 'A',78 });
		myMap.insert({ 'B',983 });
		myMap.insert({ 'C',395 });
		myMap.insert({ 'X',-825 });

		// map[(Key)] : (Key)에 해당하는 Value를 반환
		cout << "myMap['A'] = " << myMap['A'] << endl;
		cout << "myMap['B'] = " << myMap['B'] << endl;
		cout << "myMap['C'] = " << myMap['C'] << endl;
		cout << "myMap['X'] = " << myMap['X'] << endl;

		myMap['A'] = 11;
		cout << "myMap['A'] = " << myMap['A'] << endl;
#pragma endregion

	return 0;
}