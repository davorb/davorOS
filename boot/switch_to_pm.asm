        [bits 16]
switch_to_pm:
        mov eax, 0xfafafafa     ; test message

        cli                     ; clear interrupts
        lgdt [gdt_descriptor]   ; load gdt

        mov eax, cr0            ; make switch to protected mode
        or eax, 0x1             ; the first bit of cr0
        mov cr0, eax

        jmp CODE_SEG:init_pm    ; far jump to flush cache

        [bits 32]
init_pm:
        mov ax, DATA_SEG        ; point segments to data selector in gdt
        mov ds, ax
        mov ss, ax
        mov es, ax
        mov fs, ax
        mov gs, ax

        mov ebp, 0x90000        ; update stack position so its right
        mov esp, ebp             ; ontop of the free space

        call BEGIN_PM
