assume cs:code,ds:data
data segment

    arr db 10h,20h,30h,40h,50h
    n db n-arr
    key db 70h
    msg1 db "Key not found$"
    msg2 db "Key found at position:"
    pos db ?,"$"

data ends

code segment
start:

    mov ax,data
    mov ds,ax

    mov al,0
    mov dl,n
    dec dl ; as we take till n-1 only.
    mov ah,00
    next:
        cmp al,dl
        ja failed
        mov cl,al
        add al,dl
        shr al,1
        mov si,ax
        mov bl,[si]
        cmp bl,key       
        jge next2
        inc al
        jmp next

    next2:
        je success
        dec al
        mov dl,al
        mov al,cl
        jmp next

    success:
        inc al
        add ax,3030h
        mov pos,al
        lea dx,msg2
        jmp display

    failed:
        lea dx,msg1
        jmp display

    display:
        mov ah,09
        int 21h

        mov ah,04ch
        int 21h

    code ends
    end start