.586
.model flat
public @CountLength@4
.code
@CountLength@4 proc
  mov esi,ecx
  mov ah,[esi] ;//cur char
  mov bh,0
 begin_while:
  cmp ah,0
  je end_while
  inc esi
  mov ah,[esi]
  inc bh
  jmp begin_while
   end_while:
  xor eax,eax
  mov al,bh
ret 
@CountLength@4 endp
end