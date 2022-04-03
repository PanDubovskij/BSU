#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

extern "C" double* _stdcall CalcLn(int k);
extern "C" double* _stdcall Integral(int k);
int main() {
  int k;
  std::cin >> k;
  std::cout << *Integral(k) << '\n';
  std::cout << *CalcLn(k) << '\n';
  std::cout << M_LN2;
 return 0; 
}