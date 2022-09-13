#include <stdio.h>

int main(void) {
    // print every number from 1 to 10 inclusive with a while loop.
    
    int i = 1; // initialisation step
    while (i <= 10) { // condition

        // body
        printf("%d\n", i);


        // increment (step)
        i++;
    }


    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }

   return 0;
}
