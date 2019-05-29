assume cs:code,ds:data
data segment

    pa equ 20a0h
    pb equ 20a1h
    pc equ 20a2h
    cr equ 20a3h

data ends

code segment
start:

    mov ax,data
    mov ds,ax

    mov dx,cr
    mov al,80h
    mov dx,al

    mov cx,64h ;for 180 degrees 180/1.8 == 100d, comes to be 64 h, for 90 degrees we have 32h
    mov dx,pa
    mov al,77h ;if dpoesnt work try with 11h
    
    rotate:
        out dx,al
        ror al,1 ;(AntiCLockwise) rol(CLockwise)
        call delay
        loop rotate

    mov ah,4ch 
    int 21h

delay proc

    mov si,02fffh
    l1: mov di,0ffffh
    l2: dec di
    jnz l2
    dec si
    jnz l1
    ret

delay endp

code ends
end start