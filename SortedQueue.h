#pragma once
#include "LinkedList.h"
template<typename T>
class SortedQueue
{
public:
	SortedQueue(char printSeparator = ' ');
	SortedQueue(const SortedQueue& other);
	~SortedQueue();
	void Add(T el);
	T Remove(T el);
	T Peek() const;
	int Count() const;
	bool isEmpty() const;
	vector<T> ToVector() const;

	friend ostream& operator<<(ostream& os, const SortedQueue& other)
	{
		os << other.container;
		return os;
	}

private:
	LinkedList<T> container;
};

template<typename T>
SortedQueue<T>::SortedQueue(char printSeparator)
{
	container.setPrintSeparator(printSeparator);
}

template<typename T>
SortedQueue<T>::SortedQueue(const SortedQueue& other)
{
	container = other.container;
}

template<typename T>
SortedQueue<T>::~SortedQueue()
{
}

template<typename T>
void SortedQueue<T>::Add(T el)
{
	container.insertSorted(el);
}

template<typename T>
T SortedQueue<T>::Remove(T el)
{
	return container.remove(el);
}

template<typename T>
T SortedQueue<T>::Peek() const
{
	return container.peek();
}

template<typename T>
int SortedQueue<T>::Count() const
{
	return container.getSize();
}

template<typename T>
bool SortedQueue<T>::isEmpty() const
{
	return container.isEmpty();
}

template<typename T>
vector<T> SortedQueue<T>::ToVector() const
{
	return container.toVector(); 
}
