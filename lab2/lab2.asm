section .data
    var dd 0xDEADBEEF

section .text
    global _start


show:
    mov cl, 0

    push 0x0A000000 ; \n
    add esp, 3      ; fix

 .l:mov eax, 1      ; mask
    shl eax, cl     ; create
    and eax, [var]  ; apply

    jz .z           ; condition
    mov eax, 1      ; z!=0 -> z=1
 .z:add eax, 0x30   ; 0, 1 -> '0', '1'
    shl eax, 24     ; fix
    push eax        ; save
    add esp, 3      ; fix
    add cl, 1       ; loop

    cmp cl, 32      ; compare
    jnz .l          ; repeat

    mov eax, 4      ; write
    mov ebx, 2      ; stdout
    mov ecx, esp    ; message
    mov edx, 33     ; length
    int 80h         ; kernel call
    add esp, 33     ; clear stack
    ret



_start:
    call show

    mov eax, 1
    mov ebx, 0
    int 80h
