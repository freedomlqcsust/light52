/**
    @file hello.c
    @brief Hello World demo for light52 core.
        
    Does nothing but send a greeting string to the console.
    Should fit in 2K of ROM and use no XRAM.
*/
#include <stdio.h>
#include "../../include/light52.h"

/*-- Public functions --------------------------------------------------------*/

void main(void){
    /* The UART is left in its default reset state: 19200-8-N-1 */
    
    printf("\n\r");
    printf("Light52 project -- " __DATE__ "\n\n\r");
    printf("Hello World!\n\r");

    /* Quit simulation by writing EOT to UART. */
    printf("\004");
    while(1);
}

/*-- Local functions ---------------------------------------------------------*/

/** 
    Stdclib putchar replacement function.
    Relies on polling for simplicity and does CR to CRLF expansion.
    
    @arg c Character to be displayed. Character '\n' will be expanded to '\n\r'.
*/
void putchar (char c) { 
#ifdef BUILD_FOR_HW
    /* This will run on actual HW so keep track of RDY flags. */
    while (!TXRDY);
    SBUF = c;
    if(c=='\n'){
        while (!TXRDY);
        SBUF = '\r';
    }
#else
    /* This is for sim only so ignore RDY flags which ISS doesn't simulate. */
    SBUF = c;
    if(c=='\n'){
        SBUF = '\r';
    }
#endif
}
