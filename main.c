#include "gpio.h"
#include "LCD.h"
#include "systick.h"
#include "keypad.h"



//void CASE_B (uint8_t EnteredCookingWeight);

//void Display_Time(uint16_t CookingTimeInSecs);




//int main( void ) {
//	
//	SysTick_Init();
//	LCD_Init();
//	KEYPAD_Init();
//	
//	GPIO_setupPinDirection(PORTF_ID,PIN0_ID,PIN_INPUT,PIN_PULLUP_RESISTOR);
//	GPIO_setupPinDirection(PORTF_ID,PIN4_ID,PIN_INPUT,PIN_PULLUP_RESISTOR);
//	
//	uint8_t COOKING_CASE  = '0';
//	uint16_t CookingTimeInSecs = 0 ;
//	uint8_t EnteredCookingWeight = '0';
//	uint8_t CookingTimeCaseD [] = {"0000"};
//	

//	
//	
//	while(1)
//	{
//		
//		COOKING_CASE = KEYPAD_Getkey();
//		
//		switch(COOKING_CASE) {
//			
//			case 'A' :
//				LCD_displayStringRowColumn(0,4,"POP CORN");
//			  CookingTimeInSecs = 60 ;
//			  Display_Time(CookingTimeInSecs);		
//			  LCD_clearScreen();
//						break ;		
//						
//				ERROR_CASE_B:						
//			case 'B' :
//				LCD_displayStringRowColumn(0,2,"BEEF WEIGHT?");
//			  EnteredCookingWeight = KEYPAD_Getkey();
//			  if((EnteredCookingWeight <='9') && (EnteredCookingWeight>='1'))
//          {
//						LCD_clearScreen();
//						LCD_displayCharacter(EnteredCookingWeight);
//						LCD_displayString(" kilos");
//						SysTick_Wait1s(2);
//						LCD_clearScreen();
//						CookingTimeInSecs = (EnteredCookingWeight - '0') * 30;
//						Display_Time(CookingTimeInSecs);
//				    LCD_clearScreen();		
//					}
//					
//				else{
//					LCD_clearScreen();
//					LCD_displayStringRowColumn(0,7,"ERR");
//					SysTick_Wait1s(2);
//					goto ERROR_CASE_B;
//					
//				}
//					break;
//				
//				
//				ERROR_CASE_C:	
//			case 'C' :
//				LCD_displayStringRowColumn(0,0,"Chicken WEIGHT?");
//			  EnteredCookingWeight = KEYPAD_Getkey();
//			  if((EnteredCookingWeight <='9') && (EnteredCookingWeight>='1'))
//          {
//						LCD_clearScreen();
//						LCD_displayCharacter(EnteredCookingWeight);
//						LCD_displayString(" kilos");
//						SysTick_Wait1s(2);
//						LCD_clearScreen();
//						CookingTimeInSecs = (EnteredCookingWeight - '0') * 12;
//						Display_Time(CookingTimeInSecs);
//				    LCD_clearScreen();		
//					}
//					
//				else{
//					LCD_clearScreen();
//					LCD_displayStringRowColumn(0,7,"ERR");
//					SysTick_Wait1s(2);
//					goto ERROR_CASE_C;
//					
//				}
//					break;
//				
//				case 'D' :
//			LCD_displayStringRowColumn(0,1,"Cooking Time?");
//			SysTick_Wait1s(2);
//			LCD_clearScreen();	
//				
//			LCD_displayStringRowColumn(1,6,"00:00");	
//			CookingTimeCaseD[0] = KEYPAD_Getkey();
//			LCD_displayCharRowColumn(1,10,CookingTimeCaseD[0]);
//				
//			CookingTimeCaseD[1] = KEYPAD_Getkey();
//			LCD_displayCharRowColumn(1,9,CookingTimeCaseD[0]);
//			LCD_displayCharRowColumn(1,10,CookingTimeCaseD[1]);
//			
//			CookingTimeCaseD[2] = KEYPAD_Getkey();
//			LCD_displayCharRowColumn(1,7,CookingTimeCaseD[0]);
//			LCD_displayCharRowColumn(1,9,CookingTimeCaseD[1]);
//			LCD_displayCharRowColumn(1,10,CookingTimeCaseD[2]);
//		  
//			CookingTimeCaseD[3] = KEYPAD_Getkey();
//			LCD_displayCharRowColumn(1,6,CookingTimeCaseD[0]);
//			LCD_displayCharRowColumn(1,7,CookingTimeCaseD[1]);
//			LCD_displayCharRowColumn(1,9,CookingTimeCaseD[2]);
//			LCD_displayCharRowColumn(1,10,CookingTimeCaseD[3]);
//				
//			CookingTimeInSecs = ((CookingTimeCaseD[0] - '0') * 600) + ((CookingTimeCaseD[1] - '0') * 60) + ((CookingTimeCaseD[2] - '0') * 10) + ((CookingTimeCaseD[3] - '0'));
//	    Display_Time(CookingTimeInSecs);
//      LCD_clearScreen();			
//	
//			
//				 
//				
//		
//				
//			  

//						
//		}			
//  }
//}

//void Display_Time(uint16_t CookingTimeInSecs) {
//	
//	for(CookingTimeInSecs;CookingTimeInSecs > 0;CookingTimeInSecs --)
//						{
//							LCD_displayTime(CookingTimeInSecs);
//							SysTick_Wait1s(1);
//						}
//	
//}

#include "TM4C123.h"                    // Device header

int main(void)
{
    
	GPIO_setupPinDirection(PORTF_ID,PIN0_ID,PIN_INPUT,PIN_PULLUP_RESISTOR);
	GPIO_setupPinDirection(PORTF_ID,PIN4_ID,PIN_INPUT,PIN_PULLUP_RESISTOR);
	GPIO_setupPinDirection(PORTF_ID,PIN3_ID,PIN_OUTPUT,PIN_NO_RESISTOR);
	

	GPIOF_EnableInt();
	
 

    
    while(1)
    {
			// do nothing and wait for the interrupt to occur
    }
}

/* SW1 is connected to PF4 pin, SW2 is connected to PF0. */
/* Both of them trigger PORTF falling edge interrupt */
void GPIOF_Handler(void)
{	
  if (BIT_IS_SET((GPIOF->MIS),4)) /* check if interrupt causes by PF4/SW1*/
    {   
      GPIOF->DATA |= (1<<3);
      GPIOF->ICR |= 0x10; /* clear the interrupt flag */
     } 
    else if (BIT_IS_SET((GPIOF->MIS),0)) /* check if interrupt causes by PF0/SW2 */
    {   
     GPIOF->DATA &= ~0x08;
     GPIOF->ICR |= 0x01; /* clear the interrupt flag */
    }
}