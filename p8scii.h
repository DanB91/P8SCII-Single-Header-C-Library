//Original code written by Daniel Bokser and released into the public domain
//Font designed by Joseph "zep" White
#ifndef P8SCII_H
#define P8SCII_H
#include <stdint.h>

#define TO_P8SCII(string_literal)((const P8SCIIChar*)string_literal)
#define GLYPH_HEIGHT 5
#define SMALL_GLYPH_WIDTH 3
#define LARGE_GLYPH_WIDTH 7
typedef uint8_t P8SCIIChar;

//Customize: Pixel space between glyphs. Default is 1 (same as PICO-8).
#define GLYPH_SPACE 1 
//Customize: Type of bitmap pixel. Default is uint8_t.
typedef uint8_t BitmapPixel;

//Customize: You may want to change up this function to fit your own needs.
//           For example: if you know the bitmap width and height at compile time, 
//           you may just want to make those constants instead of parameters.
void p8scii_print(const P8SCIIChar *s, int x, int y, BitmapPixel fill_value,
        BitmapPixel *out_bitmap, int bitmap_width, int bitmap_height);

#ifdef P8SCII_IMPL
#define ARRAY_LEN(a) (sizeof(a)/sizeof(*a))
static const uint16_t SMALL_GLYPHS[] = {
    /*
     * Small glyphs are 3x5 pixels. Each line is represented by 3 bits (hence why it is written in octal).
     * Each glyph is 16 bits (2 bytes) with the most significant bit unused.
     * The least significant (right-most) 3 bits represents the top most line.
     */

	/*
	 * 000 0
	 * 000 0
	 * 000 0
	 * 000 0
	 * 000 0
	 */
	000000, //Space
	/*
	 * 010 2
	 * 010 2
	 * 010 2
	 * 000 0
	 * 010 2
	 */
	020222, //!
	/*
	 * 101 5
	 * 101 5
	 * 000 0
	 * 000 0
	 * 000 0
	 */
	000055, //"
	/*
	 * 101 5
	 * 111 7
	 * 101 5
	 * 111 7
	 * 101 5
	 */
   057575, //#
   /*
	* 111 7
	* 110 6
	* 011 3
	* 111 7
	* 010 2
	*/
   027367, //$
   /*
	* 101 5
	* 001 1
	* 010 2
	* 100 4
	* 101 5
	*/
   054215, //%
   /*
	* 110 6
	* 110 6
	* 110 6
	* 101 5
	* 111 7
	*/
   075666, //&
   /*
	* 010 2
	* 100 4
	* 000 0 
	* 000 0
	* 000 0
	*/
   000042, //'
   /*
	* 010 2
	* 100 4
	* 100 4
	* 100 4
	* 010 2
	*/
   024442, //(
   /*
	* 010 2
	* 001 1
	* 001 1
	* 001 1
	* 010 2
	*/
   021112, //)
   /*
	* 101 5
	* 010 2
	* 111 7
	* 010 2
	* 101 5
	*/
   052725, //*
   /*
	* 000 0
	* 010 2
	* 111 7
	* 010 2
	* 000 0
	*/
   002720, //+
   /*
	* 000 0
	* 000 0
	* 000 0
	* 010 2
	* 100 4
	*/
   042000, //,
   /*
	* 000 0
	* 000 0
	* 111 7
	* 000 0
	* 000 0
	*/
   000700, //-
   /*
	* 000 0
	* 000 0
	* 000 0
	* 000 0
	* 010 2
	*/
   020000, //.
   /*
	* 001 1
	* 010 2
	* 010 2
	* 010 2
	* 100 4
	*/
   042221, // /
   /*
	* 111 7
	* 101 5
	* 101 5
	* 101 5
	* 111 7
	*/
   075557, //0
   /*
	* 110 6
	* 010 2
	* 010 2
	* 010 2
	* 111 7
	*/
   072226, //1
   /*
	* 111 7
	* 001 1
	* 111 7
	* 100 4
	* 111 7
	*/
   074717, //2
   /*
	* 111 7
	* 001 1
	* 011 3
	* 001 1
	* 111 7
	*/
   071317, //3
   /*
	* 101 5
	* 101 5
	* 111 7
	* 001 1
	* 001 1
	*/
   011755, //4
   /*
	* 111 7
	* 100 4
	* 111 7
	* 001 1
	* 111 7
	*/
   071747, //5
   /*
	* 100 4
	* 100 4
	* 111 7
	* 101 5
	* 111 7
	*/
   075744, //6
   /*
	* 111 7
	* 001 1
	* 001 1
	* 001 1
	* 001 1
	*/
   011117, //7
   /*
	* 111 7
	* 101 5
	* 111 7
	* 101 5
	* 111 7
	*/
   075757, //8
   /*
	* 111 7
	* 101 5
	* 111 7
	* 001 1
	* 001 1
	*/
   011757, //9
   /*
	* 000 0
	* 010 2
	* 000 0
	* 010 2
	* 000 0
	*/
   002020, //:
   /*
	* 000 0
	* 010 2
	* 000 0
	* 010 2
	* 100 4
	*/
   042020, //;
   /*
	* 001 1
	* 010 2
	* 100 4
	* 010 2
	* 001 1
	*/
   012421, //<
   /*
	* 000 0
	* 111 7
	* 000 0
	* 111 7
	* 000 0
	*/
   007070, //=
   /*
	* 100 4
	* 010 2
	* 001 1
	* 010 2
	* 100 4
	*/
   042124, //>
   /*
	* 111 7
	* 001 1
	* 010 2
	* 000 0
	* 010 2
	*/
   020217, //?
   /*
	* 010 2
	* 101 5
	* 101 5
	* 100 4
	* 011 3
	*/
   034552, //@
   /*
	* 000 0
	* 111 7
	* 101 5
	* 111 7
	* 101 5
	*/
   057570, //a
   /*
	* 000 0
	* 110 7
	* 111 7
	* 101 5
	* 111 7
	*/
   075770, //b
   /*
	* 000 0
	* 111 7
	* 100 4
	* 100 4
	* 111 7
	*/
   074470, //c
   /*
	* 000 0
	* 110 6
	* 101 5
	* 101 5
	* 110 6
	*/
   065560, //d
   /*
	* 000 0
	* 111 7
	* 110 6
	* 100 4
	* 111 7
	*/
   074670, //e
   /*
	* 000 0
	* 111 7
	* 110 6
	* 100 4
	* 100 4
	*/
   044670, //f
   /*
	* 000 0
	* 111 7
	* 100 4
	* 101 5
	* 111 7
	*/
   075470, //g
   /*
	* 000 0
	* 101 5
	* 101 5
	* 111 7
	* 101 5
	*/
   057550, //h
   /*
	* 000 0
	* 111 7
	* 010 2
	* 010 2
	* 111 7
	*/
   072270, //i
   /*
	* 000 0
	* 111 7
	* 010 2
	* 010 2
	* 110 6
	*/
   062270, //j
   /*
	* 000 0
	* 101 5
	* 110 6
	* 101 5
	* 101 5
	*/
   055650, //k
   /*
	* 000 0
	* 100 4
	* 100 4
	* 100 4
	* 111 7
	*/
   074440, //l
   /*
	* 000 0
	* 111 7
	* 111 7
	* 101 5
	* 101 5
	*/
   055770, //m
   /*
	* 000 0
	* 110 6
	* 101 5
	* 101 5
	* 101 5
	*/
   055560, //n
   /*
	* 000 0
	* 011 3
	* 101 5
	* 101 5
	* 110 6
	*/
   065530, //o
   /*
	* 000 0
	* 111 7
	* 101 5
	* 111 7
	* 100 4
	*/
   047570, //p
   /*
	* 000 0
	* 010 2
	* 101 5
	* 110 6
	* 011 3
	*/
   036520, //q
   /*
	* 000 0
	* 111 7
	* 101 5
	* 110 6
	* 101 5
	*/
   056570, //r
   /*
	* 000 0
	* 011 3
	* 100 4
	* 001 1
	* 110 6
	*/
   061430, //s
   /*
	* 000 0
	* 111 7
	* 010 2
	* 011 2
	* 010 2
	*/
   022270, //t
   /*
	* 000 0
	* 101 5
	* 101 5
	* 101 5
	* 011 3
	*/
   035550, //u
   /*
	* 000 0
	* 101 5
	* 101 5
	* 111 7
	* 010 2
	*/
   027550, //v
   /*
	* 000 0
	* 101 5
	* 101 5
	* 111 7
	* 111 7
	*/
   077550, //w
   /*
	* 000 0
	* 101 5
	* 010 2
	* 101 5
	* 101 5
	*/
   055250, //x
   /*
	* 000 0
	* 101 5
	* 111 7
	* 001 1
	* 111 7
	*/
   071750, //y
   /*
	* 000 0
	* 111 7
	* 001 1
	* 100 4
	* 111 7
	*/
   074170, //z
   /*
	* 110 6
	* 100 4
	* 100 4
	* 100 4
	* 110 6
	*/
   064446, //[
   /*
	* 100 4
	* 010 2
	* 010 2
	* 010 2
	* 001 1
	*/
   012224, //"\" 
   /*
	* 011 3
	* 001 1
	* 001 1
	* 001 1
	* 011 3
	*/
   031113, //]
   /*
	* 010 2
	* 101 5
	* 000 0
	* 000 0
	* 000 0
	*/
   000052, //^
   /*
	* 000 0
	* 000 0
	* 000 0
	* 000 0
	* 111 7
	*/
   070000, //_
   /*
	* 010 2
	* 001 1
	* 000 0
	* 000 0
	* 000 0
	*/
   000012, //`
   /*
	* 111 7
	* 101 5
	* 111 7
	* 101 5
	* 101 5
	*/
   055757, //A
   /*
	* 111 7
	* 101 5
	* 110 6
	* 101 5
	* 111 7
	*/
   075657, //B
   /*
	* 011 3
	* 100 4
	* 100 4
	* 100 4
	* 011 3
	*/
   034443, //C
   /*
	* 110 6
	* 101 5
	* 101 5
	* 101 5
	* 111 7
	*/
   075556, //D
   /*
	* 111 7
	* 100 4
	* 111 7
	* 100 4
	* 111 7
	*/
   074747, //E
   /*
	* 111 7
	* 100 4
	* 111 7
	* 100 4
	* 100 4
	*/
   044747, //F
   /*
	* 011 3
	* 100 4
	* 100 4
	* 101 5
	* 111 7
	*/
   075443, //G
   /*
	* 101 5
	* 101 5
	* 111 7
	* 101 5
	* 101 5
	*/
   055755, //H
   /*
	* 111 7
	* 010 2
	* 010 2
	* 010 2
	* 111 7
	*/
   072227, //I
   /*
	* 111 7
	* 010 2
	* 010 2
	* 010 2
	* 110 6
	*/
   062227, //J
   /*
	* 101 5
	* 101 5
	* 110 6
	* 101 5
	* 101 5
	*/
   055655, //K
   /*
	* 100 4
	* 100 4
	* 100 4
	* 100 4
	* 111 7
	*/
   074444, //L
   /*
	* 111 7
	* 111 7
	* 101 5
	* 101 5
	* 101 5
	*/
   055577, //M
   /*
	* 110 6
	* 101 5
	* 101 5
	* 101 5
	* 101 5
	*/
   055556, //N
   /*
	* 011 3
	* 101 5
	* 101 5
	* 101 5
	* 110 6
	*/
   065553, //O
   /*
	* 111 7
	* 101 5
	* 111 7
	* 100 4
	* 100 4
	*/
   044757, //P
   /*
	* 010 2
	* 101 5
	* 101 5
	* 110 6
	* 011 3
	*/
   036552, //Q
   /*
	* 111 7
	* 101 5
	* 110 6
	* 101 5
	* 101 5
	*/
   055657, //R
   /*
	* 011 3
	* 100 4
	* 111 7
	* 001 1
	* 110 6
	*/
   061743, //S
   /*
	* 111 7
	* 010 2
	* 010 2
	* 011 2
	* 010 2
	*/
   022227, //T
   /*
	* 101 5
	* 101 5
	* 101 5
	* 101 5
	* 011 3
	*/
   035555, //U
   /*
	* 101 5
	* 101 5
	* 101 5
	* 111 7
	* 010 2
	*/
   027555, //V
   /*
	* 101 5
	* 101 5
	* 101 5
	* 111 7
	* 111 7
	*/
   077555, //W
   /*
	* 101 5
	* 101 5
	* 010 2
	* 101 5
	* 101 5
	*/
   055255, //X
   /*
	* 101 5
	* 101 5
	* 111 7
	* 001 1
	* 111 7
	*/
   071755, //Y
   /*
	* 111 7
	* 001 1
	* 010 2
	* 100 4
	* 111 7
	*/
   074217, //Z
   /*
	* 011 3
	* 010 2
	* 110 6
	* 010 2
	* 011 3
	*/
   032623, //{
   /*
	* 010 2
	* 010 2
	* 010 2
	* 010 2
	* 010 2
	*/
   022222, //|
   /*
	* 110 6
	* 010 2
	* 011 3
	* 010 2
	* 110 6
	*/
   062326, //}
   /*
	* 000 0
	* 001 1
	* 111 7
	* 100 4
	* 000 0
	*/
   004710, //~
   /*
	* 000 0
	* 010 2
	* 101 5
	* 101 5
	* 111 7
	*/
   075520, //'u' with an accent?
};	

static const uint8_t LARGE_GLYPHS[] = {
    /*
     * Large glyphs are 7x5 pixels. Each line of a glyph is 1 byte, with the 
     * most significant bit unused. With 5 lines, each glyph is 5 bytes.
     * The least significant (left-most) byte of each 5-byte group represents the top most line.
     */
	/*
	 * 0111|1111 0x7F
	 * 0111|1111 0x7F
	 * 0111|1111 0x7F
	 * 0111|1111 0x7F
	 * 0111|1111 0x7F
	 */
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F, //rectangle
	/*
	 * 0101|0101 0x55
	 * 0010|1010 0x2A
	 * 0101|0101 0x55
	 * 0010|1010 0x2A
	 * 0101|0101 0x55
	 */
	0x55, 0x2A, 0x55, 0x2A, 0x55, //checkerboard
	/*
	 * 0100|0001 0x71
	 * 0111|1111 0x7F
	 * 0101|1101 0x5D
	 * 0101|1101 0x5D
	 * 0011|1110 0x3E
	 */
	0x41, 0x7F, 0x5D, 0x5D, 0x3E, //jelpi
	/*
	 * 0011|1110 0x3E
	 * 0110|0011 0x63
	 * 0110|0011 0x63
	 * 0111|0111 0x77
	 * 0011|1110 0x3E
	 */
	0x3E, 0x63, 0x63, 0x77, 0x3E, //down button
	/*
	 * 0100|0100 0x44
	 * 0001|0001 0x11
	 * 0100|0100 0x44
	 * 0001|0001 0x11
	 * 0100|0100 0x44
	 */
	0x44, 0x11, 0x44, 0x11, 0x44, //particles
	/*
	 * 0001|0000 0x10
	 * 0001|1110 0x1E
	 * 0001|1100 0x1C
	 * 0011|1100 0x3C
	 * 0000|0100 0x04
	 */
	0x10, 0x1E, 0x1C, 0x3C, 0x04, //shuriken
	/*
	 * 0001|1100 0x1C
	 * 0011|1010 0x3A
	 * 0011|1110 0x3E
	 * 0011|1110 0x3E
	 * 0001|1100 0x1C
	 */
	0x1C, 0x3A, 0x3E, 0x3E, 0x1C, //ball
	/*
	 * 0011|0110 0x36
	 * 0011|1110 0x3E
	 * 0011|1110 0x3E
	 * 0001|1100 0x1C
	 * 0000|1000 0x08
	 */
	0x36, 0x3E, 0x3E, 0x1C, 0x08, //heart
	/*
	 * 0001|1100 0x1C
	 * 0011|0110 0x36
	 * 0111|0111 0x77
	 * 0011|0110 0x36
	 * 0001|1100 0x1C
	 */
	0x1C, 0x36, 0x77, 0x36, 0x1C, //eye
	/*
	 * 0001|1100 0x1C
	 * 0001|1100 0x1C
	 * 0011|1110 0x3E
	 * 0001|1100 0x1C
	 * 0001|0100 0x14
	 */
	0x1C, 0x1C, 0x3E, 0x1C, 0x14, //player
	/*
	 * 0001|1100 0x1C
	 * 0011|1110 0x3E
	 * 0111|1111 0x7F
	 * 0010|1010 0x2A
	 * 0010|1110 0x2E
	 */
	0x1C, 0x3E, 0x7F, 0x2A, 0x2E, //house
	/*
	 * 0011|1110 0x3E
	 * 0111|0011 0x73
	 * 0110|0011 0x63
	 * 0111|0011 0x73
	 * 0011|1110 0x3E
	 */
	0x3E, 0x73, 0x63, 0x73, 0x3E, //left button
	/*
	 * 0111|1111 0x7F
	 * 0101|1101 0x5D
	 * 0111|1111 0x7F
	 * 0100|0001 0x41
	 * 0111|1111 0x7F
	 */
	0x7F, 0x5D, 0x7F, 0x41, 0x7F, //face
	/*
	 * 0000|1110 0x0E
	 * 0000|1000 0x08
	 * 0000|1000 0x08
	 * 0011|1000 0x38
	 * 0011|1000 0x38
	 */
	0x0E, 0x08, 0x08, 0x38, 0x38, //music note
	/*
	 * 0011|1110 0x3E
	 * 0110|0011 0x63
	 * 0110|1011 0x6B
	 * 0110|0011 0x63
	 * 0011|1110 0x3E
	 */
	0x3E, 0x63, 0x6B, 0x63, 0x3E, //o button
	/*
	 * 0000|1000 0x08
	 * 0001|1100 0x1C
	 * 0011|1110 0x3E
	 * 0001|1100 0x1C
	 * 0000|1000 0x08
	 */
	0x08, 0x1C, 0x3E, 0x1C, 0x08, //pico8 logo
	/*
	 * 0000|0000 0x00
	 * 0000|0000 0x00
	 * 0101|0101 0x55
	 * 0000|0000 0x00
	 * 0000|0000 0x00
	 */
	0x00, 0x00, 0x55, 0x00, 0x00, //dotted line
	/*
	 * 0011|1110 0x3E
	 * 0110|0111 0x67
	 * 0110|0011 0x63
	 * 0110|0111 0x67
	 * 0011|1110 0x3E
	 */
	0x3E, 0x67, 0x63, 0x67, 0x3E, //right button
	/*
	 * 0000|1000 0x08
	 * 0001|1100 0x1C
	 * 0111|1111 0x7F
	 * 0011|1110 0x3E
	 * 0010|0010 0x22
	 */
	0x08, 0x1C, 0x7F, 0x3E, 0x22, //star
	/*
	 * 0011|1110 0x3E
	 * 0001|1100 0x1C
	 * 0000|1000 0x08
	 * 0001|1100 0x1C
	 * 0011|1110 0x3E
	 */
	0x3E, 0x1C, 0x08, 0x1C, 0x3E, //hour glass
	/*
	 * 0011|1110 0x3E
	 * 0111|0111 0x77
	 * 0110|0011 0x63
	 * 0110|0011 0x63
	 * 0011|1110 0x3E
	 */
	0x3E, 0x77, 0x63, 0x63, 0x3E, //up button
	/*
	 * 0000|0000 0x00
	 * 0101|0000 0x50
	 * 0010|0101 0x25
	 * 0000|0010 0x02
	 * 0000|0000 0x00
	 */
	0x00, 0x50, 0x25, 0x02, 0x00, //birds
	/*
	 * 0000|0000 0x00
	 * 0100|0100 0x44
	 * 0010|1010 0x2A
	 * 0001|0001 0x11
	 * 0000|0000 0x00
	 */
	0x00, 0x44, 0x2A, 0x11, 0x00, //mountains
	/*
	 * 0011|1110 0x3E
	 * 0110|1011 0x6B
	 * 0111|0111 0x77
	 * 0110|1011 0x6B
	 * 0011|1110 0x3E
	 */
	0x3E, 0x6B, 0x77, 0x6B, 0x3E, //x button
	/*
	 * 0111|1111 0x7F
	 * 0000|0000 0x00
	 * 0111|1111 0x7F
	 * 0000|0000 0x00
	 * 0111|1111 0x7F
	 */
	0x7F, 0x00, 0x7F, 0x00, 0x7F, //horizontal stripes
	/*
	 * 0101|0101 0x55
	 * 0101|0101 0x55
	 * 0101|0101 0x55
	 * 0101|0101 0x55
	 * 0101|0101 0x55
	 */
	0x55, 0x55, 0x55, 0x55, 0x55, //verticle stripes
};

static void draw_large_char(P8SCIIChar c, int x, int y, BitmapPixel fill_value,
        BitmapPixel *out_bitmap, int bitmap_width, int bitmap_height) {
	int index = (c - 128) * 5;
	if (index < 0 || index >= ARRAY_LEN(LARGE_GLYPHS)) {
		return;
	}
	for (int i = index, tmp_y = y; i < index + 5; i++,tmp_y++) {
        if (tmp_y >= bitmap_height) {
            //bounds check
            return;
        }
		int mask = 0x40;
		for (int j = 0, tmp_x = x; j < 7; j++,mask >>= 1,tmp_x++) {
			if (tmp_x >= bitmap_width) {
                //bounds check
				return;
			}
			if (LARGE_GLYPHS[i] & mask) {
				out_bitmap[tmp_y*bitmap_width + tmp_x] = fill_value;
			}
		}
	}
}
static void draw_small_char(P8SCIIChar c, int x, int y, BitmapPixel fill_value,
        BitmapPixel *out_bitmap, int bitmap_width, int bitmap_height) {
	int index = c - ' ';
	if (index < 0 || index >= ARRAY_LEN(SMALL_GLYPHS)) {
		return;
	}
	int mask = 0x4000;
	uint16_t bitmap = SMALL_GLYPHS[index];
	for (int tmp_y = y+4; tmp_y >= y; tmp_y--) {
        if (tmp_y >= bitmap_height) {
            //bounds check
            continue;
        }
		for (int tmp_x = x; tmp_x < x+3; tmp_x++) {
			if (tmp_x >= bitmap_width) {
                //bounds check
				return;
			}
			if (bitmap & mask) {
				out_bitmap[tmp_y*bitmap_width + tmp_x] = fill_value;
			}
			mask >>= 1;
		}
	}
}

void p8scii_print(const P8SCIIChar *s, int x, int y, BitmapPixel fill_value, 
        BitmapPixel *out_bitmap, int bitmap_width, int bitmap_height) {
    if (y >= bitmap_height) {
        //bounds check
        return;
    }
	for (;*s;s++) {
        if (x >= bitmap_width) {
            //bounds check
            return;
        }
		if (*s < 128) {
			draw_small_char(*s, x, y, fill_value, out_bitmap, bitmap_width, bitmap_height);
			x += SMALL_GLYPH_WIDTH + GLYPH_SPACE;
		}
		else {
			draw_large_char(*s, x, y, fill_value, out_bitmap, bitmap_width, bitmap_height);
			x += LARGE_GLYPH_WIDTH + GLYPH_SPACE;
		}
	}
}
#endif
#endif
