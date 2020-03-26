assume cs:code,ds:data,ss:stack
data segment
num1 db 05h
num2 db 06h
sum db ?
su db ?
data ends
stack segment
stack ends;
code segment
start: mov ax,data;
mov ds,ax
mov ax,stack;
call addition
int 03h
addition proc near
mov al,num1;
mov bl,num2;
add al,bl;                                       
mov sum,al;
ret
addition endp
code ends
end start

