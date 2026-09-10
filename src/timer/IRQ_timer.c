/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Author: 							Marco Ammirati
** Last modified Date:  08/01/2023
** Descriptions:        handlers on the interrupt of the timers
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "timer.h"
#include "../GLCD/GLCD.h"
#include "../RIT/RIT.h"
#include "../functions.h"

/*	 VARIABLES		*/

//AGE
extern int seconds;
extern int minutes;
extern int hours;
char age[N];

//FOOD
extern int happiness;
extern int satiety;
extern int food_menu;
int time_to_eat = 0;
int time = 0;

//MOVEMENT
extern int centre;
extern int direction;
extern int animation;
int time_to_cry = 0;

//SOUND
uint16_t SinTable[45] =                                       
{
    410, 467, 523, 576, 627, 673, 714, 749, 778,
    799, 813, 819, 817, 807, 789, 764, 732, 694, 
    650, 602, 550, 495, 438, 381, 324, 270, 217,
    169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
    20 , 41 , 70 , 105, 146, 193, 243, 297, 353
};
extern float factor;

int food[3]={1592,1417,1263};
int cuddle[8]={2120,1890,1684,2120,2120,1890,1684,2120};
int leave[5]={2120,1890,1684,1592,1417};
int number_of_note = 1;
int flag = 1;
int i = 0;
int duration = 500;

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Animations (basic, cuddle, leave)
**
******************************************************************************/

void TIMER0_IRQHandler (void)
{
	switch(animation){
		
		case CUDDLES:
			if(LPC_TIM0->IR == 2){
				cuddle2();
				LPC_TIM0->IR = 2;			//Clear Interrupt on MR1
			}			
			if(LPC_TIM0->IR == 1){
				cuddle3();
				happiness = happiness + 25;
				set_happiness(happiness);
				enable_RIT();
				animation = 0;
				number_of_note = 1;
				LPC_TIM0->IR = 1;			//Clear Interrupt on MR0
			}
			break;
			
		case 0:
			if(LPC_TIM0->IR == 2){
				//function for the animation
				basicAnimation();
				LPC_TIM0->IR = 2;			//Clear Interrupt on MR1
			}
			
			if(LPC_TIM0->IR == 1){
				//function for the basic pet
				backTo();
				LPC_TIM0->IR = 1;			//Clear Interrupt on MR0
			}
			break;
			
		case LEAVE:
			if(LPC_TIM0->IR == 2){
				almost_crying();
				LPC_TIM0->IR = 2;			//Clear Interrupt on MR1
			}
			
			if(LPC_TIM0->IR == 1){
				crying();
				LPC_TIM0->IR = 1;			//Clear Interrupt on MR0
			}
			time_to_cry++;
			if(time_to_cry == 6){
				disable_timer(0);
				reset_timer(0);
				number_of_note = 5;
				flag = 0;
				i = number_of_note;
				reset_timer(2);
				enable_timer(2);
				time_to_cry = 0;
				mooncake_profile();
				enable_timer(3);
			}
			break;
			
		default:
			break;
	}
	
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Age counter and happiness/satiety handler
**
******************************************************************************/

void TIMER1_IRQHandler (void)
{
	if(animation == 0){
		time++;
		if(time == 5){
			time = 0;
			happiness = happiness - 25;
			satiety = satiety - 25;
			
			set_happiness(happiness);
			set_satiety(satiety);
			
			if(happiness == 0 || satiety == 0){
				disable_timer(0);
				disable_timer(1);
				disable_RIT();
				animation = LEAVE;
				basic_face();
				reset_timer(0);
				reset_timer(1);
				enable_timer(0);
			}
		}
	}
	
	if(seconds == 59){
		seconds = 0;
		minutes++;
		if(minutes == 60){
			minutes = 0;
			hours++;
		}
	}
	else{
		seconds++;
	}
	
	sprintf(age, "%02d:%02d:%02d", hours, minutes, seconds);
	GUI_Text(120, 10, (uint8_t*) age, Black, White);
	
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}
/******************************************************************************
** Function name:		Timer2_IRQHandler
**
** Descriptions:		Sound
**
******************************************************************************/

void TIMER2_IRQHandler (void)
{
	static int ticks=0;

	if(number_of_note > 1){
		if(flag == 0){
		switch(number_of_note){
			case 3:
				init_timer(2, food[i-1]);
				duration = 2500;
				i--;
				if(i < 0){
					disable_timer(2);
					duration = 500;
					flag = 0;
					LPC_TIM2->IR = 1;			/* clear interrupt flag */
				}
				flag = 1;
				break;
			case 8:
				init_timer(2, cuddle[i-1]);
				duration = 2500;
				i--;
				if(i < 0){
					disable_timer(2);
					duration = 500;
					flag = 0;
					LPC_TIM2->IR = 1;			/* clear interrupt flag */
				}
				flag = 1;
				break;
			case 5:
				init_timer(2, leave[i-1]);
				duration = 2500;
				i--;
				if(i < 0){
					disable_timer(2);
					duration = 500;
					flag = 0;
					LPC_TIM2->IR = 1;			/* clear interrupt flag */
				}
				flag = 1;
				break;					
		}
	}
	 else{
		static int ticks=0;
		if(duration > 0){
			duration--;
			if(LPC_TIM2->IR == 1){
					LPC_DAC->DACR = (SinTable[ticks]<<6)/factor;
					ticks++;
					if(ticks==45) ticks=0;
					LPC_TIM2->IR = 1;			//Clear Interrupt on MR0
				}
		}
		
		else{
			duration = 2500;
			flag = 0;
			LPC_TIM2->IR = 1;			/* clear interrupt flag */
		}
	 }
}		
	else if (number_of_note == 1){
		if(duration > 0){
			duration--;
			if(LPC_TIM2->IR == 1){
					LPC_DAC->DACR = (SinTable[ticks]<<6)/factor;
					ticks++;
					if(ticks==45) ticks=0;
					LPC_TIM2->IR = 1;			//Clear Interrupt on MR0
				}
		}
		
		else{
			disable_timer(2);
			duration = 500;
			flag = 0;
			LPC_TIM2->IR = 1;			/* clear interrupt flag */
		}
}
	
	
  return;
}

/******************************************************************************
** Function name:		Timer3_IRQHandler
**
** Descriptions:		Movement
**
******************************************************************************/

void TIMER3_IRQHandler (void)
{
	if(animation == FOOD){
		switch(direction){
			case LEFT:
				if(centre - 40 > 53)
					centre = move(centre, direction);
				else
					direction = 0;
				break;
			case 0:
				if(time_to_eat == 10){
					number_of_note = 3;
					i = number_of_note;
					enable_timer(2);
					time_to_eat = 0;
					if(food_menu == SNACK)
						set_happiness(happiness);
					else if (food_menu == MEAL)
						set_satiety(satiety);
					LCD_DrawFilledCircle(32, 180, 20, White);
					LCD_DrawFilledCircle(33, 180, 20, White);
					direction = RIGHT;
				}
				else 
					time_to_eat++;
				break;
			case RIGHT:
				if(centre < 120)
					centre = move(centre, direction);
				else{
					number_of_note = 1;
					flag = 0;
					i=0;
					enable_timer(0);
					LCD_DrawFilledCircle(100, 180, 10, Green);
					LCD_DrawFilledCircle(101, 180, 10, Green);
					LCD_DrawHalfCircle(120, 174, 13, Black, DOWN);
					LCD_DrawHalfCircle(120, 175, 13, Black, DOWN);
					LCD_DrawFilledCircle(96, 155, 4, White);
					LCD_DrawFilledCircle(97, 155, 4, White);
					LCD_DrawFilledCircle(135, 155, 4, White);
					LCD_DrawFilledCircle(136, 155, 4, White);
					LCD_DrawFilledCircle(100, 150, 4, Black);
					LCD_DrawFilledCircle(101, 150, 4, Black);
					LCD_DrawFilledCircle(140, 150, 4, Black);
					LCD_DrawFilledCircle(139, 150, 4, Black);
					animation = 0;
					disable_timer(3);
					reset_timer(3);
					enable_RIT();	
				}
				break;
			default:
				break;
		}
}
	else if(animation == LEAVE){
		if(centre < 281)
			centre = leaving(centre);
		else{
			disable_timer(3);
			reset_timer(3);
			LCD_DrawBiggerLine(120, 255, 120, 319, White);
			LCD_DrawThickRectangle(1, 255, 237, 63, Red);
			LCD_DrawRectangle(43, 278, 33, 13, White);
			LCD_DrawRectangle(155, 278, 40, 12, White);
			GUI_Text(100, 280, (uint8_t*) "RESET", Black, White); 
			GUI_Text(25, 140, (uint8_t*) "You didn't take care of", Black, Green);
			GUI_Text(22, 160, (uint8_t*) "Mooncake and he returned", Black, Green);
			GUI_Text(40, 180, (uint8_t*) "to the final space!", Black, Green);
			enable_RIT();
		}
		
	}
		
  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
