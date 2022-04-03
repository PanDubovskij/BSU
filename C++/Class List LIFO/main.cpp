#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "C:\Users\User\source\repos\list+lifo\list+lifo\StackOnList.h"

int main()
{
	//List list;
	//list.addLast(20);
	//list.addFirst(10);
	//list.addLast(11);
	//list.addFirst(20);
	//list.addLast(14);
	////list.getByIndex(2);
	//list.pop();
	//list.print();
	StackOnList<int> stack;
	stack.Push(10);
	stack.Push(11);
	std::cout<<"\nSize:"<<stack.Size()<<"\n";
	stack.print();
	std::cout<<"\nEmpty:"<<stack.IsEmpty();
	std::ifstream in("input.txt");
	std::string str;
	StackOnList<char> stack_letters;
	getline(in, str, 'i');
	return 0;
}