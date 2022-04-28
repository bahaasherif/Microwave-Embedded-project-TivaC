#ifndef KEYPAD_H_
#define KEYPAD_H_
#include  "TM4C123.h"
#include  "common_macros.h"
#include  "systick.h"


/*********
                          DEFINITIONS
**********/	
/* Keypad configurations for number of rows and columns */
#define No_OF_COL 4
#define NO_OF_ROW 4


#define KEYPAD_PORT_C  GPIOC
#define KEYPAD_PORT_E  GPIOE


/*********
                         FUNCTION PROTOTYPES
**********/

void KEYPAD_Init(void);
/********************************
**** This function is to initalize the port of keypad**************
********************************/
uint8_t KEYPAD_Getkey(void);
/********************************
********THIS FUNCTION IS USED TO RETURN PRESSED KEY*********
*******************************/




#endif