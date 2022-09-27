#include <stdio.h>
#define N_ELEMENTS 5

int main(void) {
    int array[N_ELEMENTS] = {3, 1, 4, 1, 5};


    for (int i = 0; i < N_ELEMENTS; i++) {
        printf("%d", array[i]);
        putchar('\n');
        // printf("%d\t", i);
        // printf("%d", array[i]);
        // // putchar(*(array + i));
        // printf("\t%p", &array[i]);
        // // printf("\t%p", array + i);
        // putchar('\n');
        
    }

    // &array[i] = &array[0] + sizeof(elenent) * i

    // array[i] = i[array]




    return 0;
}


// What if we had
// int array[N_ELEMENTS] = {3, 1, 4, 1, 5};

