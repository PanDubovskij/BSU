#include <iostream>

bool IsDegreeOfTwo(int a) {
  int b;
  _asm {
   mov eax,a
   mov ecx, 0
   again:
   cmp eax,1
    jz the_end
    test eax,1
    jz yes
    inc ecx
    shr eax,1
    jmp again
    yes:
   shr eax,1
    jmp again
   the_end:
   mov b,ecx
  }
  if (b == 0) return true;
  else return false;
}
int NumberOfSignificantDigits(int a) {
  int b;
  _asm {
     mov eax,a
     mov ecx,0
     again:
    test eax,1
    jz yes
    inc ecx
    shr eax,1
    cmp eax,1
     jz the_end
    jmp again
    yes:
   shr eax,1
    cmp eax,1 
    jz the_end
    jmp again
    the_end:
   inc ecx
   mov b,ecx
  }
  return b;
}
int MaxN(int a) {
int n=1;
  _asm {
            mov eax, a
            mov ecx, n
            _next:
            imul ecx
            jo end_
            inc ecx
            jmp _next
             end_:
            mov n,ecx
  }
return n;
}
int main() {
  
  int a;
  std::cout << "Enter a\n";
  std::cin >> a;
  if (IsDegreeOfTwo(a)) std::cout << "True";
  else std::cout << "false";
  std::cout << "\nthe number of significant digits in the binary notation of "
               "an integer: "
            << NumberOfSignificantDigits(a);
  std::cout << "\nMax n: " << MaxN(a);
  return 0;

}