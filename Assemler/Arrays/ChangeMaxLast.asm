.586
.model flat
public _ChangeMaxLast@8 ;(int* arr,int size)
.code
_ChangeMaxLast@8 proc
push ebp
mov ebp, esp
mov ebx,[ebp+8] 
sub ebx,4
mov ecx, [ebp+12]
mov edx,[ebx]
repeat2:
  cmp ecx, 0
	jz the_end2
	dec ecx
  add ebx,4
  cmp [ebx],edx
  jg greater2
  jmp repeat2
   greater2:
  mov edx,[ebx]
	mov eax, ebx
   jmp repeat2
    the_end2:
   mov ecx, [ebx]
	 mov [ebx], edx
	 mov [eax], ecx
       pop ebp
ret 8
_ChangeMaxLast@8 endp
end