#include <stdio.h>

void swap(char *a, char *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main() {
    int x = 0xDEADBEEF;
    printf("%X\n", x);

    char size = sizeof(x);
    char amount[size];

    for (char i = 0; i < size; i++) {
        for (char j = 0; j < 8; j++) {
            amount[i] += (x&(1<<8*i+j))!=0;
        }
    }

    for (char i = 0; i < size; i++) printf("%d ", amount[i]); printf("\n");

    for (char k = 0; k < size; k++) {
        for (char i = 0; i < size - 1; i++) {
            if (amount[i] > amount[i+1]) {
                swap(&amount[i], &amount[i+1]);
                swap((char*)(&x)+i, (char*)(&x)+i+1);
            }
        }
    }

    for (char i = 0; i < size; i++) printf("%d ", amount[i]); printf("\n");

    printf("%X\n", x);
    return 0;
}
