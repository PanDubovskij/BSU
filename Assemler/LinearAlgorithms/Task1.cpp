#include <iostream>  
//1. Вычислить значение выражения а5 + а3 + а для числа а,
//    вводимого с консоли.
int main() {
  int a, result;
  std::cout << "Enter a\n";
  std::cin >> a;

  _asm {
  mov eax,a
 imul a
 imul a
 imul a
 imul a

 mov ecx,eax; ecx = a*a*a*a*a
 mov eax,a
 imul a
 imul a
 add ecx,eax; ecx = а5+а3
 add ecx,a
 mov result,ecx
  }
  std::cout << result;

  return 0;
}
