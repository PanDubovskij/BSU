#pragma once
#pragma once
#include <iostream>

#include "Iterator.h"
template <typename T>
class Array {
 public:
  Array() : size_(0), capacity_(100), data_(new T[capacity_]){};
  Array(size_t _Size) : size_(_Size), data_(new T[size_]){};
  Array(const Array& a)
      : size_(a.size_), capacity_(a.capacity_), data_(new T[capacity_]) {
    for (size_t i = 0; i < a.size_; i++) {
      data_[i] = a.data_[i];
    }
  }
  Array& operator=(const Array& a) {
    if (this != &a) {
      delete[] data_;
      size_ = a.size_;
      capacity_ = a.capacity_;
      data_ = new T[capacity_];
      for (size_t i = 0; i < a.size_; i++) {
        data_[i] = a.data_[i];
      }
    }
    return *this;
  }
  Array(Array&& a) : size_(a.size_), capacity_(a.capacity_), data_(a.data_) {
    a.size_ = 0;
    a.capacity_ = 0;
    a.data_ = nullptr;
  }
  void Print() {
    for (int i = 1; i <= (this->GetUpperBound() + 1); i++) {
      std::cout << this->GetAt(i) << " ";
    }
  }
  Array& operator=(Array&& a) {
    if (this != &a) {
      delete[] data_;
      size_ = a.size_;
      capacity_ = a.capacity_;
      data_ = a.data_;
      a.size_ = 0;
      a.capacity_ = 0;
      a.data_ = nullptr;
    }
    return *this;
  }
  ~Array() { delete[] data_; }
  int GetUpperBound() const { return (size_ - 1); }
  bool IsEmpty() { return (size_ == 0); }
  void FreeExtra() {
    for (int i = size_; i < capacity_; i++) {
      delete data_[i];
    }
    capacity_ = size_;
  }
  int& GetAt(int index) const { return data_[index]; }
  void SetAt(int index, const T& value) {
    if (index >= this->size_) {
      std::cout << "error index\n";
      exit(1);
    }
    data_[index] = value;
  }
  int& operator[](size_t index) {
    if (index >= this->size_) {
      std::cout << "error index\n";
      exit(1);
    }
    return data_[index];
  }
  void Add(const T& value) {
    if (size_ >= capacity_) {
      capacity_ += growth;
      T* temp = new T[capacity_];
      for (int i = 0; i < size_; i++) {
        temp[i] = data_[i];
      }
      delete[] data_;
      data_ = temp;
      delete[] temp;
    }
    size_++;
    data_[size_] = value;
  }

  /*class ArrayIterator : public Iterator<T> {
   public:
    ArrayIterator(const Array<T>* arr);
    virtual void First() { _current = 0; }
    virtual void Next() { _current++; }
    virtual bool IsDone() const { return _current >= _array->GetUpperBound(); }
    virtual T CurrentItem() const {
      if (IsDone()) {
        exit(1);
      }
      return _array->GetAt(_current);
    }

   private:
    const Array<T>* _array;
    long _current;
  };

  void PrintByIterator(ArrayIterator& start) {
    for (start.First(); !start.IsDone(); start.Next()) {
      std::cout << start.CurrentItem();
    }
  }*/

 private:
  T* data_;
  int size_ = 0;
  int capacity_;
  static const size_t growth = 5;
};
