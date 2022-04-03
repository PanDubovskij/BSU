.386
.model flat
;public _FindRowWithMaxNum@12
.code
_FindRowWithMaxNum@12 proc
mov ebp,0 ;максимальное количество идущих подряд единиц
mov edx,0 ;количество единиц в строке
mov ecx,0 ; i – номер текущей строки A 
 begin_n: 
 mov ebx,0 ; j – номер текущего элемента A 
 begin_m: 
 ; адрес A[i][j] равен A+(i*m+j)*размер элемента
 ; вычисляем i*m+j 
 mov eax,[esp+12] 
 mul ecx 
 add eax,ebx 
 mov esi,eax ; esi= (i*m+j) 
 mov edi,[esp+4][esi*4] ; edi = A[i][j] 
 cmp edi,1
 jne next
 inc edx
 cmp edx,ebp
 jng next
 mov ebp,edx
 next:
 inc ebx ; к следующему элементу в строке
 cmp ebx,[esp+12] 
 jl begin_m ; не все элементы обработаны 
 inc ecx ; к следующей строке
 cmp ecx,[esp+8] 
 jl begin_n ; не все строки обработан
 mov eax,ebp
ret 12
_FindRowWithMaxNum@12 endp
end