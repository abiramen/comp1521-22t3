#include <stdio.h>
#define N_ELEMENTS 5

int array[N_ELEMENTS] = {3, 1, 4, 1, 5};
int main(void) {
    // char array[N_ELEMENTS] = {'h', 'e', 'l', 'l', 'o'};


loop_i_to_N_ELEMENTS_init:
    int i = 0;
loop_i_to_N_ELEMENTS_cond:
    if (i >= N_ELEMENTS) goto loop_i_to_N_ELEMENTS_end;
loop_i_to_N_ELEMENTS_body:
    printf("%d", array[i]);     // array + 4 * i
    putchar('\n');
    i++;

    goto loop_i_to_N_ELEMENTS_cond;

loop_i_to_N_ELEMENTS_end:
    return 0;
}


// &array[i] = &array[0] + sizeof(element) * i
//           = array + sizeof(element) * i

// &array[i] = array + i
// &i[array] = i + array








// What if we had
// int array[N_ELEMENTS] = {3, 1, 4, 1, 5};

