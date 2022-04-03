#pragma once
#include <iostream>
#include<initializer_list>
#include <vector>

template <typename T>
class BiDirectionalListOnArray {
 private:
	T* data_;
	int size_ = 0;
	int capacity_;

	static const size_t MIN_CAPACITY = 10;
	static const size_t GROWTH_FACTOR = 2;

 public:

	 BiDirectionalListOnArray(): size_(0), capacity_(MIN_CAPACITY), data_(new T[capacity_]) {}

	 ~BiDirectionalListOnArray() { delete[]  data_; }

	 BiDirectionalListOnArray(const std::initializer_list<T>& list): BiDirectionalListOnArray() {
		 for (T data_ : list)
		 {
			 PushBack(data_);
		 }
	 }

	 void PushBack(const T& value) {
		 if (size_ >= capacity_) {
			 capacity_ += 2;
			 T* temp = new T[capacity_];
			 for (int i = 0; i < size_; i++) {
				 temp[i] = data_[i];
			 }
			 delete[] data_;
			 data_ = temp;
			 delete[]temp;
		 }
		 data_[size_] = value;
		 size_++;
	 }

	 int Size() { return size_; }

	 bool IsEmpty() { return size_ == 0; }

	 BiDirectionalListOnArray(const BiDirectionalListOnArray& obj) {
		 size_ = obj.size_;
		 capacity_ = size_;
		 data_ = NULL;
		 if (size_ != 0)
			 data_ = new T[size_];
		 else
			 data_ = 0;
		 for (int i = 0; i < size_; ++i)
			 data_[i] = obj.data_[i];
	 }

	 BiDirectionalListOnArray(BiDirectionalListOnArray&& list) {
		 size_ = list.size_;
		 capacity_ = list.capacity_;
		 data_ = list.data_;
		 list.data_ = nullptr;
	 }

	 BiDirectionalListOnArray& operator=(const BiDirectionalListOnArray& obj) {
		 if (this != &obj) {
			 size_ = obj.size_;
			 capacity_ = size_;
			 data_ = NULL;
			 if (size_ != 0)
				 data_ = new T[size_];
			 else
				 data_ = 0;
			 for (int i = 0; i < size_; ++i)
				 data_[i] = obj.data_[i];
		 }
		 return *this;
	 }

	 BiDirectionalListOnArray& operator=(BiDirectionalListOnArray&& list) {
		 size_ = list.size_;
		 capacity_ = list.capacity_;
		 data_ = list.data_;
		 list.data_ = nullptr;
		 return *this;
	 }

	 T& operator[] (int i) {
		 return data_[i];
	 }

	 const T* operator[](size_t index) const {
		 if (index >= size_) {
			 throw std::out_of_range("Index out of range");
		 }
		 return &data_[index];
	 }

	 void Print() const
	 { 
		 for (int i = 0; i < size_; i++) {
				 std::cout << data_[i] << " ";
		 }
		 std::cout << std::endl;
	 }

	 std::vector<T> ToVector() {
		 std::vector<T> result;
		 for (int i = 0; i < size_; i++) {
			 result.push_back(data_[i]);
		 }
		 return result;
	 }

	 T* Front() {
		 return &data_[0];
	 }

	 const T* Front() const {
		 return &data_[0];
	 }

	 T* Back() {
		 return &data_[size_ - 1];
	 }

	 const T* Back() const {
		 return &data_[size_ - 1];
	 }

	 void PushFront(const T& value) {
		 if (size_ == capacity_) {
			 capacity_ += 2;
		 }
		 size_++;
		 for (int i = size_ - 1; i > 0; i--) {
			 data_[i] = data_[i - 1];
		 }
		 data_[0] = value;
	 }

	 void PopFront() {
		 if (size_ == 0) {
			 throw std::out_of_range("Vector is already empty");
		 }
		 for (int i = 1; i < size_; i++) {
			 data_[i - 1] = data_[i];
		 }
		 size_--;
	 }

	 void PopBack() {
		 if (size_ == 0) {
			 throw std::out_of_range("Vector is already empty");
		 }
		 size_--;
	 }

	 void InsertBefore(size_t index, const T& value) {
		 if (size_ == capacity_) {
			 capacity_ += 2;
		 }
		 size_++;
		 for (int i = size_ - 1; i > index; i--) {
			 data_[i] = data_[i - 1];
		 }
		 data_[index] = value;
	 }

	 void InsertAfter(size_t index, const T& value) {
		 if (size_ == capacity_) {
			 capacity_ += 2;
		 }
		 size_++;
		 for (int i = size_ - 1; i > index + 1; i--) {
			 data_[i] = data_[i - 1];
		 }
		 data_[index + 1] = value;
	 }

	 bool operator==(BiDirectionalListOnArray list) {
		 if (size_ != list.size_) {
			 return false;
		 }
		 for (int i = 0; i < size_; i++) {
			 if (data_[i] != list.data_[i]) {
				 return false;
			 }
		 }
		 return true;
	 }

	 bool operator!=(BiDirectionalListOnArray list) {
		 return !((*this) == list);
	 }

	 void Erase(size_t index) {
		 if (size_ == 0) {
			 throw std::out_of_range("Vector is already empty");
		 }
		 for (int i = index; i < size_; i++) {
			 data_[i] = data_[i + 1];
		 }
		 size_--;
	 }
};
