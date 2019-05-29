assume cs:code,ds:data
data segment

    pa equ 20a0h
    pb equ 20a1h
    pc equ 20a2h
    cr equ 20a3h
    rowval db ?
    colval db ?
    scode db ?

data ends

code segment
start:

    mov ax,data
    mov ds,ax

    mov dx,cr
    mov al,90h
    out dx,al


try_again:
    mov bl,01h ;defines start as 01
    mov bh,03h ;defines as 03h 
    mov cl,00h ;start with ch 00h
    mov ah,00h

next_row:
    ;this configures the output port.
    mov dx,pc
    mov al,bl
    out dx,al

    mov dx,pa ;sets up the input port
    in al,dx ;taks single key input
    
    cmp al,00h ;we commpare al with 00h, it will have some value if input is taken
    jne calculate ;if not equal jump to calculate.
    add cl,08h ;we add 08 to cl
    inc ah ;we incremment the value in ah
    shl bl,1 ;we perform shift left on bl.
    dec bh; we decrease bh
    jnz next_row ;if rows remaining jump to next row.
    jmp try_again ;we will then try again.

calculate:
    ;we have got the row number now.
    mov rowval,ah
    mov ah,00 ;we put 00h back in ah
rotate:
    ror al,01
    jc next ;jump if carry to next
    inc ah
    inc cl
    jmp rotate
next:
    mov scode,cl
    mov colval,ah;now we 
    mov al,cl ;ax becomes colval,scancode.
    call disp ;call display function
    mov ah,4ch
    int 21h


disp proc
    mov bl,al
    mov cl,4
    shr al,cl ;rotate it by cl
    cmp al,09
    jle add_30
    add al,07 ;ASCII values.

add_30:
    add al,30h
    mov dl,al
    mov ah,02
    int 21h

    mov al,bl
    and al,0fh
    cmp al,09
    jle add_30_1
    add al,07

add_30_1:
    add al,30h
    mov dl,al
    mov ah,02
    int 21h
    ret

disp endp

code ends
end start