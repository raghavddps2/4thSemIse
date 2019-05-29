assume cs:code,ds:data
data segment

    pa equ 20a0h ;setting address for port A
    pb equ 20a1h ;setting Address for port B
    pc equ 20a2h ;setting adderess for port C
    cr equ 20a3h ;setting address for control register.
    msg db "No of 1's is:" 
    ones db ?,"$" ;ends the message here basically.

data ends

code segment
start:

    ;Initiallly usual two instructions are fixed.
    mov ax,data
    mov ds,ax

    ;We configure the input port as B and output port as A
    mov dx,cr
    mov al,82h ;configure the port
    out dx,al ;move output to dx

    mov dx,pb ;for the input port.
    in al,dx ;getting the value in al, setting as taking input.


    mov cx,8 ;for counting the number of rotations
    mov ah,00

rot_again:
    ror al,1
    jnc next
    inc ah

next:
    loop rot_again
    mov bl,ah ;we use it later for parity checking.
    add ah,30h
    mov ones,ah

    ;following code displays the message.
    lea dx,msg
    mov ah,09h
    int 21h



    ;After we pass it to the output port, we check the parity.
    mov al,00
    ror bl,1 ;rotate the content in bl.
    jc display ;if carry is genearted matblab ODD.
    mov al,0ffh ;pass this for even.

display:

        ;we have to pass the same to the output port as well.(Parity)
    mov dx,pa
    out dx,al

    mov ah,4ch
    int 21h


code ends
end start