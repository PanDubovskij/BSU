.586
.model flat
public _FindIndex@8
.code
_FindIndex@8 proc
mov esi,[esp+4]
  mov ah,[esi]
  mov bh,0
 begin_while:
  cmp ah,0
  je end_while
  inc esi
  mov ah,[esi]
  inc bh
  jmp begin_while
   end_while:
  xor ecx,ecx
  mov cl,bh

  mov al,[esp+8]
  mov edi,[esp+4]
  cld
  repne scasb
  jecxz not_found
  xor eax,eax
  dec ecx
  mov eax,ecx
  jmp the_end
  not_found:
  mov eax,-1
  the_end:
ret 8
_FindIndex@8 endp
end