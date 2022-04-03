.586
.model flat
.data
one dq 1.0
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
    fld one
    fild k
    fild k
    fld four
    fmul;4*k
    fmul;4*k*k
    fsubr;4*k*k-1
    fld two
    fild k
    fmul
    fmul
    fld one
    fdivr
    fstp result
    fld sum
    fld result
    fadd
    fstp sum
    loop cycle
    fld one
    fld two
    fdiv
    fld sum
    fadd
    fstp log
    lea eax,log
   pop ebp
ret 4
_CalcLn@4 endp
end