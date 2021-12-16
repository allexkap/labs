<swap>:
    endbr64
    movzx  eax,BYTE PTR [rdi]   ; ┐
    xor    al,BYTE PTR [rsi]    ; ├ *a ^= *b
    mov    BYTE PTR [rdi],al    ; ┘
    xor    al,BYTE PTR [rsi]    ; ┬ *b ^= *a
    mov    BYTE PTR [rsi],al    ; ┘
    xor    BYTE PTR [rdi],al    ; ─ *a ^= *b
    ret

<main>:
    endbr64                             ; ┐
    push   rbp                          ; ├ enter
    push   rbx                          ; ┘
    sub    rsp,0x18                     ; ┐
    mov    rax,QWORD PTR fs:0x28        ; ├ const
    mov    QWORD PTR [rsp+0x8],rax      ; │
    xor    eax,eax                      ; │
    mov    DWORD PTR [rsp],0xdeadbeef   ; ┘
    mov    ebx,0x1f                     ; ┐
    lea    rbp,[rip+0xe3c] ;            ; ├ show binary
    mov    edx,DWORD PTR [rsp]          ; │
    mov    ecx,ebx                      ; │
    sar    edx,cl                       ; │
    and    edx,0x1                      ; │
    mov    rsi,rbp                      ; │
    mov    edi,0x1                      ; │
    mov    eax,0x0                      ; │
    call   1090 <__printf_chk@plt>      ; │
    sub    ebx,0x1                      ; │
    cmp    ebx,0xffffffff               ; │
    jne    11c8 <main+0x2d>             ; │
    mov    edi,0xa                      ; │
    call   1070 <putchar@plt>           ; ┘
    mov    edi,DWORD PTR [rsp]          ; ┐
    lea    r8,[rsp+0x4]                 ; ├ calc params
    mov    esi,0x8                      ; │
    mov    r9,r8                        ; │
    lea    ecx,[rsi-0x8]                ; │
    mov    edx,0x0                      ; │
    mov    eax,edi                      ; │
    sar    eax,cl                       ; │
    and    eax,0x1                      ; │
    add    edx,eax                      ; │
    add    ecx,0x1                      ; │
    cmp    ecx,esi                      ; │
    jne    120e <main+0x73>             ; │
    mov    BYTE PTR [r9],dl             ; │
    add    r8,0x1                       ; │
    add    esi,0x8                      ; │
    cmp    esi,0x28                     ; │
    jne    1203 <main+0x68>             ; │
    mov    ebx,0x4                      ; │
    lea    rbp,[rsp+0x4]                ; │
    jmp    125c <main+0xc1>             ; ┘
    lea    rsi,[rsp+0x7]                ; ┐
    lea    rdi,[rsp+0x6]                ; ├ bubble sort
    call   1189 <swap>                  ; │
    lea    rsi,[rsp+0x3]                ; │
    lea    rdi,[rsp+0x2]                ; │
    call   1189 <swap>                  ; │
    sub    bl,0x1                       ; │
    je     12bb <main+0x120>            ; │
    movzx  eax,BYTE PTR [rsp+0x4]       ; │
    cmp    BYTE PTR [rsp+0x5],al        ; │
    jl     127f <main+0xe4>             ; │
    movzx  eax,BYTE PTR [rsp+0x6]       ; │
    cmp    BYTE PTR [rsp+0x5],al        ; │
    jg     129b <main+0x100>            ; │
    movzx  eax,BYTE PTR [rsp+0x7]       ; │
    cmp    BYTE PTR [rsp+0x6],al        ; │
    jle    1257 <main+0xbc>             ; │
    jmp    1239 <main+0x9e>             ; │
    lea    rsi,[rsp+0x5]                ; │
    mov    rdi,rbp                      ; │
    call   1189 <swap>                  ; │
    mov    rdi,rsp                      ; │
    lea    rsi,[rsp+0x1]                ; │
    call   1189 <swap>                  ; │
    jmp    1267 <main+0xcc>             ; │
    lea    rsi,[rsp+0x6]                ; │
    lea    rdi,[rsp+0x5]                ; │
    call   1189 <swap>                  ; │
    lea    rsi,[rsp+0x2]                ; │
    lea    rdi,[rsp+0x1]                ; │
    call   1189 <swap>                  ; │
    jmp    1272 <main+0xd7>             ; ┘
    mov    ebx,0x1f                     ; ┐
    lea    rbp,[rip+0xd3d]              ; ├ show binary
    mov    edx,DWORD PTR [rsp]          ; │
    mov    ecx,ebx                      ; │
    sar    edx,cl                       ; │
    and    edx,0x1                      ; │
    mov    rsi,rbp                      ; │
    mov    edi,0x1                      ; │
    mov    eax,0x0                      ; │
    call   1090 <__printf_chk@plt>      ; │
    sub    ebx,0x1                      ; │
    cmp    ebx,0xffffffff               ; │
    jne    12c7 <main+0x12c>            ; │
    mov    edi,0xa                      ; │
    call   1070 <putchar@plt>           ; ┘
    mov    rax,QWORD PTR [rsp+0x8]      ; ┐
    xor    rax,QWORD PTR fs:0x28        ; ├ exit
    jne    1311 <main+0x176>            ; │
    mov    eax,0x0                      ; │
    add    rsp,0x18                     ; │
    pop    rbx                          ; │
    pop    rbp                          ; │
    ret                                 ; ┘
    call   1080 <__stack_chk_fail@plt>  ; ┬ check
    nop    WORD PTR cs:[rax+rax*1+0x0]  ; ┘

