#pragma once
#include <vector>
template<typename T>
struct Node {
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node(T data)
	{
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};
template<typename T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T>&);
	~LinkedList();
	void insertStart(T el);
	void insertEnd(T el);
	void insertBefore(T new_el, T el);
	void insertSorted(T el);
	T remove(T el);
	bool isEmpty() const;
	T peek() const;
	int getSize() const;
	void setPrintSeparator(char separator);
	vector<T> toVector() const;
	T* LocateElement(T el) const;
	
	friend ostream& operator<<(ostream& os, const LinkedList<T>& list)
	{
		Node<T>* temp = list.head;
		while (temp != nullptr)
		{
			os << temp->data << list.printSeparator << "->" << list.printSeparator;
			temp = temp->next;
		}
		os << "END" << list.printSeparator;
		return os;
	}

private:
	Node<T>* find(T el) const;
	void insertBefore(T new_el, Node<T>* el);
	void remove(Node<T>* el);
	Node<T>* head;
	Node<T>* tail;
	char printSeparator;
	int count;
};

template<typename T>
LinkedList<T>::LinkedList()
{
	printSeparator = ' ';
	head = nullptr;
	tail = nullptr;
	count = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>&)
{
	// deep copy all elements
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		insertEnd(temp->data);
		temp = temp->next;
	}
}

template<typename T>
void LinkedList<T>::setPrintSeparator(char separator)
{
	printSeparator = separator;
}

template<typename T>
vector<T> LinkedList<T>::toVector() const
{
	vector<T> vec;
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		vec.push_back(temp->data);
		temp = temp->next;
	}
	return vec;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	while (!isEmpty())
	{
		remove(peek());
	}
}

template<typename T>
void LinkedList<T>::insertStart(T el)
{
	Node<T>* temp = new Node<T>(el);
	temp->next = head;
	if (head != nullptr)
	{
		head->prev = temp;
	}
	head = temp;
	count++;

	if (count == 1)
	{
		tail = head;
	}
}

template<typename T>
void LinkedList<T>::insertEnd(T el)
{
	Node<T>* temp = new Node<T>(el);
	temp->prev = tail;
	if (tail != nullptr)
	{
		tail->next = temp;
	}
	tail = temp;
	count++;

	if (count == 1)
	{
		head = tail;
	}
}

template<typename T>
void LinkedList<T>::insertBefore(T new_el, T el)
{
	insertBefore(new_el, find(el));
}


template<typename T>
void LinkedList<T>::insertSorted(T el)
{
	Node<T>* temp = head;
	while (temp != nullptr && temp->data < el)
	{
		temp = temp->next;
	}
	if (temp == nullptr)
	{
		insertEnd(el);
	}
	else if (temp == head)
	{
		insertStart(el);
	}
	else 
	{
		insertBefore(el, temp);
	}
}

template<typename T>
T LinkedList<T>::remove(T el)
{
	Node<T>* temp = find(el);
	if (temp != nullptr)
	{
		T data = temp->data;
		remove(temp);
		return data;
	}
	else
	{
		return T();
	}
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
	return count == 0;
}

template<typename T>
T LinkedList<T>::peek() const
{
	return head->data;
}

template<typename T>
int LinkedList<T>::getSize() const
{
	return count;
}

template<typename T>
Node<T>* LinkedList<T>::find(T el) const
{
	Node<T>* temp = head;
	while (temp != nullptr && temp->data != el)
	{
		temp = temp->next;
	}

	return temp;
}
template<typename T>
T* LinkedList<T>::LocateElement(T el) const
{
	Node<T>* temp = find(el);
	if (temp != nullptr)
	{
		return &temp->data;
	}
	else
	{
		return nullptr;
	}
}

template<typename T>
void LinkedList<T>::insertBefore(T new_el, Node<T>* el)
{
	if (el != nullptr)
	{
		Node<T>* temp = new Node<T>(new_el);
		temp->prev = el->prev;
		temp->next = el;
		el->prev = temp;
		temp->prev->next = temp;
		count++;
	}
}

template<typename T>
void LinkedList<T>::remove(Node<T>* el)
{
	if (el != nullptr)
	{
		Node<T>* elPrev = el->prev;
		Node<T>* elNext = el->next;
		if (elPrev == nullptr)
		{
			head = elNext;
		}
		else {
			elPrev->next = elNext;
		}
		
		if (elNext == nullptr)
		{
			tail = elPrev;
		}
		else {
			elNext->prev = elPrev;
		}

		delete el;
		count--;
	}
}
