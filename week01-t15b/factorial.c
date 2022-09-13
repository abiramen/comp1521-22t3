#include <stdio.h>

int factorial(int n);

// n! = n x (n - 1)!
// 5! = 5 x 4 x 3 x 2 x 1 = 5 x 4!
// 4! =     4 x 3 x 2 x 1 = 4 x 3!
// 3! =         3 x 2 x 1

// 0! = 1


int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, factorial(n));
    return 0;
}

int factorial(int n) {
    
    if (n == 0) {
        return 1;
    } 

    return n * factorial(n - 1);

}
