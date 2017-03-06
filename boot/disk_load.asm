        ;; load DH sectors to ES:BX from drive DL
        [bits 16]
disk_load:
        push dx                 ; store dx on stack so we can recall
        ;; how many sectors were requested to be read even if
        ;; dx is altered

        mov ah, 0x02            ; bios read sector function

        mov al, dh              ; read dh sectors
        mov ch, 0x00            ; cylinder 0
        mov dh, 0x00            ; head 0

        ;; start reading from second sector
        ;; i.e. after the boot sector
        mov cl, 0x02

        int 0x13                ; bios interrupt

        jc disk_error           ; jump if error

        pop dx
        cmp dh, al              ; if AL (sectors read) != DH (sectors expected)
        jne disk_error
        ret

disk_error:
        mov bx, DISK_ERROR_MSG
        call print_string
        jmp $

DISK_ERROR_MSG db "Disk read error!", 0
