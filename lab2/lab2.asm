section .data
    var dd 0xDEADBEEF

section .bss
    tmp resb 64

section .text
    global _start


show:
    mov cl, 0       ; loop
    mov ebx, tmp    ; position
    add ebx, 0x20   ; offset
    mov eax, 0x0A   ; '\n'
    mov [ebx], al   ; save

 .l:mov eax, 1      ; mask
    shl eax, cl     ; create
    and eax, [var]  ; apply

    jz .z           ; condition
    mov eax, 1      ; z != 0 -> z = 1
 .z:add eax, 0x30   ; 0, 1 -> '0', '1'
    
    sub ebx, 1      ; previous cell
    mov [ebx], al   ; save

    add cl, 1       ; increase
    cmp cl, 32      ; compare
    jnz .l          ; repeat

    mov eax, 4      ; write
    mov ebx, 2      ; stdout
    mov ecx, tmp    ; message
    mov edx, 33     ; length
    int 80h         ; kernel call
    ret             ; return



_start:
    call show       ; show binary

    mov eax, 1      ; exit
    mov ebx, 0      ; status
    int 80h         ; kernel call
