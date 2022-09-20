// non recursively calculate a factorial in C
// Abiram Nadarajah, Feb 2022

#include <stdio.h>

int main(void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);

    int fac = 1;


loop_init:
    int i = 1;
loop_cond:
    if (i > n) goto loop_end;

loop_body:
    fac *= i;       // fac = fac * i



    i++;
    goto loop_cond;

 loop_end:
    printf("n! = ");
    printf("%d", fac);
    putchar('\n');

    return 0;
}
