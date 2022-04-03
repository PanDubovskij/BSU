#include "DList.h"

template<class T>
void DList<T>::pushBack(const T& value)
{
	Node* newNode = new Node(value, tail);
	if (size == 0)
	{
		head = newNode;
	}
	else
	{
		tail->next = newNode;
	}
	tail = newNode;
	size++;
}
template<class T>
std::ostream& operator<<(std::ostream& out, DList<T>& l)
{
	for (DList<int>::Iterator i = l.begin(); i != l.end(); i++)
	{
		std::cout << *i << " ";
	}
	return out;
}
template <class T>
T DList<T>::popBack()
{
	if (size == 0)
	{
		std::cout << "List is empty\n";
		return T();
	}
	Node* temp = tail;
	T key = temp->data;
	tail = tail->prev;
	delete temp;
	if (size == 1)
	{
		head = nullptr;
	}
	size--;
	return key;
}
template<class T>
void DList<T>::PushFront(const T& value)
{
	Node* newNode = new Node(value, nullptr, head);
	if (size == 0)
	{
		tail = newNode;
	}
	else
	{
		head->prev = newNode;
	}
	head = newNode;
	++size;
}

template<class T>
T DList<T>::PopFront()
{
	if (size == 0)
	{
		std::cout << "List is empty" << std::endl;
		return T();
	}

	Node* temp = head;
	T key = temp->data;
	head = head->next;
	delete temp;
	if (size == 1)
	{
		tail = nullptr;
	}
	size--;
	return key;
}
template<class T>
T& DList<T>::operator[](size_t index)
{
	if (index >= size)
	{
		std::cout << "Wrong index.\n";
		exit(0);
	}
	Node* cur = head;
	for (size_t i = 0; i < index; i++, cur = cur->next);

	return cur->data;
}
template<class T>
void DList<T>::insert(const T& temp_data, size_t index)
{
	if (index > size)
	{
		std::cout << "Error index! Insert cannot be done!\n";
		return;
	}

	if (index == 0)
	{
		PushFront(temp_data);
		return;
	}

	if (index == size)
	{
		pushBack(temp_data);
		return;
	}

	Node* pos = head;
	size_t count = 0;

	while (count != index) //поиск нужной позиции
	{
		pos = pos->next;
		count++;
	}

	Node* temp = new Node(temp_data, pos->prev, pos);
	(pos->prev)->next = temp;
	pos->prev = temp;
	size++;
}
template<class T>
void DList<T>::erase(size_t index)
{
	if (index > size)
	{
		std::cout << "Incorrect index\n";
		return;
	}

	int i = 1;
	Node* Del = head;
	while (i < index)
	{
		Del = Del->next;
		i++;
	}

	Node* PrevDel = Del->prev;
	Node* AfterDel = Del->next;

	if (PrevDel != 0 && size != 1)
		PrevDel->next = AfterDel;
	if (AfterDel != 0 && size != 1)
		AfterDel->prev = PrevDel;
	if (index == 1)
		head = AfterDel;
	if (index == size)
		tail = PrevDel;
	delete Del;
	size--;
}
template<class T>
void DList<T>::Erase(DList::Iterator start, DList::Iterator end)
{
	size_t index = Find(*start);
	size_t numberOfElements = 0;
	for (Iterator it = start; it != end; ++it)
	{
		++numberOfElements;
	}
	for (size_t i = 1; i <= numberOfElements; ++i)
	{
		erase(index);
	}
}
template<class T>
void DList<T>::Replace(const T& oldValue, const T& newValue)
{
	size_t index = Find(oldValue);
	while (index != -1)
	{
		(*this)[index] = newValue;
		index = Find(oldValue);
	}
}
template<class T>
size_t DList<T>::Find(const T& value)
{
	size_t index = 0;
	Node* current;
	for (current = head; current != nullptr && current->data != value; current = current->next)
	{
		++index;
	}
	if (current != nullptr)
	{
		return index;
	}    return -1;
}