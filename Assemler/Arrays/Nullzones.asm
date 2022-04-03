.586
.model flat
public _Nullzones@8 ;(int* arr,int size)
.code
_Nullzones@8 proc
push ebp
mov ebp, esp
mov ebx,[ebp+8] 
sub ebx,4
mov ecx, [ebp+12]
mov eax,0
       repeat_:
       cmp ecx,0
        je the_end
       mov edx,[ebx]
       cmp edx,0
       je zero
        add ebx,4
       loop repeat_
        jmp the_end
        zero:
        dec ecx
       add ebx,4
       mov edx,[ebx]
        
        cmp edx,0
        je zero
        inc eax
        jmp repeat_
        the_end:
       pop ebp
ret 8
_Nullzones@8 endp
end
