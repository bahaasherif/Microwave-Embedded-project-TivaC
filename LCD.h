#ifndef LCD_H_
#define LCD_H_

#include "stdint.h"
#include "common_macros.h"
#include "TM4C123.h"
#include "systick.h"

/***************************
 *                      Preprocessor Macros                                    *
 ***************************/
/* LCD Data bits mode configuration */



/* LCD HW Pins */
#define RS 0x01   //PIN0 IN PORTB
#define RW 0x02   //PIN1 IN PORTB
#define EN 0x04   //PIN2 IN PORTB

#define LCD (GPIOB->DATA)

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80 //Takes cursor to beginning of first row
#define INCREMENT_CURSOR 0x06
#define LCD_ON  0x0F

/***************************
 *                      Functions Prototypes                                   *
 ***************************/
void LCD_sendCommand(uint8_t command);

void LCD_Init(void);

void LCD_writeBits(uint8_t data, uint8_t control);



#endif /* LCD_H_ */