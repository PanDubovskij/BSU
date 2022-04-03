//#include <iostream>
//extern "C" void _stdcall ReplaceElem(int* arr, int n);
//extern "C" int _stdcall SumOfSub(int* arr,int n);
//int main() {
// /* int N=5;
//  int* arr = new int[N]{7,-2,3,-4,5};
//  ReplaceElem(arr, N);
//  for (size_t i = 0; i < N; i++) {
//    std::cout << arr[i] << " ";
//  }*/
//  int N = 12;
//  int* arr = new int[N]{2,1,30,3,3,3,3,3,4,4,4,5};
//  std::cout << SumOfSub(arr, N);
// return 0;
//}
#include <Windows.h>

#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

extern "C" void __fastcall func3(short*, int);


int main() {
  srand(time(NULL));

  setlocale(0, " ");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  cout << "Введите размерность массива: ";

  int n;
  cin >> n;

  cout << endl;

  short int* A = new short int[n];

  cout << "Начальный массив: ";
  for (unsigned i(0); i < n; i++) {
    A[i] = rand() % 100 - 50;
    cout << A[i] << " ";
  }
  cout << endl;

  // func1(A, n);
  // func2(A, n);
  func3(A, n);

  cout << "Новый массив: ";

  for (unsigned i(0); i < n; i++) cout << A[i] << " ";
  cout << endl;
}