#include <iostream>  
//Вычислить значение выражения (а4-2)/(а-4)

int main() {
  int a, result;
  std::cout << "Enter a\n";
  std::cin >> a;

  _asm {
  mov eax,a
 imul a
 imul a
 imul a
 sub eax,2

 mov ecx,a
 sub ecx,4
 cdq
 idiv ecx
 mov result,eax
  }
  std::cout << result;

  return 0;
}
