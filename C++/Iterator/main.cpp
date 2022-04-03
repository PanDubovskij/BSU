#include "Array.h"
#include "ArrayIterator.h"
#include "Iterator.h"
int main() {
  Array<int> myarray;
  myarray[0] = 5;
  myarray[1] = 4;
  myarray[2] = 8;
  ArrayIterator<int> myiterator(&myarray);
  for (myiterator.First(); !myiterator.IsDone(); myiterator.Next()) {
    std::cout << myiterator.CurrentItem();
  }
}