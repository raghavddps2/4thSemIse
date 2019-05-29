assume cs:code

code segment
start:

        mov ah,00h ;interuupt for setting up the video mode.
        mov al,03h ;interuupt for a particular screen size.
        int 10h 

        mov ah,02h ;this is to set the cursor
        mov dh,12d ;setting the row
        mov dl,40d ;setting the column.
        int 10h

        mov ah,09h ;this is to place the X
        mov al,'X' ;x will be printed.
        mov bl,12h ;this is for the color.
        mov cl,1 ;this tells number of times.
        int 10h

        ;any user input without echo.
        mov ah,07h
        int 21h
        ;exit
        mov ah,04ch
        int 21h


code ends
end start