#pragma once
#include <iostream>
template<typename T>
class Array
{
public:
	Array() : size_(0), capacity_(5), data_(new T[capacity_]) {};
	Array(size_t _Size): size_(_Size), data_(new T[size_]) {};
	Array(const Array& a) : size_(a.size_), capacity_(a.capacity_), data_(new T[capacity_])
	{
		for (size_t i = 0; i < a.size_; i++)
		{
			data_[i] = a.data_[i];
		}
	}
	Array& operator=(const Array& a)
	{
		if (this != &a)
		{
			delete[]data_;
			size_ = a.size_;
			capacity_ = a.capacity_;
			data_ = new T[capacity_];
			for (size_t i = 0; i < a.size_; i++)
			{
				data_[i] = a.data_[i];
			}
		}
		return *this;
	}
	Array(Array&& a) :size_(a.size_),capacity_(a.capacity_), data_(a.data_)
	{
		a.size_ = 0;
		a.capacity_ = 0;
		a.data_ = nullptr;
	}
	Array& operator=(Array&& a)
	{
		if (this != &a)
		{
			delete[]data_;
			size_ = a.size_;
			capacity_ = a.capacity_;
			data_ = a.data_;
			a.size_ = 0;
			a.capacity_ = 0;
			a.data_ = nullptr;
		}
		return *this;
	}
	~Array() { delete[]  data_; }
	int GetCapacity() {
		return capacity_;
	}
	void SetSize(int size) {
		if (size >= capacity_) {
			capacity_ += growth;
			T* temp = new T[capacity_];
			for (int i = 0; i < size_; i++) {
				temp[i] = data_[i];
			}
			delete[] data_;
			data_ = temp;
			delete[]temp;
		}
		size_ = size;
	}
	int GetUpperBound() {
		return (size_ - 1);
	}
	bool IsEmpty() {
		return (size_ == 0);
	}
	void FreeExtra() {
		for (int i = size_; i < capacity_; i++) {
			delete data_[i];
		}
		capacity_ = size_;
	}
	void RemoveAll() {
		delete[]data_;
		size_ = 0;
		capacity_ = 0;
	}
	int& GetAt(int index) {
		return data_[index];
	}
	void SetAt(int index, const T& value) {
		if (index >= this->size_)
		{
			std::cout << "error index\n";
			exit(1);
		}
		data_[index] = value;
	}
	int& operator[](size_t index)
	{
		if (index >= this->size_)
		{
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
			delete[]temp;
		}
		data_[size_] = value;
		size_++;
	}
	void InsertAt(size_t index, const T& value) {
		if (size_ == capacity_) {
			capacity_ += 2;
		}
		size_++;
		for (int i = size_ - 1; i > index; i--) {
			data_[i] = data_[i - 1];
		}
		data_[index] = value;
	}
	void RemoveAt(size_t index) {
		if (size_ == 0) {
			exit(1);
		}
		for (int i = index; i < size_; i++) {
			data_[i] = data_[i + 1];
		}
		size_--;
	}
	Array Append(Array arr) {
		int new_size = size_ + arr.size_;
		Array new_arr(new_size);
		for (int i = 0; i < size_; i++) {
			new_arr[i] = data_[i];
		}
		for (int i = 0; i < arr.size_; i++) {
			new_arr[i + size_] = arr.data[i];
		}
		return new_arr;
	}
private:
	T* data_;
	int size_ = 0;
	int capacity_;
	static const size_t growth = 1;
};

