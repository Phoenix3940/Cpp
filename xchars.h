#ifndef XCHARS_H
#define XCHARS_H
        const unsigned char AE = static_cast<unsigned char>(142);
        const unsigned char ae = static_cast<unsigned char>(132);
        const unsigned char OE = static_cast<unsigned char>(153);
        const unsigned char oe = static_cast<unsigned char>(148);
        const unsigned char UE = static_cast<unsigned char>(154);
        const unsigned char ue = static_cast<unsigned char>(129);
        const unsigned char ss = static_cast<unsigned char>(225);

        /**Enter-Taste*/
        #define ENTER (char)13
        /**Esc-Taste*/
        #define ESC (char)27
        /**Leerzeichen*/
        #define SPACE (unsigned char)32
        /**Tab*/
        #define TAB (unsigned char)9
        /**Loeschen*/
        #define DEL (unsigned char)127
        /**Shift out*/
        #define SHIFT_IN (unsigned char)14
        /**Shift in*/
        #define SHIFT_OUT (unsigned char)15
#endif
