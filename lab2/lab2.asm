section .data
    var dd 0xDEADBEEF

section .bss
    tmp resb 64

section .text
    global _start


show:
    mov eax, [var]  ; value
    mov ecx, 0      ; zeroing

    mov ebx, tmp    ; position
    add ebx, 0x20   ; offset
    mov edx, 0x0A   ; '\n'
    mov [ebx], dl   ; save

 .l dec ebx         ; previous cell
    mov edx, 0x30   ; preparation

    test eax, 1     ; mask
    jz .z           ; condition
    inc dl          ; '0' -> '1'

 .z shr eax, 1      ; next bit   
    mov [ebx], dl   ; save

    inc cl          ; increase
    cmp cl, 32      ; compare
    jnz .l          ; repeat

    mov eax, 4      ; write
    mov ebx, 1      ; stdout
    mov ecx, tmp    ; message
    mov edx, 33     ; length
    int 128         ; kernel call
    ret             ; return


calc:
    mov eax, [var]  ; value
    mov ecx, 0      ; zeroing
    mov edx, 0      ; zeroing

 .l test cl, 111b   ; only 3 low bits
    jnz .n          ; check 8|ch
    ror edx, 8      ; new cell

 .n test eax, 1     ; mask
    jz .z           ; check bit
    inc edx         ; increase cell

 .z shr eax, 1      ; next bit

    inc cl          ; increase
    cmp cl, 32      ; compare
    jnz .l          ; repeat

    ror edx, 8      ; zero cell
    mov [tmp], edx  ; save
    ret             ; return


sort:
    mov ecx, 0      ; zeroing
 .o mov edx, 0      ; zeroing
 .l mov ebx, tmp    ; position
    add ebx, edx    ; offset
    
    mov al, [ebx]   ; 1 -> al
    inc ebx         ; next
    mov ah, [ebx]   ; 2 -> ah

    cmp al, ah      ; compare
    jle .e          ; al > ah

    mov [ebx], al   ; al -> 2
    dec ebx         ; previous
    mov [ebx], ah   ; ah -> 1

    mov ebx, var    ; position
    add ebx, edx    ; offset
    mov al, [ebx]   ; 1 -> al
    inc ebx         ; next
    mov ah, [ebx]   ; 2 -> ah
    mov [ebx], al   ; al -> 2
    dec ebx         ; previous
    mov [ebx], ah   ; ah -> 1

 .e inc dl          ; increase
    cmp dl, 3       ; compare
    jnz .l          ; repeat
    inc cl          ; increase
    cmp cl, 4       ; compare
    jnz .o          ; repeat
    ret             ; return



_start:
    call show       ; show binary
    call calc       ; calc params
    call sort       ; bubble sort
    call show       ; show binary

    mov eax, 1      ; exit
    mov ebx, 0      ; status
    int 128         ; kernel call
