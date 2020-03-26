assume cs:code, ds:data
data segment
data ends
code segment
start:
        mov al,07h
        mov ah,07h
        mov bl,08h
        mov bh,08h
        add ax,bx
        aaa
        int 03h
code ends
end start
