#include <stdio.h>
#include <stdint.h>
 
typedef struct six_bit_groups {
    uint8_t middle_bits;
    uint8_t lower_bits;
} six_bit_groups_t;
 
/* 
For example:
00000000 00000101 01000000 01110110 

 
middle six bits are 101010
 lower six bits are 110110  
*/
 
// TODO
six_bit_groups_t get_bit_groups(uint32_t value) {


    // (*node).lower_bits is equivalent to
    // node->lower_bits

    six_bit_groups_t result;
    result.lower_bits = value & 0x3f;
    // 0011 1111
    //    3    f
    result.middle_bits = (value >> 13) & 0x3f;
    
    // six_bit_groups_t result = {
       // .lower_bits = ...,
        //.middle_bits = ...
    //};



    return result;
}
 
int main(void) {
    return 0;
}
