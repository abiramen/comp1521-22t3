#include <stdio.h>

// for loops are turned into while loops
// while loops into if-goto
// if-else statements into if-goto

int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);




    if (x > 46340) {
        printf("square too big for 32 bits\n");
    } else {
        y = x * x;
        printf("%d\n", y);
    }

    return 0;
}
