#pragma once
#include <iostream>
#include <fstream>
template<class T>
class DList
{

public:
	struct Node
	{
		T data;
		Node* prev;
		Node* next;
		struct Node* ptr_;
		Node() = default;
		Node(const T& _data, Node* _prev=nullptr, Node* _next=nullptr):
			data(_data),prev(_prev),next(_next){}
		~Node() = default;
	};
	DList():size(0),head(nullptr),tail(nullptr){}
	~DList()
	{
		while (size > 0)
		{
			popBack();
		}
	}
	T getValue(Node* p) { return p->data; }
	void pushBack(const T&);
	T popBack();
	void PushFront(const T& value);
	T PopFront();
	void insert(const T& temp_data, size_t index);
	T& operator[](size_t index);
	bool IsEmpty() { return size == 0; }
	void erase(size_t index);
	Node* getElem(size_t index)
	{
		Node* temp = head;

		// Позиция от 1 до Count?
		if (index < 1 || index > size)
		{
			// Неверная позиция
			std::cout << "Incorrect position !!!\n";
			return 0;
		}
		int i = 1;
		while (i < index && temp != 0)
		{
			temp = temp->next;
			i++;
		}
		if (temp == 0)
			return 0;
		else
			return temp;
	}
	size_t Find(const T& value);
	void Replace(const T& oldValue, const T& newValue);
template<class T>
	friend std::ostream& operator<<(std::ostream&, DList<T>&);
private:
	size_t size;
	Node* head;
	Node* tail;
public:
	class Iterator
	{
	public:
		Iterator() = default;
		Iterator(Node* _ptr) :ptr(_ptr) {};
		~Iterator() = default;
		Iterator& operator++()
		{
			ptr = ptr->next;
			return *this;
		}
		Iterator& operator++(int)
		{
			Iterator temp(*this);
			this->operator++();
			return temp;
		}
		Iterator& operator--()
		{
			ptr = ptr->prev;
			return *this;
		}
		Iterator& operator--(int)
		{
			Iterator temp(*this);
			this->operator--();
			return temp;
		}
		T& operator*()const { return ptr->data; }
		bool operator==(const Iterator& i) const { return ptr == i.ptr; }
		bool operator!=(const Iterator& i) const { return ptr != i.ptr; }
	private:
		Node* ptr;
	};
	Iterator begin() { return Iterator(head); }
	Iterator end() { return Iterator(tail->next); }
	class ReverseIterator
	{
	public:
		ReverseIterator() = default;
		ReverseIterator(Node* _ptr) : ptr(_ptr) {}
		~ReverseIterator() = default;
		ReverseIterator& operator++() // Префиксная форма
		{
			ptr = ptr->previous;
			return *this;
		}
		ReverseIterator& operator++(int) // Постфиксная форма
		{
			ReverseIterator temp(*this);
			this->operator++();
			return temp;
		}
		ReverseIterator& operator--()
		{
			ptr = ptr->next;
			return *this;
		}
		ReverseIterator& operator--(int)
		{
			ReverseIterator temp(*this);
			this->operator--();
			return temp;
		}
		T& operator*() const { return ptr->data; }
		bool operator==(const ReverseIterator& it) const { return ptr == it.ptr; }
		bool operator!=(const ReverseIterator& it) const { return ptr != it.ptr; }
	private:
		Node* ptr;
	};
	ReverseIterator RBegin() { return ReverseIterator(tail); }
	ReverseIterator REnd() { return ReverseIterator(head->previous); }
	void Erase(DList::Iterator start, DList::Iterator end);
};
