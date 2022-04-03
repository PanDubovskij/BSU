#pragma once
#include "Iterator.h"

class MyContainer;
class Iterator;

class MyContainerIterator : Iterator {
 public:
  MyContainerIterator(const MyContainer* q);
  virtual void First();
  virtual void Next();
  virtual bool IsDone() const;
  virtual bool CurrentItem() const;

 private:
  const MyContainer* _q;
  long _current;
};
