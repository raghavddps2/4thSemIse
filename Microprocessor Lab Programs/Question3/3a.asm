assume cs:code,ds:data

disp macro mesg
    lea dx,mesg
    mov ah,09
    int 21h
endm


data segment

    pwd1 db 'raghav@123M'
    len1 db len1-pwd1
    pwd2 db 20 dup(?)
    len2 db  ?

    msg1 db 0ah,0dh,"Enter password:$"
    msg2 db 0ah,0dh,"Three attempts exceeded$"
    msg3 db 0ah,0dh,"Passoword matched$"
    msg4 db 0ah,0dh,"Password wrong$"


data ends


code segment
start:

    mov ax,data
    mov ds,ax
    mov es,ax
    mov bl,00h
    repeat:
        call read_pwd
        call match
        inc bl
        cmp bl,03
        jb repeat
        disp msg2
        jmp display
        
        
 read_pwd proc
        disp msg1
        mov bh,00h
        lea si,pwd2

      again:

        mov ah,08
        int 21h
        cmp al,0dh
        je next
        inc bh
        mov [si],al
        inc si
        mov dl,'*'
        mov ah,02h
        int 21h
        jmp again
    next:
        mov len2,bh
        ret

read_pwd endp


match proc near

    
    mov cl,len1
    cmp cl,len2
    je have_to_match
    jmp mismatch

    have_to_match:
        lea si,pwd1
        lea di,pwd2
        cld ;clears the direction flag.
        ;mov ch,00h
        rep cmpsb
        jnz mismatch
        disp msg3
        jmp display


    mismatch:
        disp msg4
        ret


match endp

display:
    mov ah,04ch
    int 21h

code ends
end start