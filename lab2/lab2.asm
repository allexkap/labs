section .data
    var dd 0xDEADBEEF

section .text
    global _start


show:
    mov cl, 0

    push 0x0A000000 ; \n
    add esp, 3      ; fix

 .l:mov edx, 0x31   ; '1'
    mov ebx, 1      ; mask
    shl ebx, cl     ; create
    and ebx, eax    ; apply

    jnz .n          ; skip next line
    sub edx, 1      ; '1' -> '0'
 .n:shl edx, 24     ; fix
    push edx        ; save
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
    mov eax, [var]
    call show

    mov eax, 1
    mov ebx, 0
    int 80h
