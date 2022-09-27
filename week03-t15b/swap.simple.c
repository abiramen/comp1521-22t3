#include <stdio.h>

#define N_ELEMENTS          10
#define N_ELEMENTS_DIV_2    (N_ELEMENTS / 2)
#define N_ELEMENTS_M_1      (N_ELEMENTS - 1)


int numbers[N_ELEMENTS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int main(void) {
loop_i_to_N_ELEMENTS_DIV_2_init:
    int i = 0;

loop_i_to_N_ELEMENTS_DIV_2_cond:
    if (i >= N_ELEMENTS_DIV_2) goto loop_i_to_N_ELEMENTS_DIV_2_end;
loop_i_to_N_ELEMENTS_DIV_2_body:
    int x = numbers[i];                     // numbers + i * 4
    int y = numbers[N_ELEMENTS_M_1 - i];    // numbers + (N_ELEMENTS_M_1 - i) * 4
    numbers[i] = y;
    numbers[N_ELEMENTS_M_1 - i] = x;
    i++;
    goto loop_i_to_N_ELEMENTS_DIV_2_cond;

loop_i_to_N_ELEMENTS_DIV_2_end:
    return 0;
}
