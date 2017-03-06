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

	void Enqueue(const T& element);
	T Dequeue() throw(...);
	T Front() const throw(...);
	bool IsEmpty() const;

	void ExtendArray();
	void PrintQueue() const;

	Queue(Queue &otherQueueObject);
	Queue& operator=(Queue &otherQueueObject);

	Queue(int start);
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
void Queue<T>::Enqueue(const T& element) {
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
T Queue<T>::Dequeue() throw(...) {
	try {
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
			pos = 0;
			throw pos;
		}
	}
	catch (int e) {
		std::cout << "Error: Dequeue of empty queue at pos " << e << std::endl;
		return NULL;
	}
}

template <typename T>
T Queue<T>::Front() const throw(...) {
	try {
		if (numberOfElements != 0) {
			T returnItem = itemArray[pos];
			return returnItem;
		}
		else {
			throw pos;
		}
	}
	catch (int e) {
		std::cout << "Error: Front of empty queue at pos " << e << std::endl;
		return NULL;
	}	
}

template <typename T>
bool Queue<T>::IsEmpty() const {
	if (numberOfElements == 0) {
		return true;
	}
	return false;
}

template <typename T>
void Queue<T>::ExtendArray() {
	T* temp = new T[arraySize + 1];

	/*for (int i = 0; i < arraySize; i++) {
	temp[i] = this->itemArray[i];
	}*/

	for (int i = 0; i < pos; i++) {
		temp[i] = this->itemArray[i];
	}
	for (int i = (pos + 1); i < (arraySize + 1); i++) {
		temp[i] = this->itemArray[i - 1];
	}

	delete[] itemArray;
	this->itemArray = temp;
	//this->itemArray = new T[arraySize + 1];

	/*for (int i = 0; i < pos; i++) {
		this->itemArray[i] = temp[i];
	}
	for (int i = (pos + 1); i < (arraySize + 1); i++) {
		this->itemArray[i] = temp[i - 1];
	}*/

	//delete temp;
	pos++;
	arraySize++;
}

template <typename T>
void Queue<T>::PrintQueue() const {
	int i = pos;
	int loopCount = 0;

	//std::cout << std::endl;
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
Queue<T>::Queue(Queue &otherQueueObject) {
	this->itemArray = new T[otherQueueObject.GetArraySize()];
	this->pos = otherQueueObject.GetPos();
	this->arraySize = otherQueueObject.GetArraySize();
	this->numberOfElements = otherQueueObject.GetNumberOfElements();

	for (int i = 0; i < arraySize; i++) {
		this->itemArray[i] = otherQueueObject.GetItemArray(i);
	}
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue &otherQueueObject) {
	this->itemArray = new T[otherQueueObject.GetArraySize()];
	this->pos = otherQueueObject.GetPos();
	this->arraySize = otherQueueObject.GetArraySize();
	this->numberOfElements = otherQueueObject.GetNumberOfElements();

	for (int i = 0; i < arraySize; i++) {
		this->itemArray[i] = otherQueueObject.GetItemArray(i);
	}
	return *this;
}

template <typename T>
Queue<T>::Queue(int start) {
	if (start < 1) start = 1;

	this->itemArray = new T[start];
	this->pos = 0;
	this->arraySize = start/* + 1*/;
	this->numberOfElements = 0;
}

template <typename T>
Queue<T>::~Queue() {
	//for (int i = 0; i < arraySize; i++) {
	//	delete itemArray[i];
	//}
	delete[] this->itemArray;
}

#endif