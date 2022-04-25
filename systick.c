#include  "TM4C123.h"
#include "systick.h"
#include "common_macros.h"

#define SYSTEM_CLK_FREQUENCY 16000 //Clock Speed in kHz
#define SYSTEM_TICK_S          1   //System ticks every 1 seconds


void SysTick_Enable (void) {
	SysTick ->CTRL = 0;               //Disable SysTick during setup
	SysTick ->LOAD = 0x00FFFFFF;      //Maximum reload value
	SysTick ->VAL = 0;                //any write to CURRENT clears it
	     //enable SysTick with core clock
  SET_BIT((SysTick ->CTRL),0U);
	SET_BIT((SysTick ->CTRL),2U);
}

void SysTick_Wait (uint32_t delay){
	SysTick ->LOAD = delay - 1;      //Number of counts
	SysTick ->VAL = 0;               //Any value written to CURRENT clears
while (BIT_IS_CLEAR((SysTick->CTRL),16U)){} //wait for flag          
}                                         

void delayMs(uint32_t n)
{  
	volatile uint32_t i,j;             //volatile is important for variables incremented in code
	for(i=0;i<n;i++)
		for(j=0;j<3180;j++)         //delay for 1 msec
		{}
}
