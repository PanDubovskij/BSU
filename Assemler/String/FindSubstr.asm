.686
.model flat
public _FindSubstr@16
.code

_FindSubstr@16 proc
cld
mov ecx,[esp+12]
mov ebx,[esp+8]
mov esi,[esp+4]
add esi,ebx
mov edi,dword ptr[esp+16]
rep movsb

ret 16
_FindSubstr@16 endp
end