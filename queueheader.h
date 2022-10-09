#pragma once
#include <iostream>
using namespace std;

template <class T> 
class Queue {
private:
	int size;
	T* Qarr;
	int front;
	int back;

public:

	Queue(int s);
	void push(T a);
	T getfront();
	void pop();
};

template <class T>
Queue <T> ::Queue(int s) {
	size = s;
	Qarr = new T[size];
	front = 0;
	back = 0;
}

template <class T>
void Queue <T>::push(T a) {
		Qarr[back] = a;
		back = back + 1;
}

template <class T>
void Queue <T> ::pop() {


	front = front + 1;

}

template <class T>
T Queue <T> ::getfront() {

	return Qarr[front];
}