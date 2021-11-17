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

 .l mov edx, eax    ; copy
    shr eax, 1      ; next bit
    and edx, 1      ; mask

    jz .z           ; condition
    mov edx, 1      ; z != 0 -> z = 1
 .z add edx, 0x30   ; 0, 1 -> '0', '1'
    
    sub ebx, 1      ; previous cell
    mov [ebx], dl   ; save

    add cl, 1       ; increase
    cmp cl, 32      ; compare
    jnz .l          ; repeat

    mov eax, 4      ; write
    mov ebx, 1      ; stdout
    mov ecx, tmp    ; message
    mov edx, 33     ; length
    int 80h         ; kernel call
    ret             ; return


calc:
    mov eax, [var]  ; value
    mov ecx, 0      ; zeroing
    mov edx, 0      ; zeroing

 .l mov ch, cl      ; copy
    shl ch, 5       ; only 3 low bits
    jnz .n          ; check 8|ch
    ror edx, 8      ; new cell

 .n mov ebx, eax    ; copy
    shr eax, 1      ; next bit
    and ebx, 1      ; mask

    jz .z           ; condition
    add edx, 1      ; increase cell

 .z add cl, 1       ; increase
    cmp cl, 32      ; compare
    jnz .l          ; repeat

    ror edx, 8      ; zero cell
    mov [tmp], edx  ; save
    ret             ; return


sort:
    mov ch, 0       ; zeroing
 .h mov cl, 0       ; zeroing
 .l mov edx, 0      ; zeroing
    mov dl, cl      ; cl -> edx

    mov ebx, tmp    ; position
    add ebx, edx    ; offset
    mov al, [ebx]   ; 1 -> al
    add ebx, 1      ; next
    mov ah, [ebx]   ; 2 -> ah

    cmp al, ah      ; compare
    jle .e          ; al > ah

    mov [ebx], al   ; al -> 2
    sub ebx, 1      ; previous
    mov [ebx], ah   ; ah -> 1

    mov ebx, var    ; position
    add ebx, edx    ; offset
    mov al, [ebx]   ; 1 -> al
    add ebx, 1      ; next
    mov ah, [ebx]   ; 2 -> ah
    mov [ebx], al   ; al -> 2
    sub ebx, 1      ; previous
    mov [ebx], ah   ; ah -> 1

 .e add cl, 1       ; increase
    cmp cl, 3       ; compare
    jnz .l          ; repeat
    add ch, 1       ; increase
    cmp ch, 4       ; compare
    jnz .h          ; repeat
    ret             ; return



_start:
    call show       ; show binary
    call calc       ; calc params
    call sort       ; bubble sort
    call show       ; show binary

    mov eax, 1      ; exit
    mov ebx, 0      ; status
    int 80h         ; kernel call
