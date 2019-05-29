assume cs:code, ds:data
data segment

    pa equ 20a0h ;set address for port A
    pb equ 20a1h ;set address for port B
    pc equ 20a2h ;set address for port C
    cr equ 20a3h  ;set address for control register.

data ends

code segment
start:

    ;usual same 5 lines for configuration of all the hardware programs.
    mov ax,data
    mov ds,ax
        
    mov dx,cr ;mov cr to ax
    mov al,82h ;mov 82h to al
    out dx,al ;output the same.

    mov al,01h

repeat:
    ;output it.
    mov dx,pa
    out dx,al

    call delay ;call the delay procedure.
    ror al,1 ;rotate it. 

    ;Now check if there is any input from the user.
    
    push ax
        mov ah,06 ;check for input
        mov dl,0ffh
        int 21h
        
    pop ax
    jz repeat ;it is set if no input is there, so we repeat if no input is there.
;these lines will end the program.
mov ah,04ch
int 21h

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