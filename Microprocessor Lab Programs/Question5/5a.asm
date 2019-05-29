assume cs:code,ds:data
data segment

    n db 5
    fact db ?

data ends

code segment
start:

    mov al,n
    call fact
    mov ah,04ch
    int 21h
    mov ah,00h ;have to make it as we use ah
    fact proc

        cmp al,00h
        jmp cal
        
        push ax
            dec al
            call fact
        pop ax
        mul res ;multiply with whatever is popped out.
        mov res,al ;store result finally in al.
        ret 

        cal:
            mov fact,01
            ret

    fact endp

code ends
end start