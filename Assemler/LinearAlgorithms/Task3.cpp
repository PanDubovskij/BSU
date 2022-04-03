#include <iostream>  
//3.	Найти целочисленное решение уравнения ах+b=0 , если оно существует.

int main() {
  int a, b, res;
  std::cout << "Enter a and b\n";
  std::cin >> a >> b;
  if (a == 0 || b == 0) {
    std::cout << "No solutions\n";
    exit(1);
  }
  _asm {
   mov eax,b
   neg eax
   mov ebx,a
   cdq
   idiv ebx
   cmp edx,0
   jz zero
   jnz not_zero
   zero:
   mov res,eax
    jmp the_end
    not_zero:
   mov res,0
    jmp the_end
    the_end:
  }
  if (res != 0) {
    std::cout << res << "\n";
  }
  else {
    std::cout << "No solutions\n";
  }

  return 0;
}
