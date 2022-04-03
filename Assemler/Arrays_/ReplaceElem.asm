.586
.model flat
public _ReplaceElem@8
.code
_ReplaceElem@8 proc
   mov ecx,[esp+8]
   mov ebx, [esp+4]
   mov edx, [ebx]
   sub ebx,4
   begin:
  cmp ecx, 0
	jz the_end
	dec ecx
  add ebx,4
  mov eax,[ebx]
  cmp eax,0
  jle begin
  cmp eax,edx
  jng min_elem
  jmp begin
   min_elem:
  mov edx,[ebx]
	mov esi, ebx
   jmp begin
   the_end:
  mov ecx,[esp+8]
  mov ebx, [esp+4]
  sub ebx,4
  change:
  cmp ecx, 0
	jz the_end2
	dec ecx
  add ebx,4
  mov eax,[ebx]
  cmp eax,0
  jge change
  mov [ebx], edx
  jmp change
   the_end2:
ret 8
_ReplaceElem@8 endp
end