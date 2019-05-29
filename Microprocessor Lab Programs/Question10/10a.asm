assume cs:code,ds:data
data segment

    fname db "TEST.txt"
    buff db 100 dup(?)
    errorMsg db "File not found$"
    successMsg db "File closed successfully$"

data ends

code segment
start:

    mov ax,data
    mov ds,ax

    lea dx,fname
    mov ah,03dh
    int 21h

    jnc next
    lea dx,errorMsg
    mov ah,09
    int 21h

    jmp display


    next:

        lea dx,buff
        mov cx,100d
        mov bx,ax
        mov ah,03fh
        int 21h

    mov cx,100d
    lea si,buff 
    label1:

        mov dl,[si]
        mov ah,02
        int 21h

        inc si
        loop label1

        mov ah,03ch
        int 21h
        
        lea dx,successMsg
        mov ah,09
        int 21h
        jmp display

    display:
        mov ah,4ch
        int 21h

code ends
end start