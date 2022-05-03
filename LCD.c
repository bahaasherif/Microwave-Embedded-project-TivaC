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
void LCD_displayCharacter(uint8_t data)
{
	LCD_writeBits(data & 0xF0 , RS);   
	LCD_writeBits((data & 0x0F )<< 4 , RS);     
	delayUs(40);											
	
		
}

void LCD_displayString(const uint8_t *Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
}

void LCD_goToRowColumn(uint8_t row,uint8_t col)
{
	uint8_t Address;
	
	
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		
	}					
	
	LCD_sendCommand(Address | SET_CURSOR_LOCATION); 
}
void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); //clear display 
}




