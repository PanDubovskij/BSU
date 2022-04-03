#pragma once
#include <stdio.h>
class List
{
public:
	struct tnode
	{
		tnode(const int& value_, tnode* next_ = nullptr) :value(value_), next(next_) {};//конструктор с двумя параметрами
		int value;
		tnode* next;
	};
	void addFirst(int value)
	{
		tnode* newNode = new tnode(value, head);
		head = newNode;
	}
	void print()
	{
		printf("LIST:");
		for (; head != NULL; head = head->next)
		{
			printf("%5d", head->value);
		}
		printf("\n");
	}
	void addLast(int value)
	{
		tnode* newNode = new tnode(value, NULL);
		if (head == NULL) head = newNode;
		else
		{
			tnode* current;
			for (current = head; current->next != NULL; current = current->next)
			{
				current->next = newNode;
			}
		}
	}
	tnode* getByIndex(int index) {
		tnode* current = head;
		for (int i = 0; i < index; ++i) {
			if (current == NULL) break;
			current = current->next;
		}
		return current;
	}
	void insertBefore(tnode* element, int value) {
		tnode* newNode = new tnode(value, element);
		if (head == element) head = newNode;
		else {
			tnode* current;
			for (current = head; current->next != element; current = current->next)
				;
			current->next = newNode;
		}
	}
	int pop() {
		tnode* deleteNode = head;
		int value = deleteNode->value;
		head = head->next;
		delete deleteNode;
		return value;
	}
	void erase(tnode* element) {
		if (head == element) head = element->next;
		else {
			tnode* current;
			for (current = head; current->next != element; current = current->next)
				;
			current->next = element->next;
		}
		delete element;
	}
private:
	tnode* head;


};

