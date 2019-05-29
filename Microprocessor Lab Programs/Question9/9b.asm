assume cs:code,ds:data
data segment

    pa equ 20a0h ;setting up the address for port A
    pb equ 20a1h ;setting up the address for port B
    pc equ 20a2h ;setting up the address for port C
    cr equ 20a3h ;setting up the address for control register.
    ;putting up the message (FIRE HELP HERE)
    msg db 0ffh,71h,9fh,0f5h,61h,0ffh,0d1h,61h,0e3h,31h,0ffh,0d1h,61h,0f5h,61h

data ends

code segment
start:

    mov ax,data
    mov ds,ax

    mov dx,cr
    mov al,80h ;setting up the ouput configuration. 
    out dx,al

repeat:
        mov cx,15d ;storing the number of charcaters.
        lea si,msg

    loop1:
        mov al,[si]
        call disp ;display the charracter.
        call delay ;for that roll feel
        inc si ;increment the value of si
        loop loop1 ;loop till all the charcaters are covered.

        ;now we look for the input of any from tthe user.
        mov ah,06
        mov dl,0ffh
        int 21h
        jz repeat

        mov ah,4ch ;exit from the program.
        int 21h 

    disp proc

        ;this one is to put into cx the number of bits.
        push cx
        mov cx,08

    nextbit:    ;for the output port B
            mov dx,pb
            out dx,al

            push ax
            ;all for port C below
            mov dx,pc
            mov al,0ffh
            out dx,al

            mov al,00h
            out dx,al

            pop ax ;pop out ax
            ror al,1 ;rotate the al
            loop nextbit ;jump to the nextbit
            pop cx ; we need to op cx as well.
            ret

    disp endp

    delay proc
        mov bx,0ffffh
        l1: mov di,0ffffh
        l2: dec di
        jnz l2
        dec bx
        jnz l1
        ret
    delay endp

code ends
end start