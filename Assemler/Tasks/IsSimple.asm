.586
.model flat
public @IsSimple@4
.code
@IsSimple@4 proc
  mov esi,ecx
  mov ecx,1
  mov eax,1
  push eax
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
  cmp eax,1
   je the_end2
   mov eax,0
   jmp the_end3
   the_end2:
   mov eax,1
   the_end3:
  
ret
@IsSimple@4 endp
end
