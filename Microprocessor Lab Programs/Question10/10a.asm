assume cs:code,ds:data

data segment
    fileName db "raghav.txt" ;name of the file
    buff db 50 dup(0)  ;an array for getting the contents of the file.
    errorMsg db 0ah,0dh,"File not found$"
    closeMsg db 0ah,0dh,"File closed successfully$"
data ends


code segment
start:

    mov ax,data
    mov ds,ax

    ;Note that for opening file (03dh)
    ;note that for closing file (03eh)
    ;note that for reading from dile (03f)

    mov ah,03dh ;set the value as 03dh, opening
    lea dx,fileName
    mov al,0 ;this means in the read mode.
    int 21h ;close the interrupt.

    ;this interrupt will set the carry flag if file is not found, so if no carry jump to next.
    jnc label1 ;jump to the loop to read from the file and then close it.
    ;other wise, load error message in dx and jump to display.
    lea dx,errorMsg;
    mov ah,09h
    int 21h
    jmp display

    label1:
        mov ah,03fh ;for reading the file, and putting buff in dx.
        mov cx,50d
        lea dx,buff
        int 21h

        mov cx,50d ;define cx for the loop to occur.
        lea si,buff ;put buff in si

    repeat:
        mov dl,[si] ;put in dl and print it
        mov ah,02
        int 21h
        inc si ;innc si and again loop to repeat
        loop repeat
    
    ;closing the file
    mov ah,03eh
    int 21h
    ;displaying the message.
    lea dx,closeMsg
    mov ah,09h 
    int 21h

    display:
        mov ah,4ch
        int 21h

code ends
end start