assume cs:code,ds:data
data segment

    pa equ 20a0h
    pb equ 20a1h
    pc equ 20a2h
    cr equ 20a3h
    fire db 71h,9fh,0f5h,61h ;values for fire on a seven segment display
    help db 0d1h,61h,0e3h,31h ;values for help on a seven segment display.
data ends

code segment
start:

    ;we write the standard lines for writing any Hardware programs. Here the port is 80h
    mov ax,data
    mov ds,ax 

    mov dx,cr
    mov al,80h
    out dx,al

repeat:
    mov cx,04
    lea si,fire

    ;for dispplaying fire
    loop1:
        mov al,[si] ;we move the value to al
        call disp ;we call the display function
        inc si ;we increment the si value.
        loop loop1 ;for the next character, we loop

        call delay ;wait for some time and display the nexyt word.
        mov cx,04h ;we again put 4 in cx.

    ;for displaying help.
    loop2:
        mov al,[si]
        call disp
        inc si
        loop loop2

        call delay ;we have to call delay again here.
        ;Now we check if there is any user input
        mov ah,06h
        mov dl,0ffh
        int 21h
        jz repeat ;if zero flag set, jump back to repeat.

    mov ah,4ch
    int 21h

;Now we have to learn how to write the disp and the delay procedure.
disp proc
    push cx
    mov cx,8 ;as we have from a to h.

    next_bit:

        ;we define the output port b
        mov dx,pb
        out dx,al 

        ;here we use it to determine the value of al.
        push ax

        mov dx,pc ;told about the port.

        ;we move 0ffh
        mov al,0ffh
        out dx,al

        ;now we move 00h
        mov al,00h
        out dx,al

        pop ax ;we pop the ax here.
        ror al,1 ;it is very very important to rotate. :)))
        loop next_bit ;we loop for the next bit.
        ;after everything is done, just pop ax.
        pop cx
        ret
disp endp

delay proc

    mov si,0ffffh
    l1: mov di,0ffffh
    l2: dec di
    jnz l2
    dec si
    jnz l1
    ret

delay endp

code ends
end start