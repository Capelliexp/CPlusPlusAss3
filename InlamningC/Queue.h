#ifndef QUEUE_H
#define QUEUE_H

#include "IQueue.h"
#include <iostream>
#include <string>

template <typename T>
class Queue : public IQueue {
private:
	T **itemArray;
	int pos;
	int arraySize;
	int numberOfElements;
public:
	void Enqueue(const T& element);
	T Dequeue() throw(...);
	T Front() const throw(...);
	bool IsEmpty() const;
	void ExtendArray();

	Queue(Queue &otherQueueObject);
	Queue& operator=(Queue &otherQueueObject);

	Queue();
	~Queue();
};

template <typename T>
void Queue<T>::Enqueue(const T& element) {
	if (numberOfElements == arraySize) {
		ExtendArray();
		itemArray[pos - 1] = element;
	}
	else {
		int arrayPos = pos + numberOfElements;
		if (arrayPos > (arraySize - 1)) {
			arrayPos -= arraySize;
		}
		itemArray[arrayPos] = element;
	}
}

template <typename T>
T Queue<T>::Dequeue() throw(...) {
	T returnItem = itemArray[pos];

	delete[] itemArray[pos];
	numberOfElements--;
	pos++;
	if (pos > (arraySize - 1)) {
		pos = 0;
	}

	return returnItem;
}

template <typename T>
T Queue<T>::Front() const throw(...) {}

template <typename T>
bool Queue<T>::IsEmpty() const {
	if (numberOfElements == 0) {
		return true;
	}
	return false;
}

template <typename T>
void Queue<T>::ExtendArray() {
	T** temp = new T*[arraySize];
	
	for (int i = 0; i < arraySize; i++) {
		temp[i] = itemArray[i];
	}

}

template <typename T>
Queue<T>::Queue(Queue &otherQueueObject) {}

template <typename T>
Queue& Queue<T>::operator=(Queue &otherQueueObject) {}

template <typename T>
Queue<T>::Queue() {
	this->itemArray = new T*[0];
	this->pos = 0:
	this->arraySize = 0;
	this->numberOfElements = 0;
}

template <typename T>
Queue<T>::~Queue() {}

#endif