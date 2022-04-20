#include "gpio.h"

int main(void)
{
	GPIO_setupPinDirection(PORTF_ID,PIN1_ID,PIN_OUTPUT,PIN_NO_RESISTOR);
	GPIO_writePin(PORTF_ID,PIN1_ID,LOGIC_HIGH);
	
	while(1);
}