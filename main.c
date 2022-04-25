#include "gpio.h"
#include "systick.h"

int main(void)
{
	GPIO_setupPinDirection(PORTF_ID,PIN2_ID,PIN_OUTPUT,PIN_NO_RESISTOR);
	SysTick_Enable();
	
}
