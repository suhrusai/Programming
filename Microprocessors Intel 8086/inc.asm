assume CS: Code DS: Data
Data segment
data ends
Code segment
start:
    mov ax,00h
    inc ax
    inc ax
    inc ax
    inc ax
    int 03h
code ends 
ends start
    