#include "MyContainerIterator.h"
#include "Iterator.h"
#include "MyContainer.h"

MyContainerIterator::MyContainerIterator(const MyContainer* q)
    : _q(q), _current(0) {}

void MyContainerIterator::First() { _current = 0; }

void MyContainerIterator::Next() { _current++; }

bool MyContainerIterator::IsDone() const { return _current >= _q->Size(); }

bool MyContainerIterator::CurrentItem() const {
  if (IsDone()) {
    throw -1;
  }
  return _q->GetAt(_current);
}