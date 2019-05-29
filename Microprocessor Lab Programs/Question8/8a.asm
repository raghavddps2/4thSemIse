assume cs:code
code segment
start:
    
    ;when we call this this gives us the time in cx.
    mov ah,02ch
    int 21h 

    mov al,ch
    aam
    add ax,3030h
    mov bx,ax
    call disp

    mov dl,':'
    mov ah,02h
    int 21h

    mov al,cl
    aam
    add ax,3030h
    mov bx,ax
    call disp
    mov ah,4ch
    int 21h

    disp proc

        mov dl,bh
        mov ah,02
        int 21h

        mov dl,bl
        mov ah,02
        int 21h
        ret

    disp endp




code ends
end start