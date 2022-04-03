.586
.model flat
public _FindWord@8
.code
_FindWord@8 proc
mov esi,[esp+4]
mov ah,[esi]  ;cur char of str
mov edi,[esp+8]
mov bh,[edi]  ;cur char of sub_str
mov al,0 ;index
mov cl,0 ;index of sub_str
cycle:
mov dl,0
cmp ah,0
je the_end
cmp ah,bh
je equal
inc al
inc esi
inc edi
mov ah,[esi] 
mov bh,[edi]
jmp cycle
equal:
cmp ah,0
je the_end
inc dl
mov cl,al
inc al
inc esi
inc edi
mov ah,[esi] 
mov bh,[edi]
cmp ah,bh
je equal
sub cl,dl
jmp cycle
the_end:
xor eax,eax
mov al,cl
_FindWord@8 endp
end