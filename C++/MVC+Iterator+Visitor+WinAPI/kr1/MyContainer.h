#pragma once
#include <initializer_list>
#include <fstream>

class Visitor;
class Iterator;

class MyContainer {
private:
 bool* data;
 int size = 100;
public:
 // конструктор по умолчанию
 MyContainer();

 // конструктор с одним параметром
 explicit MyContainer(int size_);

 // конструирование из списка инициализации (std::initializer_list)
 MyContainer(const std::initializer_list<int>& list);

 // деструктор
 ~MyContainer();

 void add(int item);

 bool& GetAt(int index) const;
 int Size() const { return size; }

 void Accept(Visitor* visitor);

 void save(std::string file_name);
 std::string ToStringSet();
private:
 //запрещаем копирование и перемещение
 MyContainer(const MyContainer& obj) {}
 MyContainer(MyContainer&& obj) {}

 MyContainer& operator=(const MyContainer& obj) {}
 MyContainer& operator=(MyContainer&& obj) {}
};