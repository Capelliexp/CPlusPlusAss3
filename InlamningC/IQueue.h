#ifndef IQUEUE_H
#define IQUEUE_H

template <typename T>
class IQueue {
public:
	virtual void Enqueue(const T& element) = 0;
	virtual T Dequeue() throw(...) = 0;
	virtual T Front() const throw(...) = 0;
	virtual bool IsEmpty() const = 0;
};
#endif