#include <stdio.h>

int main(void) {
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);

    printf("decimal: %d\n", n);
    printf("hexadecimal: %x %X\n", n, n);
    printf("octal: %o\n", n);

    return 0;
}
