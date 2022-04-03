#include <iostream>

int SumOfDigits(int number) {
 int count=0;
 _asm {
  mov eax,number
  mov ecx,count
  mov ebx,10
  cmp eax,0
  je end_while
 begin_while:
   cdq
   idiv ebx
   add ecx, edx
   cmp eax,0
   jnz begin_while
   jz end_while
   end_while:
  mov count,ecx
 }
 return count;
}

int NumberOfEvenNumbers(int number) {
 int digit;
 int count=0;
  _asm {
  mov eax,number
  mov ecx,count
  begin_while:
  mov ebx,10
  cmp eax,0
  je end_while
  mov digit,eax
  cdq
  idiv ebx
  mov eax,edx
  mov ebx,2
  cdq
  idiv ebx
  cmp edx,0
  jz yes
  jnz no
  no:
   mov eax,digit
   mov ebx,10
   cdq
   idiv ebx
    jmp begin_while
  yes:
  inc ecx
   mov eax,digit
   mov ebx,10
   cdq
   idiv ebx
  jmp begin_while
   end_while:
  mov count,ecx
 }
  return count;
}
int Degree(int a,int n) { 
 int res;
  _asm {
    mov eax,a
    mov ecx,n
    dec ecx
    degree:
    imul a
    loop degree
    mov res,eax
  }
 return res;
}
void Reduce(int chisl, int znamen) { 
 int gcd;
  if (znamen == 0) {
    std::cout << "Error";
    exit(1);
  }
  _asm {
     mov eax,chisl
     mov ebx,znamen
     cmp eax,0
     jz zero
     jg next
     jl negative
     negative:
     neg eax
      jmp next
      next:
     cmp ebx,0
     jz zero
     jg begin_while
    begin_while:
     cmp eax,ebx
     je end_while
      jg greater
      jl less
      greater:
     sub eax,ebx
      less:
     sub ebx,eax
      end_while:
     cmp eax,0
      jz the_end
     mov gcd,eax
      mov eax,chisl
      mov ebx,gcd
      cdq
      idiv ebx
      mov chisl,eax
      mov eax,znamen
      mov ebx,gcd
      cdq
      idiv ebx
      mov znamen,eax
      jmp the_end
     zero:
     mov chisl,0
     jmp the_end
      the_end:
  }
  if (chisl == 0) {
    std::cout << 0;
  }
  else {
    std::cout << chisl << "/" << znamen;
  }
}
bool IsSymmetric(int number) { 
 int symmetric;
 _asm {
      mov eax, number
      mov ecx, 0
      mov ebx, 10
      begin_while:
      cmp eax, 0
        jg repeat
        je end_while
        repeat:
      imul ecx, ebx
        cdq
      idiv ebx
        add ecx, edx
        jmp begin_while
    end_while:
      mov symmetric, ecx
 }
 if (symmetric == number) {
   return true;
 }
 else {
   return false;
 }
}
void DegreeOfTwo(int number) {
  int n1 = 0, n2 = 0;
  _asm {
     mov ebx,number
     mov eax,2
     mov ecx,n1
     while_begin:
     mov edx,2
     cmp eax, ebx
     jge while_end
      imul edx
      inc ecx
      jmp while_begin
      while_end:
     mov n1,ecx
     inc ecx
     mov n2,ecx
  }
  std::cout << n1 << " " << n2;
}
int main() {
  int task;
  {//task 1
    std::cout << "Enter number  ";
    int number;
    std::cin >> number;
    std::cout << "sum of digits: " << SumOfDigits(number);
    std::cout << "number of even digits: " << NumberOfEvenNumbers(number);
  }
  {//task 1c
    int number;
    std::cout << "\nEnter number: ";
    std::cin >> number;
    if (IsSymmetric(number)) {std::cout << "The number is symmetric";}
    else {
      std::cout << "The number is not symmetric";
    }
  }
  {//task 3
   int a,n,res;
    std::cout << "\nEnter a and n: ";
    std::cin>>a>>n;
    std::cout << Degree(a,n);
  }
  {//task 2
   int chisl,znamen,gcd;
    std::cout << "\nEnter chislitel and znamenatel: ";
    std::cin>>chisl>>znamen;
    Reduce(chisl, znamen);
  }
  {//task 4
    int number;
    std::cout << "\nEnter number: ";
    std::cin >> number;
    DegreeOfTwo(number);
  }
 return 0;
}