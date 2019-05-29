assume cs:code,ds:data
data segment

    pa equ 20a0h ;sets address for port A
    pb equ 20a1h ;sets address for port B
    pc equ 20a2h ;sets address for port C
    cr equ 20a3h ;sets address for control register.

data ends

code segment
start:

    mov ax,data ;sends the data to ax
    mov ds,ax ; sends ax to the data segment register.

    mov dx,cr ;move the control register value to dx
    mov al,82h ;move to al the 82h for configuring the ports.
    out dx,al ;output port setup kiye.

    mov cx,15h ;this is 20 in decimal, so will go from 0 to 20.
    ;Setup the output port here.
    mov dx,pa ;setup the output port.
    mov al,00h ;put 0 in al

next:
    out dx,al ;output this
    call delay
    add al,01 ;add to al
    daa ;decimal adjust after addition is needed.
    loop next ;loop again until everything till 20 is done.
    mov cx,15h ;again put decimal 20

next1:
    sub al,01 ;subtract 1 from al.
    das ;use decimal adjust after subtraction
    out dx,al ;output the same.
    call delay
    loop next

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