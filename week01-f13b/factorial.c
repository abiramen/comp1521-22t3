#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main(int argc, char *argv[]) {
    // argc == argument count
    // argv == argument values
    // is an array of strings

    for (int i = 1; i < argc; i++) {
        printf("argument %d is %s\n", i, argv[i]);
        printf("%s! = %d\n", argv[i], factorial(atoi(argv[i])));
    }

    return 0;
}

// n! = n x (n - 1)!

// 5! = 5 x 4 x 3 x 2 x 1 = 5 x 4!
// 4! =     4 x 3 x 2 x 1 = 4 x 3!
// 3! =         3 x 2 x 1 = 3 x 2!
// 2! =             2 x 1 = 2 x 1!
// 1! =                 1 = 1 x 0!
// 0! = 1



int factorial(int n) {
    if (n <= 0) {
        return 1;
    }
    return n * factorial(n - 1);
}
