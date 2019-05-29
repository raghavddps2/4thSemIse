assume cs:code,ds:data
data segment

    arr db 50h,40h,30h,20h,10h
    n dw n-arr

data ends

code segment
start:

    mov ax,data
    mov ds,ax
    mov bx,n
    dec bx
    next_pass:
        mov cx,bx
        mov ah,00h
        lea si,arr
        next_comp:
            mov al,[si]
            cmp al,[si+1]
            jle do_nothing
            xchg al,[si+1]
            mov [si],al
            mov ah,01h
        do_nothing:    
            inc si
            loop next_comp
            cmp ah,00
            je finish
            dec bx
            jmp next_pass

    
finish:
    mov ah,4ch
    int 21h
code ends
end start
