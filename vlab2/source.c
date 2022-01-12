#include <Windows.h>
#include <stdlib.h>
#include <string.h>

int main() { //*/
    __asm {
        xor ecx, ecx
        push ecx

        mov eax, 0x01010201
        sub eax, 0x01010101
        sub esp, eax
        push eax

        mov eax, 0x01140135     // dst + 4
        sub eax, 0x01010201
        mov [eax], cl

        push 1
        mov eax, 0x01140131     // dst
        sub eax, 0x01010201
        push eax
        mov eax, 0x7c86114d     // WinExec
        call eax

        pop eax
        add esp, eax
        mov eax, 0x7c81caa2     // ExitProcess
        call eax
        nop
    } //*/
    printf("WinExec: %x\n", GetProcAddress(GetModuleHandle(L"kernel32.dll"), "WinExec"));
    printf("ExitPrxocess: %x\n", GetProcAddress(GetModuleHandle(L"kernel32.dll"), "ExitProcess"));
    system("pause");
    return 0;
}
