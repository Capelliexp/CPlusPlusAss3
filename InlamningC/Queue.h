#ifndef QUEUE_H
#define QUEUE_H

#include "IQueue.h"
#include <iostream>
#include <string>

template <typename T>
class Queue : IQueue<T> {
private:
	T *itemArray;
	int pos;
	int arraySize;
	int numberOfElements;
public:
	T GetItemArray(int i) const;
	int GetPos() const;
	int GetArraySize() const;
	int GetNumberOfElements() const;

	void enqueue(const T& element);
	T dequeue() throw(...);
	T front() const throw(...);
	bool isEmpty() const;

	void ExtendArray();
	void PrintQueue() const;

	Queue(const Queue &otherQueueObject);
	Queue& operator=(const Queue &otherQueueObject);

	Queue(const int start = 1);
	~Queue();
};

template <typename T>
T Queue<T>::GetItemArray(int i) const {
	return itemArray[i];
}

template <typename T>
int Queue<T>::GetPos() const {
	return pos;
}

template <typename T>
int Queue<T>::GetArraySize() const {
	return arraySize;
}

template <typename T>
int Queue<T>::GetNumberOfElements() const {
	return numberOfElements;
}

template <typename T>
void Queue<T>::enqueue(const T& element) {
	if (numberOfElements == arraySize) {
		ExtendArray();
		int arrayPos1 = pos - 1;
		if (arrayPos1 == -1) {
			arrayPos1 = arraySize - 1;
		}
		itemArray[arrayPos1] = element;
	}
	else {
		int arrayPos2 = pos + numberOfElements;
		if (arrayPos2 > (arraySize - 1)) {
			arrayPos2 -= arraySize;
		}
		itemArray[arrayPos2] = element;
	}
	numberOfElements++;
}

template <typename T>
T Queue<T>::dequeue() throw(...) {
	if (numberOfElements > 0) {
		T returnItem = itemArray[pos];
		itemArray[pos] = NULL;
		numberOfElements--;
		pos++;
		if (pos > (arraySize - 1)) {
			pos = 0;
		}
		return returnItem;
	}
	else {
		int oldPos = pos;
		pos = 0;
		throw oldPos;
	}
}

template <typename T>
T Queue<T>::front() const throw(...) {
	if (numberOfElements != 0) {
		T returnItem = itemArray[pos];
		return returnItem;
	}
	else {
		throw pos;
	}	
}

template <typename T>
bool Queue<T>::isEmpty() const {
	if (numberOfElements == 0) {
		return true;
	}
	return false;
}

template <typename T>
void Queue<T>::ExtendArray() {
	T* temp = new T[arraySize + 1];

	for (int i = 0; i < pos; i++) {
		temp[i] = this->itemArray[i];
	}
	for (int i = (pos + 1); i < (arraySize + 1); i++) {
		temp[i] = this->itemArray[i - 1];
	}

	delete[] itemArray;
	this->itemArray = temp;

	pos++;
	arraySize++;
}

template <typename T>
void Queue<T>::PrintQueue() const {
	int i = pos;
	int loopCount = 0;

	while (loopCount < numberOfElements) {
		std::cout << "Element " << (loopCount + 1) << ": " << itemArray[i] << std::endl;
		i++;
		loopCount++;

		if (i > (arraySize - 1)) {
			i = 0;
		}
	}
}

template <typename T>
Queue<T>::Queue(const Queue &otherQueueObject) {
	this->itemArray = new T[otherQueueObject.GetArraySize()];
	this->pos = otherQueueObject.GetPos();
	this->arraySize = otherQueueObject.GetArraySize();
	this->numberOfElements = otherQueueObject.GetNumberOfElements();

	for (int i = 0; i < arraySize; i++) {
		this->itemArray[i] = otherQueueObject.GetItemArray(i);
	}
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue &otherQueueObject) {
	if (&otherQueueObject != this) {
		delete[] this->itemArray;

		this->itemArray = new T[otherQueueObject.GetArraySize()];
		this->pos = otherQueueObject.GetPos();
		this->arraySize = otherQueueObject.GetArraySize();
		this->numberOfElements = otherQueueObject.GetNumberOfElements();

		for (int i = 0; i < arraySize; i++) {
			this->itemArray[i] = otherQueueObject.GetItemArray(i);
		}
	}
	return *this;
}

template <typename T>
Queue<T>::Queue(const int start = 1) {
	int startValue = start;
	if (startValue < 1) startValue = 1;

	this->itemArray = new T[startValue];
	this->pos = 0;
	this->arraySize = startValue;
	this->numberOfElements = 0;
}

template <typename T>
Queue<T>::~Queue() {
	delete[] this->itemArray;
}

#endif