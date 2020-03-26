addition macro num1,num2,sum
mov ax,[si]
mov bx,[si+2]
add ax,bx
mov sum,ax
endm
assume cs:code,ds:data
data segment
        a dw 0004h
        b dw 0007h
        res dw ?
data ends
code segment
start:  mov ax,data
        mov ds,ax
        addition a,b,res
        int 03h
code ends
end start
