#include  "TM4C123.h"

void SysTick_Enable (void); // Initialize the SysTick Timer
void SysTick_Disable(void); // Disable the SysTick timer
void SysTick_Wait (uint32_t delay); //The delay parameter is in units pf the 16 MHz core clock (62.5 ns)
void SysTick_Wait1s(uint32_t delay); //This function wait for delay*1s
void delayMs(uint32_t n);    //Delay for 1 millisecond
void delayUs(uint32_t n);    //Delay for 1 Microsecond     
