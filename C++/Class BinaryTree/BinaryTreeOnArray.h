#pragma once
#include <iostream>

class BinaryTreeOnArray {
 public:
  BinaryTreeOnArray() = default;
  BinaryTreeOnArray(size_t);
  ~BinaryTreeOnArray();

  int* GetArr() const;
  size_t GetSize() const;
  void MemoryExtension(int, int);

  void Insert(int, int pos = 0);
  bool Search(int, int pos = 0);
  void PrintTree(int pos = 0);

  void PrintArray();

 private:
  size_t size = 0;
  int* arr;
};
