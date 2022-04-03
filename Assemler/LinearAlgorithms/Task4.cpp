#include <iostream>  
//Написать программу, которая по заданному количеству секунд определяет количество часов, минут и секунд.

int main() {
  int sec, hour, min, secn;
  std::cout << "Enter seconds\n";
  std::cin >> sec;
  _asm
      {
   mov eax, sec
   mov ebx,3600
   mov ecx,24
   cdq
   div ebx
   cdq 
   div ecx
   mov hour,edx
   mov eax,sec
   mov ebx,60
   cdq
   div ebx
   cdq
   div ebx
   mov min,edx
   mov eax,sec
   mov ebx,60
   cdq
   div ebx
   mov secn,edx

      }
  std::cout << hour << ":" << min / 10 << "" << min % 10 << ":" << secn / 10
            << "" << secn % 10;
  return 0;
}
