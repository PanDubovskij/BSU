#include <iostream>
extern "C" int _stdcall FindRowWithMaxNum(int* a, int n,int m);
int main() {
  int n,m;
  std::cout << " Enter Matrix size\n";
  std::cin >> n>>m;
  int* A = new int[n*m];
  for (size_t i = 0; i < n*m; i++) {
    std::cin >> A[i];
  }
  //ChangeRowCalm(A, size, index);
  std::cout << FindRowWithMaxNum(A, n, m);
  return 0;
}