#include "MyContainer.h"
#include "Visitor.h"
#include "MyContainerIterator.h"
#include <string>

MyContainer::MyContainer() : size(100) {
 data = new bool[size];
 for (int i = 0; i < size; i++)data[i] = 0;
}

MyContainer::MyContainer(int size_) : size(size_), data(new bool[size_]) {}

MyContainer::MyContainer(const std::initializer_list<int>& list)
 : MyContainer(list.size()) {
 int cnt = 0;
 for (auto& element : list) {
  data[cnt] = element;
  ++cnt;
 }
}

MyContainer::~MyContainer() {
 if (size > 0) {
  delete[] data;
 }
}

void MyContainer::add(int item) {
 data[item] = 1;
}

void MyContainer::save(std::string file_name) {
 std::ofstream out(file_name);
 for (int i = 0; i < size; i++) {
  if (data[i] != 0) {
   out << i << " ";
  }
 }
 //MyContainerIterator myiterator(this);
 //for (myiterator.First(); !myiterator.IsDone(); myiterator.Next()) {
 // if (data[myiterator.CurrentItem()] != 0) {
 //  out << myiterator.CurrentItem()<<" ";
 // }
 //}
}

bool& MyContainer::GetAt(int index) const { return data[index]; }

void MyContainer::Accept(Visitor* visitor) {
 MyContainerIterator myiterator(this);
 for (myiterator.First(); !myiterator.IsDone(); myiterator.Next()) {
  visitor->Visit(myiterator.CurrentItem());
 }
}

std::string MyContainer::ToStringSet() {
 std::string str;
 for (int i = 0; i < size; i++) {
  if (data[i] != 0) {
   str += std::to_string(i) + " ";
  }
 }
 return str;
}