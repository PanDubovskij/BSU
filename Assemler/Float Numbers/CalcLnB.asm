.586
.model flat
.data
one dq 1.0
neg_one dq -1.0
two dq 2.0
four dq 4.0
result dq 0.0
sum dq 0.0
log dq 0.0
k dd 0
public _CalcLn@4 ;function declaration
.code
_CalcLn@4 proc
push ebp
mov ebp,esp
mov ecx,[ebp+8];
      finit
    cycle:
   mov k,ecx
    fld1
    fild k
    fdiv
    fstp result

    test ecx,1
    jne next
    fld result 
    fchs
    fstp result

    next:
    fld result
    fld sum
    fadd
    fstp sum
    loop cycle
    lea eax,sum
   pop ebp
ret 4
_CalcLn@4 endp
end