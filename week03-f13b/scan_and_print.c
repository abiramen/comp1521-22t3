#include <stdio.h>
#define N_ELEMENTS 10

int main(void) {
    int i;
    int numbers[N_ELEMENTS] = {0};

loop_scan_init:
    i = 0;
loop_scan_cond:
    if (i >= N_ELEMENTS) goto loop_scan_end;

loop_scan_body: 
    scanf("%d", &numbers[i]);       // numbers + 4 * i
    i++;
    goto loop_scan_cond;
   
loop_scan_end:

loop_print_init:
    i = 0;
loop_print_cond:
    if (i >= N_ELEMENTS) goto loop_print_end;
loop_print_body:
    printf("%d ", numbers[i]);
    i++;
    goto loop_print_cond;
loop_print_end:
    return 0;
}
