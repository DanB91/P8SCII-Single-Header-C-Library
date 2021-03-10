//Original code written by Daniel Bokser and released into the public domain

/*
 * IMPORTANT!!!
 * Define P8SCII_IMPL before the include when you want to include the implementation.
 * Only do this on exactly one compilation unit in your program.
 */
#define P8SCII_IMPL  
#include "p8scii.h"

#include <string.h>
#include <stdio.h>

#define LINE_SPACE (GLYPH_HEIGHT + 1)

static BitmapPixel bitmap[128*128];
int main(void) {
    memset(bitmap, ' ', sizeof(bitmap));
    p8scii_print(TO_P8SCII(" !\"#$%&'()*+,-./0123456789:;<=>?"), 0, 0*LINE_SPACE, '#', bitmap, 128, 128);
    p8scii_print(TO_P8SCII("@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"), 0, 1*LINE_SPACE, '#', bitmap, 128, 128);
    p8scii_print(TO_P8SCII("`abcdefghijklmnopqrstuvwxyz{|}~\x7F"), 0, 2*LINE_SPACE, '#', bitmap, 128, 128);
    p8scii_print(TO_P8SCII("\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8A\x8B\x8C\x8D\x8E\x8F"), 0, 3*LINE_SPACE, '#', bitmap, 128, 128);
    p8scii_print(TO_P8SCII("\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99"), 0, 4*LINE_SPACE, '#', bitmap, 128, 128);

    BitmapPixel line[129]; //include null byte
    for (int i = 0; i < 128*128; i+=128) {
        memcpy(line, bitmap + i, 128); 
        line[128] = 0;
        printf("%s\n", line);
    }
    return 0;
}
