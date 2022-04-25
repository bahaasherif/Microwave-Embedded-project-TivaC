#include "keypad.h"



static const unsigned char keymap[NO_OF_ROW][No_OF_COL] = {
{ '1', '2', '3', 'A'},
{ '4', '5', '6', 'B'},
{ '7', '8', '9', 'C'},
{ '*', '0', '#', 'D'},
};


void KEYPAD_Init(void){

SET_BIT((SYSCTL->RCGCGPIO),1); // Enable clock to PORTB
GPIOB->CR  |= 0xFF;  // Allow settings for all pins of PORTA
GPIOB->DEN |= 0xFF;  // Set PORTA as digital pins
GPIOB->DIR |= 0xF0;  // Set the most 4 pins of PORTB as digital output (columns) and the least 4 pins as digital inputs (rows)
GPIOB->PDR |= 0x0F;  // Enable pull down resistor on the least 4 pins of PORTB (rows)
}

