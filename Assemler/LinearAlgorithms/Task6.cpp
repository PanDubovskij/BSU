#include <iostream>  
//6.	Пользователь вводит номер года. Необходимо написать программу, которая выведет количество дней в этом году

int main() {
  int year, days;
  std::cout << "Enter year\n";
  std::cin >> year;
  _asm {
   mov eax,year
   mov ebx,400
   cdq
   div ebx
   cmp edx,0
   jz next
   jnz next2
   next:
   mov days,366
    jmp the_end
    next2:
    mov eax,year
     mov ebx,4
    cdq
    div ebx
    cmp edx,0
    jz next3
    jnz next5
     next3:
    mov eax,year
     mov ebx,100
     cdq
     div ebx
     cmp edx,0
     jnz next4
     jz next5
     next4:
    mov days,366
     jmp the_end
     next5:
    mov days,365
     jmp the_end
     the_end:
  }
  std::cout << days;
  return 0;
}
