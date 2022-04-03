#include <cstdlib>
#include <iostream>

int compare_int(const void* x1, const void* x2)
{
  return (*(int*)x1 - *(int*)x2);  
}
int compare_double(const void* x1, const void* x2) {
  return (*(double*)x1 - *(double*)x2);
}
int main() {
  int array[] = {15,3,7,10,8,9};
  qsort(array, 6, sizeof(int), compare_int);
  for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
  double arr[] = {18.4, 5.2,13, -9.8, 10.3};
  qsort(arr, 5, sizeof(double), compare_double);
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  int key;  
  std::cout << "Enter element, which you want to find: ";
  std::cin >> key;
  int* item = (int*)bsearch(&key, array, 6, sizeof(int), compare_int);
  if (item != NULL)
    std::cout << "Element " << *item << " is in array\n";
  else
    std::cout << "Element " << key << " isn't found\n";
  double key2;
  std::cout << "Enter element, which you want to find: ";
  std::cin >> key2;
  double* item2 = (double*)bsearch(&key2, arr, 5, sizeof(double), compare_double);
  if (item2 != NULL)
    std::cout << "Element " << *item2 << " is in array\n";
  else
    std::cout << "Element " << key2 << " isn't found\n";
  return 0;
}