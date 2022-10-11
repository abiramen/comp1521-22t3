#include <stdio.h>
#define N_ROWS 6
#define N_COLS 12


char flag[N_ROWS][N_COLS] = {
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'}
};

int main(void) {

main__for_row_init:
    int row = 0;
main__for_row_cond:
    if (row >= N_ROWS) goto main__for_row_end;
main__for_row_body:

main__for_col_init:
    int col = 0;
main__for_col_cond:
    if (col >= N_COLS) goto main__for_col_end;
main__for_col_body:
    printf("%c", flag[row][col]); 
main__for_col_step:
    col++;
    goto main__for_col_cond;

main__for_col_end:
    putchar('\n');


main__for_row_step:
    row++;
    goto main__for_row_cond;
main__for_row_end:
    return 0;

}
