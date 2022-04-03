#pragma once
#include "Iterator.h"
template <class Item>
class ArrayIterator : public Iterator<Item> {
 public:
  ArrayIterator(const Array<Item>* arr);
  virtual void First();
  virtual void Next();
  virtual bool IsDone() const;
  virtual Item CurrentItem() const;

 private:
  const Array<Item>* _array;
  long _current;
};
template <class Item>
ArrayIterator<Item>::ArrayIterator(const Array<Item>* arr)
    : _array(arr), _current(0) {}
template <class Item>
void ArrayIterator<Item>::First() {
  _current = 0;
}
template <class Item>
void ArrayIterator<Item>::Next() {
  _current++;
}
template <class Item>
bool ArrayIterator<Item>::IsDone() const {
  return _current >= _array->GetUpperBound();
}
template <class Item>
Item ArrayIterator<Item>::CurrentItem() const {
  if (IsDone()) {
    exit(1);
  }
  return _array->GetAt(_current);
}
