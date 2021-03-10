# P8SCII Single Header C Library
`p8scii.h` is a single header C library for print and using the P8SCII character set and font from the PICO-8 fantasy console.  Included are bitmaps of each character in the set:
- `SMALL_GLYPHS` array: This contains all P8SCII characters that directly map to ASCII values 32-126 (127 is a printable character in P8SCII).  These characters are 3x5 pixels. The upper-case and lower-case characters are reversed as PICO-8 typically reverses the case.
- `LARGE_GLYPHS` array: This contains all P8SCII characters from 128-153, which are typically used for drawing purposes.  These characters are 7x5 pixels.

In addition, the included `p8scii_print` function can be used in a project as-is, but it's main purpose is to serve as a reference for how to use the aformentioned arrays. It is probably not optimized for your project.

Take note of the comments that start with `Customize:`.  These are declarations you may want to change to suit your needs.

## Usage
Included is an example program in `example_main.c` that uses this library.  This program outputs the entire P8SCII set into a 128x128 character field. An example usage of this program is:

1. Compile the program. E.g. `cc example_main.c -o example_program`
2. Run the program and output a text file (the terminal may be too small to see the output). E.g. `./example_program > p8scii.txt`
3. Open the file in your text editor of choice that can display 128 columns. E.g. `gvim p8scii.txt`.
4. You should get the following output:

```
     #  # # # # ### # # ##   #   #   #  # #                   # ### ##  ### ### # # ### #   ### ### ###           #     #   ### 
     #  # # ### ##    # ##  #   #     #  #   #               #  # #  #    #   # # # #   #     # # # # #  #   #   #  ###  #    # 
     #      # #  ##  #  ##      #     # ### ###     ###      #  # #  #  ###  ## ### ### ###   # ### ###         #         #  #  
            ### ### #   # #     #     #  #   #   #           #  # #  #  #     #   #   # # #   # # #   #  #   #   #  ###  #      
     #      # #  #  # # ###      #   #  # #     #        #  #   ### ### ### ###   # ### ###   # ###   #     #     #     #    #  
                                                                                                                                
 #                                                                                                          ##  #    ##  #      
# # ### ### ### ##  ### ### ### # # ### ### # # #   ### ##   ## ###  #  ###  ## ### # # # # # # # # # # ### #    #    # # #     
# # # # ### #   # # ##  ##  #   # #  #   #  ##  #   ### # # # # # # # # # # #    #  # # # # # #  #  ###   # #    #    #         
#   ### # # #   # # #   #   # # ###  #   #  # # #   # # # # # # ### ##  ##    #  #  # # ### ### # #   # #   #    #    #         
 ## # # ### ### ##  ### #   ### # # ### ##  # # ### # # # # ##  #    ## # # ##   #   ##  #  ### # # ### ### ##    #  ##     ### 
                                                                                                                                
 #  ### ###  ## ##  ### ###  ## # # ### ### # # #   ### ##   ## ###  #  ###  ## ### # # # # # # # # # # ###  ##  #  ##          
  # # # # # #   # # #   #   #   # #  #   #  # # #   ### # # # # # # # # # # #    #  # # # # # # # # # #   #  #   #   #    #  #  
    ### ##  #   # # ### ### #   ###  #   #  ##  #   # # # # # # ### # # ##  ###  #  # # # # # #  #  ###  #  ##   #   ## ### # # 
    # # # # #   # # #   #   # # # #  #   #  # # #   # # # # # # #   ##  # #   #  #  # # ### ### # #   # #    #   #   #  #   # # 
    # # ###  ## ### ### #   ### # # ### ##  # # ### # # # # ##  #    ## # # ##   #   ##  #  ### # # ### ###  ##  #  ##      ### 
                                                                                                                                
####### # # # # #     #  #####  #   #     #       ###    ## ##    ###     ###     ###    #####  #######    ###   #####     #    
#######  # # #  ####### ##   ##   #   #   ####   ### #   #####   ## ##    ###    #####  ###  ## # ### #    #    ##   ##   ###   
####### # # # # # ### # ##   ## #   #     ###    #####   #####  ### ###  #####  ####### ##   ## #######    #    ## # ##  #####  
#######  # # #  # ### # ### ###   #   #  ####    #####    ###    ## ##    ###    # # #  ###  ## #     #  ###    ##   ##   ###   
####### # # # #  #####   #####  #   #       #     ###      #      ###     # #    # ###   #####  #######  ###     #####     #    
                                                                                                                                
         #####     #     #####   #####                   #####  ####### # # # #                                                 
        ##  ###   ###     ###   ### ### # #     #   #   ## # ##         # # # #                                                 
# # # # ##   ## #######    #    ##   ##  #  # #  # # #  ### ### ####### # # # #                                                 
        ##  ###  #####    ###   ##   ##      #    #   # ## # ##         # # # #                                                 
         #####   #   #   #####   #####                   #####  ####### # # # #                                                 
                           
```

## License/Credits

All code here is written by Daniel Bokser but released into the public domain.  The font was designed by Joseph "zep" White.
The PICO-8 Fantasy Console and this [PICO-8 forum post](https://www.lexaloffle.com/bbs/?tid=3760) were invaluable resources for making this library. Also thanks to Sean Barrett's stb libraries for the inspiration of the format of this library.
