#include <iostream>
extern "C" int _fastcall IsPerfect(int number);
extern "C" int _fastcall IsSimple(int number);
extern "C" int _fastcall Delete3and6(int number);
    /*int Delete3and6(int number) {
  int reverse = 0;
  _asm {
  mov eax,number
  begin:
  mov ebx,10
  cmp eax,0
  je next
  cdq
  idiv ebx
  cmp edx,3
  je begin
  mov ebx,reverse
  imul ebx,10
  add ebx,edx
  mov reverse,ebx
  jmp begin
   next:
  mov eax,reverse
  mov number,0
  begin2:
  mov ebx,10
  cmp eax,0
  je the_end
  cdq
  idiv ebx
  cmp edx,6
  je begin2
  mov ebx,number
  imul ebx,10
  add ebx,edx
  mov number,ebx
  jmp begin2
   the_end:
  }
  return number;
}*/
int main() {

 ////task1
 int number;
 std::cout<<"Enter number: ";
 std::cin>>number;
 //if(IsPerfect(number))std::cout<<"The number is perfect\n";
 //else std::cout<<"The number isn't perfect\n";


 ////task2
 //if (IsSimple(number))
 //  std::cout << "The number is simple\n";
 //else
 //  std::cout << "The number isn't simple\n";


 //task3
 std::cout<<"Number without 3 and 6: "<<Delete3and6(number);
}