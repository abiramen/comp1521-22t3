#include <stdio.h>

// if and goto

int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);


    if (x <= 46340) goto x_lte_46340;

    printf("square too big for 32 bits\n");

    goto epilogue;

x_lte_46340:
    y = x * x;
    printf("%d\n", y);

epilogue:
    return 0;
}
