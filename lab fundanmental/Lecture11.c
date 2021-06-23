#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct kdl {
    int a, b;
};
void display_bit(unsigned x) {
    unsigned mask = 1 << 31;
    for (int i = 1; i <= 32; i++) {
        printf("%c", ((x & mask)) ? '1' : '0');
        x <<= 1;
        if (i % 8 == 0)
            printf(" ");
    }
}
void Bin_To_Dec(int *arr) {
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d", size);
}
void cmp(int *x, int *y) {
}

int main() {
    // display_bit(65535);
    // int *a = (int *)malloc(6 * sizeof(int));
    // for (int i = 1; i <= 5; i++)
    //     scanf("%d", &a[i]);

    // int *pos = &a[5];
    // a = (int *)realloc(a, (4) * sizeof(int));
    // printf("%d", *pos);
    struct kdl *a;
    a->a = 1;
}