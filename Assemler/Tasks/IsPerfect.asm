.586
.model flat
public @IsPerfect@4
.code
@IsPerfect@4 proc
  mov esi,ecx
  mov eax,1
  push eax
  mov ecx,1
  begin_:
  mov eax,esi
  inc ecx
  cmp ecx,eax
  je the_end
   cdq
  idiv ecx
  cmp edx,0
  jnz begin_
  pop eax
  add eax,ecx
  push eax
   jmp begin_
   the_end:
  pop eax
  mov ebx,esi
  cmp eax,ebx
   je the_end2
   mov eax,0
   jmp the_end3
   the_end2:
   mov eax,1
   the_end3:
   ret
@IsPerfect@4 endp
end