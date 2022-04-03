#include <iostream>
extern "C" int _stdcall Nullzones(int* arr, int size);
extern "C" void _stdcall ChangeMaxLast(int* arr, int size);
void subtask3(int* arr, int n) {
  int freq[1001] = {0};
  int diff_el = 0;
  int biggest_freq = 0;
  _asm {
   xor ecx,ecx
   mov esi,arr
   lea edi,freq
   cycle:
   mov eax,[esi][ecx*4]
   inc [edi][eax*4]
   mov ebx,[edi][eax*4]
   cmp ebx,1
    jne same_el
    inc diff_el
    same_el:
   cmp ebx,biggest_freq
    jle lower_freq
    mov biggest_freq,ebx
    lower_freq:
   inc ecx
    cmp ecx,n
    jl cycle
  }
  std::cout << diff_el << " different elements\n\n Most frequent elements ("
            << biggest_freq << " times): ";
  for (int i = 0; i < 1001; i++) {
    if (freq[i] == biggest_freq) std::cout << "[" << i << "], ";
  }
}
   int main() { 
 {//task 1
       const size_t SizeS=10;
       int* arr = new int[SizeS] {1, 0, 0, 0, 6, 0, 5, 0, 0, 1};
    /*   int count = 0;
       _asm {
       mov eax,count
       mov ecx,SizeS
       mov ebx,arr
       repeat:
       cmp [ebx],0
       je zero
        add ebx,4
       loop repeat
        jmp the_end
        zero:
       dec ecx
       add ebx,4
        cmp [ebx],0
        je zero
        inc eax
        jmp repeat
        the_end:
       mov count,eax
       }*/
       std::cout << "Number of null zones in array: ";
       int count = Nullzones(arr, SizeS);
       std::cout << count<<std::endl;
  }
  {//task2
    const size_t SizeS = 5;
    int arr[] = {1, 7, 3, 8, 4};
    int max = 0;
 //   _asm {
 // mov ecx,SizeS
 // lea ebx,arr
 // mov edx, [ebx]
 // sub ebx,4
 // repeat2:
 // cmp ecx, 0
	//jz the_end2
	//dec ecx
 // add ebx,4
 // cmp [ebx],edx
 // jg greater2
 // jmp repeat2
 //  greater2:
 // mov edx,[ebx]
	//mov eax, ebx
 //  jmp repeat2
 //   the_end2:
 //  mov ecx, [ebx]
	// mov [ebx], edx
	// mov [eax], ecx
 //   }
    ChangeMaxLast(arr, SizeS);
    for (size_t i = 0; i < SizeS; i++) {
      std::cout << arr[i] << " ";
    }
   std::cout<< std::endl;
    
 }
  {//task 3
const size_t n = 8;
int* arr =new int[n] {1, 7, 3, 8, 4,3 ,5,8};
subtask3(arr, n);
  }
 return 0;
}