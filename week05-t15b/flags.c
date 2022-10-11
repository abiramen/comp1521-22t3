#include <stdio.h>
#include <stdint.h>

uint8_t printerControl = 0; // 0b 0000 0000

// Whether the printer is out of ink
#define NO_INK (0x1)       // 0b 0000 0001
// Whether to print/scan in colour
#define COLOUR (0x2)       // 0b 0000 0010
// Select print mode
#define SELECT_PRINT (0x4) // 0b 0000 0100
// Select scan mode
#define SELECT_SCAN (0x8)  // 0b 0000 1000
// Start print/scan
#define START (0x10)       // 0b 0001 0000
                        
void does_printer_have_ink() {
    // 0000 0100 &
    // 0000 0001

    // 0000 0000

    if (printerControl & NO_INK) {
        printf("printer does not have ink!\n");
    } else {
        printf("printer does ink\n");
    }
}

void ink_has_been_replaced(void) {
    // NO_INK is set
    // we want to unset the bit

    // curr=   0001 0101
    // ~NO_INK=1111 1110
    //
    // flip bits by using curr ^ NO_INK
    // unset the bit (regardless of its current value) by using
    // curr & ~NO_INK

    // goal is 0001 0100

    // printerControl = printerControl & ~NO_INK;
    printerControl &= ~NO_INK;
    
    //counter = counter + 2;
    //counter += 2;
}

void scan_in_colour() {
    // SELECT_SCAN  0000 1000
    // COLOUR       0000 0010
    // GOAL         0000 1010

    printerControl = SELECT_SCAN | COLOUR | NO_INK;
}
