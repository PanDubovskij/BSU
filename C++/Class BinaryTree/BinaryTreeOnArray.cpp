#include"BinaryTreeOnArray.h"

BinaryTreeOnArray::BinaryTreeOnArray(size_t size_) {
  arr = new int[size_];
  size = size_;
  for (size_t i = 0; i < size; i++) arr[i] = 0;
}

BinaryTreeOnArray::~BinaryTreeOnArray() { delete[] arr; }

int* BinaryTreeOnArray::GetArr() const { return this->arr; }

size_t BinaryTreeOnArray::GetSize() const { return size; }

void BinaryTreeOnArray::MemoryExtension(int pos, int data) {
  size *= 2;
  int* arr_ = new int[size];
  for (size_t i = 0; i < size; i++) arr_[i] = 0;
  for (size_t i = 0; i < size / 2; i++) arr_[i] = arr[i];
  arr_[pos] = data;
  arr = new int[size];
  for (size_t i = 0; i < size; i++) arr[i] = arr_[i];
}

void BinaryTreeOnArray::Insert(int data_, int pos) {
  if (pos >= size) this->MemoryExtension(pos, data_);
  if (arr[pos] == 0) {
    arr[pos] = data_;
    return;
  } else if (arr[pos] == data_)
    return;
  else if (data_ > arr[pos]) {
    pos = (2 * pos) + 2;
    Insert(data_, pos);
  } else {
    pos = (2 * pos) + 1;
    Insert(data_, pos);
  }
}

bool BinaryTreeOnArray::Search(int data_, int pos) {
  if (pos > size) {
    return false;
  } else if (arr[pos] == data_)
    return true;
  else if (data_ > arr[pos]) {
    pos = (2 * pos) + 2;
    return Search(data_, pos);
  } else {
    pos = (2 * pos) + 1;
    return Search(data_, pos);
  }
}

void BinaryTreeOnArray::PrintTree(int pos) {
  if (arr == nullptr) {
    std::cout << "Tree is empty!\n";
    return;
  }
  while (pos < size) {
    if (arr[pos] != 0) {
      std::cout << arr[pos] << " ";
    }
    pos++;
  }
}

void BinaryTreeOnArray::PrintArray() {
  if (arr == nullptr) {
    std::cout << "Array is empty!\n";
    return;
  }
  size_t pos = 0;
  while (pos < size) {
    std::cout << arr[pos] << ' ';
    pos++;
  }
}