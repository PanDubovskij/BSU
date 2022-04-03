#pragma once

template <class T>
class PriorityQueue
{
private:
	struct NodePriorityQueue
	{
		T data;
		int priority;
		NodePriorityQueue* prev;
		NodePriorityQueue* next;
		NodePriorityQueue() = default;//конструктор по умолчанию
		NodePriorityQueue(const T& _data, int _priority = 0, 
			NodePriorityQueue* _prev = nullptr, NodePriorityQueue* _next = nullptr)
			: data(_data), priority(_priority), prev(_prev), next(_next) {};
		~NodePriorityQueue() = default;
	};

	void insertBefore(NodePriorityQueue* beforeNode, NodePriorityQueue* newNode) {
		if (head == beforeNode) {
			newNode->next = head;
			head = newNode;
		} else {
			NodePriorityQueue * current;
			for (current = head; current->next != beforeNode; current = current->next)
				;
			newNode->prev = beforeNode->prev;
			newNode->next = beforeNode;
			current->next = newNode;
			beforeNode->prev = newNode;
		}
	}
	NodePriorityQueue* find(int newPriority) {
		NodePriorityQueue * current;
		for (current = head; current!=nullptr && current->priority >= newPriority; current = current->next)
			;
		return current;
	}

public:
    PriorityQueue() : size(0), head(nullptr), tail(nullptr) {};
    ~PriorityQueue();

	PriorityQueue(const PriorityQueue& other);	// COPY

    void SortInsert(T item, int priority);
    T PopHead();
	std::string ToString();
	size_t GetSize() const { return size; }

private:
    size_t size;
	NodePriorityQueue* head;
	NodePriorityQueue* tail;

};

template<typename T>
void PriorityQueue<T>::SortInsert(T item, int priority)
{
	NodePriorityQueue* newNode = new NodePriorityQueue(item, priority);
	NodePriorityQueue* beforeNode = find(priority);// поиск элемента с меньшим приоритетом

	if (size == 0)	// к пустой
	{
		head = newNode;
		tail = newNode;
	}
	else if (beforeNode == nullptr)	// последним
	{
		tail->next = newNode;
		tail = newNode;
	}
	else // существует элемент, перед которым добавляем, то есть в середину, в частности, перед первым
	{
		insertBefore(beforeNode, newNode);
	}
	++size;
}

template<class T>
std::string PriorityQueue<T>::ToString()
{
	std::stringstream sout;
	for (NodePriorityQueue* current = head; current != nullptr; current = current->next)
	{
		sout << current->data << ":" << current->priority << " ";
	}

	std::string str = "";
	getline(sout, str);
	return str;
}


template<typename T>
T PriorityQueue<T>::PopHead()
{
//	assert(head != nullptr); // так всё-таки можно
	NodePriorityQueue* newNode = head->next;
	T temp = head->data;
	delete head;
	head = newNode;
	--size;
	return temp;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	while (head)
	{
		PopHead();
	}
}

template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& other) : PriorityQueue()
{
	for (NodePriorityQueue* current = other.head; current != nullptr; current = current->next)
	{
		this->SortInsert(current->data, current->priority);
	}
}
