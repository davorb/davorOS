;
; as simple boot sector program that loops forever
;
        [org 0x7c00]
        KERNEL_OFFSET EQU 0x1000 ; memory offset at which kernel is loaded

        mov [BOOT_DRIVE], dl

        mov bp, 0x9000          ; set up stack
        mov sp, bp

        mov bx, MSG_REAL_MODE
        call print_string

        call load_kernel

        call switch_to_pm

        %include "print_string.asm"
        %include "print_string_pm.asm"
        %include "gdt.asm"
        %include "switch_to_pm.asm"
        %include "disk_load.asm"

        jmp $

        [bits 16]
load_kernel:
        mov bx, MSG_LOAD_KERNEL ; print message saying kernel is loading
        call print_string

        mov bx, KERNEL_OFFSET   ; parameters for disk load
        mov dh, 15              ; first 15 sectors
        mov dl, [BOOT_DRIVE]

        call disk_load

        ret

        [bits 32]
        [extern main]
BEGIN_PM:
        mov ebx, MSG_PROT_MODE
        call print_string_pm

        ;; call KERNEL_OFFSET ; run kernel code
        call KERNEL_OFFSET

        jmp $

        BOOT_DRIVE    db 0
        MSG_REAL_MODE db "In 16-bit real mode.", 0
        MSG_PROT_MODE db "In 32-bit protected mode.", 0
        MSG_LOAD_KERNEL db "Loading kernel into memory.", 0

        HELLO_MESSAGE db "Hello, world!", 0

        ;; padding and magic number
        times 510-($-$$) db 0           ; make the program fit into 512 bytes

        dw 0xaa55                       ; last two bytes form the magic
                                        ; number, so bios knows we are a boot
                                        ; sector
