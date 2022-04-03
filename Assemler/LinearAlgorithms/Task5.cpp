#include <iostream>  
//5.	Пользователь вводит три числа. Найти сумму тех чисел, которые делятся на 2.

int main() {
  int a, b, c, result = 0;
  std::cout << "Enter a,b,c\n";
  std::cin >> a >> b >> c;
  _asm {
  mov eax, a
  cdq
  mov ebx,2
  idiv ebx
  cmp edx,0
  jnz not_zero
  jz zero
 not_zero:
   jmp next
   zero:
   mov ecx,a
   add result,ecx
   jmp next
    next:
   mov eax,b
    cdq
  mov ebx,2
  idiv ebx
  cmp edx,0
  jnz not_zero2
  jz zero2
 not_zero2:
   jmp next2
   zero2:
   mov ecx,b
   add result,ecx
    jmp next2
    next2:
   mov eax,c
    cdq
  mov ebx,2
  idiv ebx
  cmp edx,0
  jnz not_zero3
  jz zero3
 not_zero3:
   jmp the_end
   zero3:
   mov ecx,c
   add result,ecx
    jmp the_end
   the_end:
  }
  std::cout << result << "\n";
  return 0;
}
