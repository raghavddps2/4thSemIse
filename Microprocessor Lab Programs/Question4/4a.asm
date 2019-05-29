assume cs:code,ds:data

data segment

    str1 db "madam"
    len1 db len1-str1
    str2 db 10 dup(?)
    msg1 db "Pallindrome$"
    msg2 db "Not a pallindrome$"

data ends

code segment
start:

    mov ax,data
    mov ds,ax

    mov cx,len1
    lea si,n
    dec si
    lea di,str2
    form_str_2:
        mov al,[si]
        mov [di],aassume cs:code,ds:data

data segment

    str1 db "madame"
    n dw n-str1 
    str2 db 10 dup(?)
    msg1 db "Pallindrome$"
    msg2 db "Not a pallindrome$"

data ends

code segment
start:

    mov ax,data
    mov ds,ax

    mov es,ax //Very importtant for cmpsb instruction.

    mov cx,n

    lea si,n
    dec si

    lea di,str2

    form_str_2:
        mov al,[si]
        mov [di],al
        dec si
        inc di
        loop form_str_2
        mov cx,n ;for the rep cmpsb instruction
        lea si,str1
        lea di,str2
        cld ;clear the direction flag
        rep cmpsb
        jnz not_a_pallin

        lea dx,msg1
        jmp display

    not_a_pallin:
        lea dx,msg2
        jmp display

    display:
        mov ah,09h
        int 21h

        mov ah,04ch
        int 21h

    code ends
    end start

code ends
end start
        dec si
        inc di
        loop form_str_2
        lea si,str1
        lea di,str2
        cld ;clear the direction flag
        rep cmpsb
        jnz not_a_pallin
        mov dx,msg1
        jmp display

    not_a_pallin:
        mov dx,msg2
        jmp display

    display:
        mov ah,09h
        int 21h

        mov ah,04ch
        int 21h

    code ends
    end start

code ends
end start