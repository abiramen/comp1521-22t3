
main:

        # Locals:
        #       - $t0: int row
        #       - $t1: int col
        #       - $t2: temporary result

main__for_row_init:
    li  $t0, 0                                                  # int row = 0;

main__for_row_cond:
    bge $t0, N_ROWS, main__for_row_end                          # if (row >= N_ROWS) goto main__for_row_end;

main__for_row_body:

main__for_col_init:
    li  $t1, 0                                                  # int col = 0;

main__for_col_cond:
    bgeif (col >= N_COLS) goto main__for_col_end;

main__for_col_body:
        mul     $t2, $t0, N_COLS                                # (row * N_COLS
        add     $t2, $t2, $t1                                   # + col)
        mul     $t2, $t2, 1                                     # * sizeof(char)
        lb      $a0, flag($t2)                                  # flag[row][col]

        li      $v0, 11                                         # syscall 11: print_Char
        syscall


    printf("%c", flag[row][col]);               // &flag[row][col] = &flag[0][0] + (row * N_COLS + col) * sizeof(char)

main__for_col_step:
    col++;
    goto main__for_col_cond;


main__for_col_end:
    printf("\n");

main__for_row_step:
    row++;
    goto main__for_row_cond;

main__for_row_end:

    return 0;

        li      $v0, 0
        jr      $ra



        .data
flag:

        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
