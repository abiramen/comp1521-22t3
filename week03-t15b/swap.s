N_ELEMENTS = 10
N_ELEMENTS_DIV_2 = N_ELEMENTS / 2
N_ELEMENTS_M_1 = N_ELEMENTS - 1


main:
        # Registers:
        #       - $t0: int i
        #       - $t1: int x
        #       - $t2: int y
        #       - $t3: 4 * i
        #       - $t4: intermediate value
        #       - $t5: 4 * (N_ELEMENTS - 1 - i)

loop_i_to_N_ELEMENTS_DIV_2_init:
        li      $t0, 0                                                  # int i = 0;

loop_i_to_N_ELEMENTS_DIV_2_cond:
        bge     $t0, N_ELEMENTS_DIV_2, loop_i_to_N_ELEMENTS_DIV_2_end   # if (i >= N_ELEMENTS_DIV_2) goto loop_i_to_N_ELEMENTS_DIV_2_end;
loop_i_to_N_ELEMENTS_DIV_2_body:
        mul     $t3, $t0, 4                                             # 
        lw      $t1, numbers($t3)                                       # x = numbers[i];

        li      $t4, N_ELEMENTS_M_1
        sub     $t5, $t4, $t0                                           # N_ELEMENTS_M_1 - i;
        mul     $t5, $t5, 4                                             # (N_ELEMENTS_M_1 - i) * 4;
        lw      $t2, numbers($t5)                                       # y = numbers[N_ELEMENTS - 1 - i];

        sw      $t2, numbers($t3)                                       # numbers[i] = y;
        sw      $t1, numbers($t5)                                       # numbers[N_ELEMENTS_M_1 - i] = x;

        addi    $t0, $t0, 1                                             # i++;

        j       loop_i_to_N_ELEMENTS_DIV_2_cond

loop_i_to_N_ELEMENTS_DIV_2_end:

        li      $v0, 0                                                  #
        jr      $ra                                                     # return 0;




        .data
numbers:
        .word   0, 1, 2, 3, 4, 5, 6, 7, 8, 9
