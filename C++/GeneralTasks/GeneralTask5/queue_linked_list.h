#ifndef QUEUE_LINKED_LIST_H_
#define QUEUE_LINKED_LIST_H_

#include<iostream>
#include<string>
#include <vector>
#include <cassert>

namespace containers {
template<class T>
class QueueLinkedList {
 public:
  struct Node {
   public:
    T value;

    ~Node() = default;

    friend class QueueLinkedList;

   private:
    Node *previous;
    Node *next;

    Node() : value(), previous(nullptr), next(nullptr) {}

    explicit Node(const T &_value, Node *_previous = nullptr,
                  Node *_next = nullptr) :
        value(_value), previous(_previous), next(_next) {}
  };

  QueueLinkedList() : size(0), head(nullptr), tail(nullptr) {}

  QueueLinkedList(const std::initializer_list<T> &list);

  QueueLinkedList(const QueueLinkedList<T> &queue);

  QueueLinkedList(QueueLinkedList<T> &&queue) noexcept;

  ~QueueLinkedList();

  int Size() const { return size; }

  bool IsEmpty() const { return size == 0; }

  std::vector<T> ToVector() const;

  Node *Head() { return head; }

  Node *Tail() { return tail; }

  Node *Head() const { return head; }

  Node *Tail() const { return tail; }

  void Push(const T &value);

  void Push(T &&value);

  T Pop();

  int Find(const T &value) const;

  std::vector<int> FindAll(const T &value) const;

  Node *operator[](size_t);

  Node *operator[](size_t) const;

  QueueLinkedList<T> &operator=(const QueueLinkedList<T> &queue);

  QueueLinkedList<T> &operator=(QueueLinkedList<T> &&queue) noexcept;

  bool operator==(const QueueLinkedList<T> &queue) const;

  bool operator!=(const QueueLinkedList<T> &queue) const;

 private:
  size_t size;
  Node *head;
  Node *tail;
};

template<class T>
QueueLinkedList<T>::~QueueLinkedList() {
  while (size > 0) {
    Pop();
  }
}

template<class T>
std::vector<T> QueueLinkedList<T>::ToVector() const {
  std::vector<T> result;
  for (Node *current = head; current != nullptr; current = current->next) {
    result.push_back(current->value);
  }
  return result;
}

template<class T>
void QueueLinkedList<T>::Push(const T &value) {
  Node *newNode = new Node(value, tail);
  if (size == 0) {
    head = newNode;
  } else {
    tail->next = newNode;
  }
  tail = newNode;
  ++size;
}

template<class T>
void QueueLinkedList<T>::Push(T &&value) {
  Push(value);
}

template<class T>
T QueueLinkedList<T>::Pop() {
  if (size == 0) {
    throw std::exception();
  }

  Node *temp = head;
  T key = temp->value;
  head = head->next;
  delete temp;
  if (size == 1) {
    tail = nullptr;
  }
  size--;
  return key;
}

template<typename T>
QueueLinkedList<T>::QueueLinkedList(const std::initializer_list<T> &list) :
    QueueLinkedList() {
  for (T value : list) {
    Push(value);
  }
}

template<class T>
typename QueueLinkedList<T>::Node *QueueLinkedList<T>::operator[](
    size_t index) {
//  if (index >= size) {
//    throw std::exception();
//  }
  assert(index < size);
  Node *cur = head;
  for (size_t i = 0; i < index; i++, cur = cur->next) {}

  return cur;
}

template<class T>
typename QueueLinkedList<T>::Node *QueueLinkedList<T>::operator[](
    size_t index) const {
  assert(index < size);
//  if (index >= size) {
//    throw std::exception();
//  }
  Node *cur = head;
  for (size_t i = 0; i < index; i++, cur = cur->next) {}

  return cur;
}

template<class T>
QueueLinkedList<T>::QueueLinkedList(const QueueLinkedList<T> &queue) {
  size = 0;
  head = tail = nullptr;
  for (Node *current = queue.head; current != nullptr;
       current = current->next) {
    Push(current->value);
  }
}

template<class T>
QueueLinkedList<T>::QueueLinkedList(QueueLinkedList<T> &&queue) noexcept {
  size = queue.size;
  head = queue.head;
  tail = queue.tail;
  queue.size = 0;
  queue.head = nullptr;
  queue.tail = nullptr;
}

template<class T>
int QueueLinkedList<T>::Find(const T &value) const {
  int index = 0;
  for (Node *current = head; current != nullptr; current = current->next) {
    if (current->value == value) {
      return index;
    }
    ++index;
  }
  return -1;
}

template<class T>
std::vector<int> QueueLinkedList<T>::FindAll(const T &value) const {
  std::vector<int> result;
  int index = 0;
  for (Node *current = head; current != nullptr; current = current->next) {
    if (current->value == value) {
      result.push_back(index);
    }
    ++index;
  }
  return result;
}

template<class T>
QueueLinkedList<T> &QueueLinkedList<T>::operator=(
    const QueueLinkedList<T> &queue) {
  if (this == &queue) {
    return *this;
  }

  while (size > 0) {
    Pop();
  }

  size = 0;
  head = tail = nullptr;
  for (Node *current = queue.head; current != nullptr;
       current = current->next) {
    Push(current->value);
  }

  return *this;
}

template<class T>
QueueLinkedList<T> &QueueLinkedList<T>::operator=(
    QueueLinkedList<T> &&queue) noexcept {
  if (this == &queue) {
    return *this;
  }

  while (size > 0) {
    Pop();
  }

  size = queue.size;
  head = queue.head;
  tail = queue.tail;
  queue.size = 0;
  queue.head = nullptr;
  queue.tail = nullptr;

  return *this;
}

template<class T>
bool QueueLinkedList<T>::operator==(const QueueLinkedList<T> &queue) const {
  if (size != queue.size) {
    return false;
  }
  Node *current2 = queue.head;
  for (Node *current1 = head; current1 != nullptr; current1 = current1->next) {
    if (current1->value != current2->value) {
      return false;
    }
    current2 = current2->next;
  }
  return true;
}

template<class T>
bool QueueLinkedList<T>::operator!=(const QueueLinkedList<T> &queue) const {
  return !(*this == queue);
}
}  // namespace containers

#endif  // QUEUE_LINKED_LIST_H_
