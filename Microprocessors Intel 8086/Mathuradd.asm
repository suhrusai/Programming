assume CS: Code, DS: Data
Data Segment
x db 04h
y db 04h
Data Ends
Code Segment
start : mov ax, Data
        mov DS, ax
        mov Al, x 
        mov Bl, y
        add Al, Bl
        int 03h
Code Ends
End Start
