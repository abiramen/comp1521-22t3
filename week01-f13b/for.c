#include <stdio.h>

int main(void) {
    // print every number from 1 to 10 inclusive with a while loop.
    
    // initialisation step
    int i = 1; 

    while (i <= 10) { // condition
        // body
        printf("%d\n", i);

        // increment
        i++;
    }


    for (int i = 1; i <= 10; i++) {
        // body
        printf("%d\n", i);
    }

   return 0;
}
