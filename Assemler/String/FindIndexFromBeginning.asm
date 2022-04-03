.586
.model flat
public _FindIndexFromBeginning@8
.code
_FindIndexFromBeginning@8 proc
xor eax, eax
mov ebx,dword ptr[esp+4]
_length:
inc eax
cmp byte ptr [ebx+eax],0
jne _length

mov ecx,eax
mov esi,dword ptr[esp+4]
add esi,eax
mov al,byte ptr [esp+8]
std
repne scasb
jecxz _not_found
mov eax,ecx
jmp _end
_not_found:
mov eax,-1
_end:

ret 8
_FindIndexFromBeginning@8 endp
end