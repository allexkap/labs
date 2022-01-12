#include <stdlib.h>
#include <stdio.h>

int fun_a();
int __cdecl fun_c(int a, int b, int c) {
    return a * c + b;
}

int main() {
    printf("%d\n", fun_a());
    system("pause");
    return 0;
}
