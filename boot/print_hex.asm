        ;;  this isn't working!
print_hex:
        mov bx, HEX_OUT

        add bx, 2
        mov cx, [bx]
        add cl, dl


        mov [bx], cx
        sub bx, 2

        call print_string
        ret

HEX_OUT:         db '0x0000', 0
