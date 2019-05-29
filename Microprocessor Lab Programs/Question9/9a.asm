

assume cs:code,ds:code

code segment
start:

    mov cx,100d
    mov bl,00h

    next_digit:
        mov ah,00h
        mov al,02h
        int 10h

        mov ah,02h
        mov dh,12d  
        mov dl,40d
        int 10h
        
        mov al,bl
        aam 
        add ax,3030h

        mov dl,ah
        push ax
        mov ah,02h
        int 21h
        pop ax

        mov dl,al
        mov ah,02h
        int 21h

        mov dl,0dh
        mov ah,02h
        int 21h

        call delay
        inc bl
        loop next_digit

    mov ah,4ch
    int 21h

    delay proc
        mov si,0092h
        l1: mov di,0ffh
        l2: dec di
        jnz l2
        dec si
        jnz l1
        ret

    delay endp

code ends
end start