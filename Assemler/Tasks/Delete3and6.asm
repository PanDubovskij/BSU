.586
.model flat
public @Delete3and6@4
.code
@Delete3and6@4 proc
  mov eax,ecx
  mov esi,ecx
  mov ebx,0
  push ebx
  begin:
  mov ebx,10
  cmp eax,0
  je next
  cdq
  idiv ebx
  cmp edx,3
  je begin
  pop ebx
  imul ebx,10
  add ebx,edx
  push ebx
  jmp begin
   next:
  push eax
  mov esi,0
  mov eax,ecx
  begin2:
  mov ebx,10
  cmp eax,0
  je the_end
  cdq
  idiv ebx
  cmp edx,6
  je begin2
  mov ebx,esi
  imul ebx,10
  add ebx,edx
  mov esi,ebx
  jmp begin2
   the_end:
   mov eax,esi
ret
@Delete3and6@4 endp
end