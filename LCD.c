#include "lcd.h"
#include "gpio.h"

/***************************
 *                      Functions Definitions                                  *
 ***************************/
void LCD_Init(void)
{
	GPIO_setupPortDirection(PORTB_ID,PORT_OUTPUT);
	LCD_sendCommand(TWO_LINE_LCD_Four_BIT_MODE);  
	LCD_sendCommand(INCREMENT_CURSOR);          
	LCD_sendCommand(CLEAR_COMMAND);					
	LCD_sendCommand(LCD_ON);          
	LCD_sendCommand(SET_CURSOR_LOCATION);   
  delayMs(50);	
}

void LCD_writeBits(uint8_t data, uint8_t control)
{
	data &= 0xF0;                       
	control &= 0x0F;                    
	LCD = data | control;         
	LCD = data | control | EN;    
	delayUs(1);													
	LCD = data | control;					
	LCD = 0;                      
}



void LCD_sendCommand(uint8_t command)
{
	LCD_writeBits(command & 0xF0 , 0);    
	LCD_writeBits((command & 0x0F )<< 4 , 0);			 
	delayMs(2);       
	
}




