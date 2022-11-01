#include <stdio.h>
#include <stdint.h>
 
typedef struct six_bit_groups {
    uint8_t middle_bits;
    uint8_t lower_bits;
} six_bit_groups_t;
 
/* 
For example:
00000000 00000101 01000000 01110110 
              111 11100000 00000000
                7    e   0    0   0

 
middle six bits are 101010
 lower six bits are 110110  
*/
 
// TODO
six_bit_groups_t get_bit_groups(uint32_t value) {
    six_bit_groups_t result;

    result.lower_bits = value & 0x3f;
    result.middle_bits = (value & 0x7e000) >> 13;

    return result;
}
 
int main(void) {
    return 0;
}
