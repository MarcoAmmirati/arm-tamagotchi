/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Author: 							Marco Ammirati
** Last modified Date:  08/01/2023
** Descriptions:        handlers of the RIT, used for the joystick
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "RIT.h"
#include "../led/led.h"
#include "../GLCD/GLCD.h"
#include "../timer/timer.h"
#include "../functions.h"
#include "../ADC/adc.h"
#include "../TouchPanel/TouchPanel.h"

/*	 VARIABLES		*/

//AGE
extern int seconds;
extern int minutes;
extern int hours;
extern char age[10];

//FOOD
extern int happiness;
extern int satiety;
extern int food_menu;

//MOVEMENT
extern int centre;
extern int direction;
extern int animation;

//SOUND
extern int freqs[8];
extern int food[3];
extern int cuddle[8];
extern int number_of_note;
extern int i;
extern int flag;

/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler used for joystick
**
******************************************************************************/

void RIT_IRQHandler (void)
{					
	static int select=0;
	static int left = 0;
	static int right = 0;
	
	ADC_start_conversion();
	
	if(getDisplayPoint(&display, Read_Ads7846(), &matrix )){
		if(display.y > 95 && display.y < 220 && display.x > 77 && display.x < 163 && happiness < 100 && animation == 0){
			disable_RIT();
			number_of_note = 8;
			flag = 0;
			i = number_of_note;
			init_timer(2, cuddle[0]);
			reset_timer(2);
			enable_timer(2);
			disable_timer(0);
			reset_timer(0);
			animation = CUDDLES;
			cuddle1();
			enable_timer(0);
		}
		else
			;//ignora
	}
	
	/*	JOYSTICK	*/
	
	//LEFT
	
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	
		left++;
		switch(left){
			case 1:
				if(food_menu != MEAL && animation == 0){
					switch_to_meal(food_menu);
					food_menu = MEAL;
				}
				break;
			default:
				break;
		}
	}
		else{
			left=0;
	}

	//RIGHT
	
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){	
		right++;
		switch(right){
			case 1:
				if(food_menu != SNACK && animation == 0){
					switch_to_snack(food_menu);
					food_menu = SNACK;
				}
				break;
			default:
				break;
		}
	}
		else{
			right=0;
	}	
	
	//SELECT 
	
	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){	
		select++;
		switch(select){
			case 1:
			disable_timer(2);
			reset_timer(2);
			init_timer(2,2120);
			enable_timer(2);
				if(food_menu == MEAL && satiety < 100 && animation == 0){
					disable_RIT();
					disable_timer(0);
					satiety = satiety + 25;
					animation = FOOD;
					meal();
					direction = LEFT;
					enable_timer(3);
				}
				else if(food_menu == SNACK && happiness < 100 && animation == 0){
					disable_RIT();
					disable_timer(0);
					happiness = happiness + 25;
					animation = FOOD;
					snack();
					direction = LEFT;
					enable_timer(3);
				}
				else if (animation == LEAVE){
					seconds = 0;
					minutes = 0;
					hours = 0;
					happiness = 100;
					satiety = 100;
					food_menu = 0;
					centre = 120;
					direction = LEFT;
					animation = 0;
					number_of_note = 1;
					i = number_of_note;
					flag = 0;
					sprintf(age, "%02d:%02d:%02d", hours, minutes, seconds);
					GUI_Text(120, 10, (uint8_t*) age, Black, White);
					set_happiness(happiness);
					set_satiety(satiety);
					LCD_DrawRectangle(100, 278, 40, 18, White);
					LCD_DrawBiggerLine(120, 255, 120, 319, Black);
					LCD_DrawThickRectangle(1, 255, 237, 63, Black);
					GUI_Text(43, 278, (uint8_t*) "Meal", Black, White);
					GUI_Text(155, 278, (uint8_t*) "Snack", Black, White);			
					LCD_DrawRectangle(21, 140, 200, 60, White);					
					basicMooncake();
					enable_timer(0);
					enable_timer(1);
				}			
				break;
			default:
				break;
		}
	}
	else{
		select = 0;
	}

  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
