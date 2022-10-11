#include <assert.h>
#include <stdio.h>

// most machines have 32 bit integers
// C standard states this can be anything >= 16 bits
typedef unsigned int Word;

Word reverse_bits(Word value) {
    
    // 0110 0011

    // 1100 0110

    size_t n_bits = sizeof(Word) * 8;
    Word result = 0; // 0000 0000

    for (int i = 0; i < n_bits; i++) {
        // i = 0
        // value  = 0110 0011 &
        // r_mask = 1000 0000
        // ANDing gives us a 0 value
        // result = 0000 0000
        // w_mask = 0000 0001

        // i = 1
        // value  = 0110 0011 &
        // r_mask = 0100 0000
        // ANDing gives us a non-0 value
        // result = 0000 0000
        // w_mask = 0000 0010
        // goal   = 0000 0010

        // i = 2
        // value  = 0110 0011 &
        // r_mask = 0010 0000
        // ANDing gives us a non-0 value
        // result = 0000 0010
        // w_mask = 0000 0100
        // goal   = 0000 0110
       

        // 0000 0001
        // 1000 0000
        Word read_mask = 1 << (n_bits - i - 1);
        Word write_mask = 1 << i;

        if (value & read_mask) {
            result |= write_mask;
        }

    }

    return result;


}

int main(void) {
    assert(reverse_bits(0xFFFFFFFF) == 0xFFFFFFFF);
    assert(reverse_bits(0x00000000) == 0x00000000);
    assert(reverse_bits(0x1) == 0x80000000);
    assert(reverse_bits(0x2) == 0x40000000);
    assert(reverse_bits(0x01234567) == 0xE6A2C480);
    printf("All tests passed!\n");
    return 0;
}
