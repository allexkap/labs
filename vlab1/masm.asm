.386
.model flat, c

extern fun_c : proc

.data
    x dword 1
    y dword 2
    z dword 3

.code
    fun_a proc
        push z
        push y
        push x
        call fun_c
        add esp, 12
        ret
    fun_a endp
end
