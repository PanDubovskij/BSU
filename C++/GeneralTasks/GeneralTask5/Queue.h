#pragma once

template<class T>
class Queue
{
public:
    struct Node
    {
        T data;
        Node* previous;
        Node* next;
        Node() = default;
        Node(const T& _data, Node* _previous = nullptr, Node* _next = nullptr) :
            data(_data), previous(_previous), next(_next) {}
        ~Node() = default;
    };

    Queue() : size(0), head(nullptr), tail(nullptr) {}
    ~Queue();

    void PushBack(const T& value);
    T PopFront();

    bool IsEmpty() { return size == 0; };

	std::string ToString();

private:
    size_t size;
    Node* head;
    Node* tail;

};

template <class T>
Queue<T>::~Queue()
{
	while (size > 0)
	{
		PopFront();
	}
};

template<class T>
void Queue<T>::PushBack(const T& value)
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
	++size;
}

template<class T>
T Queue<T>::PopFront()
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
std::string Queue<T>::ToString()
{
	std::stringstream sout;
	for (Node* current = head; current != nullptr; current = current->next)
	{
		sout << current->data << " ";
	}

	std::string str = "";
	getline(sout, str);
	return str;	
}
