#include "gpio.h"
#include "systick.h"
#include "keypad.h"

int main(void)
{
	GPIO_setupPinDirection(PORTF_ID,PIN1_ID,PIN_OUTPUT,PIN_NO_RESISTOR);
	GPIO_setupPinDirection(PORTF_ID,PIN2_ID,PIN_OUTPUT,PIN_NO_RESISTOR);
	GPIO_setupPinDirection(PORTF_ID,PIN3_ID,PIN_OUTPUT,PIN_NO_RESISTOR);
	KEYPAD_Init();

	SysTick_Enable();
	uint8_t t = '0';
	
	while(1)
	
	{
		t = KEYPAD_Getkey();
		if(t=='A')
		{
			GPIO_writePin(PORTF_ID,PIN1_ID,LOGIC_HIGH);
			GPIO_writePin(PORTF_ID,PIN2_ID,LOGIC_LOW);
			GPIO_writePin(PORTF_ID,PIN3_ID,LOGIC_LOW);
		}
		else if (t=='B')
			{
			GPIO_writePin(PORTF_ID,PIN2_ID,LOGIC_HIGH);
			GPIO_writePin(PORTF_ID,PIN1_ID,LOGIC_LOW);
			GPIO_writePin(PORTF_ID,PIN3_ID,LOGIC_LOW);
		}
			else if(t=='C')
			{
				GPIO_writePin(PORTF_ID,PIN3_ID,LOGIC_HIGH);
			GPIO_writePin(PORTF_ID,PIN1_ID,LOGIC_LOW);
			GPIO_writePin(PORTF_ID,PIN2_ID,LOGIC_LOW);
		}
			
	}
		
	
	
	
}
