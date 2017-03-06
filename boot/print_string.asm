print_string:
        mov ah, 0x0e            ; BIOS teletype output

loop:
        mov al, [bx]
        int 0x10                ; print character in al

        add bx, 1
        cmp al, 0
        jne loop

        ret
