#include <stdio.h>

// xor swap
void swap(char *a, char *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main() {
    // input
    int x = 0xDEADBEEF;

    // vars
    char size = sizeof(x);
    char amount[size];

    // show binary
    for (char i = size*8-1; i >= 0; i--) printf("%d", (x&1<<i)!=0); printf("\n");

    // calc params
    for (char i = 0; i < size; i++) {
        amount[i] = 0;
        for (char j = 0; j < 8; j++) {
            amount[i] += (x&(1<<8*i+j))!=0;
        }
    }

    // bubble sort
    for (char k = 0; k < size; k++) {
        for (char i = 0; i < size - 1; i++) {
            if (amount[i] > amount[i+1]) {
                swap(&amount[i], &amount[i+1]);
                swap((char*)(&x)+i, (char*)(&x)+i+1);
            }
        }
    }

    // show binary
    for (char i = size*8-1; i >= 0; i--) printf("%d", (x&1<<i)!=0); printf("\n");

    // exit
    return 0;
}
