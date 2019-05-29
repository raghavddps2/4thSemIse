assume cs:code,ds:data
data segment

    fib db 10 dup(?)
    n db 05h

data ends

code segment
start:

    mov ax,data
    mov ds,ax

    lea si,fib
    mov al,00h
    mov [si],al
    inc si
    mov bl,01h
    mov [si],bl
    inc si
    mov ch,00h
    mov cl,n
    sub cl,2

    next_num:
        add al,bl
        mov [si],al
        inc si
        xchg al,bl
        loop next_num

    mov ah,4ch
    int 21h

code ends
end start