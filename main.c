#include "gpio.h"
#include "LCD.h"
#include "systick.h"
#include "keypad.h"

void Timer(int time);

void CASE_B (uint8_t EnteredCookingWeight);


int main( void ) {
	
	SysTick_Init();
	LCD_Init();
	KEYPAD_Init();
	
	GPIO_setupPinDirection(PORTF_ID,PIN0_ID,PIN_INPUT,PIN_PULLUP_RESISTOR);
	GPIO_setupPinDirection(PORTF_ID,PIN4_ID,PIN_INPUT,PIN_PULLUP_RESISTOR);
	
	uint8_t COOKING_CASE  = '0';
	uint16_t CookingTimeInSecs = 0 ;
	uint8_t EnteredCookingWeight = '0';
	

	
	
	while(1)
	{
		
		COOKING_CASE = KEYPAD_Getkey();
		
		switch(COOKING_CASE) {
			
			case 'A' :
				LCD_displayStringRowColumn(0,4,"POP CORN");
			  CookingTimeInSecs = 60 ;
			
						for(CookingTimeInSecs;CookingTimeInSecs > 0;CookingTimeInSecs --)
						{
							LCD_displayTime(CookingTimeInSecs);
							SysTick_Wait1s(1);
						}
				 LCD_clearScreen();
						break ;		
						
				ERROR_CASE_B:						
			case 'B' :
				LCD_displayStringRowColumn(0,2,"BEEF WEIGHT?");
			  EnteredCookingWeight = KEYPAD_Getkey();
			  if((EnteredCookingWeight <='9') && (EnteredCookingWeight>='1'))
          {
						LCD_clearScreen();
						LCD_displayCharacter(EnteredCookingWeight);
						LCD_displayString(" kilos");
						SysTick_Wait1s(2);
						LCD_clearScreen();
						CookingTimeInSecs = (EnteredCookingWeight - '0') * 30;
						
						for(CookingTimeInSecs;CookingTimeInSecs > 0;CookingTimeInSecs --)
									{
										LCD_displayTime(CookingTimeInSecs);
										SysTick_Wait1s(1);
									}
				    LCD_clearScreen();		
					}
					
				else{
					LCD_clearScreen();
					LCD_displayStringRowColumn(0,7,"ERR");
					SysTick_Wait1s(2);
					goto ERROR_CASE_B;
					
				}
					break;
				
				
				ERROR_CASE_C:	
			case 'C' :
				LCD_displayStringRowColumn(0,0,"Chicken WEIGHT?");
			  EnteredCookingWeight = KEYPAD_Getkey();
			  if((EnteredCookingWeight <='9') && (EnteredCookingWeight>='1'))
          {
						LCD_clearScreen();
						LCD_displayCharacter(EnteredCookingWeight);
						LCD_displayString(" kilos");
						SysTick_Wait1s(2);
						LCD_clearScreen();
						CookingTimeInSecs = (EnteredCookingWeight - '0') * 12;
						
						for(CookingTimeInSecs;CookingTimeInSecs > 0;CookingTimeInSecs --)
									{
										LCD_displayTime(CookingTimeInSecs);
										SysTick_Wait1s(1);
									}
				    LCD_clearScreen();		
					}
					
				else{
					LCD_clearScreen();
					LCD_displayStringRowColumn(0,7,"ERR");
					SysTick_Wait1s(2);
					goto ERROR_CASE_C;
					
				}
					break;
				
		
				
			  

						
		}			
  }
}

//void CASE_B (uint8_t EnteredCookingWeight) {
//	
//	LCD_clearScreen();
//						LCD_displayCharacter(EnteredCookingWeight);
//						LCD_displayString(" kilos");
//						SysTick_Wait1s(2);
//						LCD_clearScreen();
//						CookingTimeInSecs = (EnteredCookingWeight - '0') * 30;
//						
//										 for(CookingTimeInSecs;CookingTimeInSecs > 0;CookingTimeInSecs --)
//									{
//										LCD_displayTime(CookingTimeInSecs);
//										SysTick_Wait1s(1);
//									}
//				    LCD_clearScreen();		
//	
//}

	
//	char somaa = KEYPAD_Getkey();
//	char weight;
//	int x; //weight in integer
//	switch(somaa){
//		case 'A':
//			// SHOW_STRING("popcorn");
//			SysTick_Enable ();
//			SysTick_Wait1s(2);
//			SysTick_Disable();
//			// clear lcd
//			for(int i=59;i>=0;i--){
//				// print i lcd
//				SysTick_Enable();
//				SysTick_Wait1s(1);
//				SysTick_Disable();
//				// clear lcd
//			}
//			
//			break;
//		case 'B':
//			caseB:
//			// print beefweight?
//			weight = KEYPAD_Getkey();
//			x = atoi(&weight);
//			// clear lcd
//			if (x>0 && x<10){
//				// print no of kilos in lcd
//				SysTick_Enable ();
//				SysTick_Wait1s(2);
//				SysTick_Disable();
//				
//			}else{
//				// print in lcd Err
//				SysTick_Enable ();
//				SysTick_Wait1s(2);
//				SysTick_Disable();
//				// clear lcd
//				goto caseB;
//			}
//			break;
//		case 'C':
//			
//			break;
//		case 'D':
//			
//			break;
//		default:
//				//	SHOW_STRING("ERR");
//			break;
//		}		
//	return 0;
//}



//void Timer(int time){
//	int min=0;
//	int sec=0;
//	min= time/60;
//	sec=time%60;
//	do{
//		// print in lcd mm:ss
//		SysTick_Enable();
//		SysTick_Wait1s(1);
//		SysTick_Disable();
//		// clear lcd
//		if(sec==0 && min >0){
//			min-=1;
//			sec = 59;	
//		}else{
//			sec-=1;
//		}
//	}
//	while(sec>0);
//	// print 00:00
//	
//}