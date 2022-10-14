#include <stdint.h>

uint8_t printerControl = 0; // 0b 0000 0000
                            // 0b 0000 0001

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


    // goal = 0000 1010

    // COLOUR 0000 0010 |
    // SCAN   0000 1000
    //        0000 1010
    // START  0001 1010
    //        


    // 0000 0100, or
    


    // 0000 1000
    // 0000 1100




    // original = 0001 0001 &
    // ~mask    = 1111 1110
    //          = 0001 0000


    //  mask    = 0000 0001
    
    

    // we can flip the no_ink bit by using XOR
    // printerControl = printerControl ^ NO_INK;

    // tell the printer there IS ink




void does_printer_have_ink(void) {

    // 0100 1000 
    // 0100 0000
    // 0000 1000 XOR

    // 0000 0000 AND, bit not set
    // 0100 0000 AND, bit is set

    // 0100 1000 OR
    // 


    if (printerControl & NO_INK) {
        printf("printer is out of ink!\n");
    } else {
        printf("printer has ink!");
    }
}

void replace_cartridge(void) {
    // 0001 0000
    // 0001 0001

    // flips the NO_INK bit
    // printerControl ^= NO_INK; // printerControl = printerControl ^ NO_INK;

    
    printerControl &= ~NO_INK; // printerControl = printerControl & ~NO_INK;

}

void start_scanning_in_colour(void) {
    printerControl = START | SELECT_SCAN | COLOUR;
}

void toggle_scan_and_print(void) {
    printerControl ^= (SELECT_PRINT | SELECT_SCAN); // printerControl = printerControl ^ (SELECT_PRINT | SELECT_SCAN);
}
