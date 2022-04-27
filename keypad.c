#include "TM4C123.h"
#include "keypad.h"

void delayus(int n) //(16 MHz CPU clock)
{
volatile int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3; j++)
{}
}

const static unsigned char keymap[NO_OF_ROW][No_OF_COL] = {
{ '1', '2', '3', 'A'},
{ '4', '5', '6', 'B'},
{ '7', '8', '9', 'C'},
{ '*', '0', '#', 'D'},
};

void KEYPAD_Init(void){
	 SYSCTL->RCGCGPIO |= 0x14; // Enable clock to PORTC and PORTE
	 (KEYPAD_PORT_C)->CR  |= 0xF0;  // Allow settings for all pins of PORTC
	 (KEYPAD_PORT_E)->CR  |= 0x0F; 	// Allow settings for all pins of PORTE
	 (KEYPAD_PORT_C)->DEN |= 0xF0;  // Set PORTC as digital pins
	 (KEYPAD_PORT_E)->DEN |= 0x0F;  // Set PORTE as digital pins
	 (KEYPAD_PORT_C)->DIR |= 0xF0;  // Set pins of PORTC as digital output
	 (KEYPAD_PORT_E)->DIR |= 0x00;  // Set pins of PORTE as digital input
	 (KEYPAD_PORT_E)->PDR |= 0x0F;  //Enable pull down resistor on PORTE
}

uint8_t KEYPAD_Getkey(void){
		while(1){
			for(int i = 0; i < 4; i++)    //Scan columns loop
			{
				(KEYPAD_PORT_C)->DATA = (1U << (i+4));
				delayus(1);
				for(int j = 0; j < 4; j++)  //Scan rows
				{
					if(((KEYPAD_PORT_E)->DATA & 0x0F) & (1U << j))
					return keymap[j][i];
				}
			}
		}
}