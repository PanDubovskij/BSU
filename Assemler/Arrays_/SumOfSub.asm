.486
PUBLIC @func3@8

.model flat
.data
.code

@func3@8 proc 
local A:dword, n:dword
 mov ebx, ecx;
 xor eax, eax
        mov eax, edx;
        mov edi, edx;
        xor edx, edx;
        sal eax, 1
        mov n, eax
        mov edx, eax
        sub edx, 2
        xor ecx, ecx
        xor eax, eax

        L :
        xor esi, esi
            mov ax, [ebx][ecx]
            cmp ax, 10
            jg NEXT
            cmp ax, -10
            jl NEXT
            cmp ecx, n
            je P

            mov esi, ecx
            F :
        mov ax, [ebx][ecx + 2]
            mov[ebx][ecx], ax
            add ecx, 2
            cmp ecx, n
            jne F
            mov ax, 0
            mov[ebx][edx], ax
            sub edx, 2
            mov ecx, esi
            mov eax, n
            sub eax, 2
            mov n, eax
            jmp L

            NEXT :
        add ecx, 2
            cmp ecx, n
            jne L

            P :
        mov n, edi
ret
@func3@8 endp
end