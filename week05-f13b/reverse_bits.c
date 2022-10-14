#include <assert.h>
#include <stdio.h>

// most machines have 32 bit integers
// C standard states this can be anything >= 16 bits
typedef unsigned int Word;

int N_BITS = sizeof(Word) * 8;

Word reverse_bits(Word value) {
    int result = 0;

    for (int i = 0; i < N_BITS; i++) {
        Word r_mask = 1u << (N_BITS - i - 1);   

        if (value & r_mask) {
            Word w_mask = 1u << i;
            result |= w_mask;
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
