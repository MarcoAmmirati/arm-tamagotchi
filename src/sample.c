/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           sample.c
** Author: 							Marco Ammirati
** Last modified Date:  08/01/2023
** Descriptions:        starting point of the program used to setup variables and timers
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
                  
#include <stdio.h>

#include "LPC17xx.H"                    /* LPC17xx definitions                */
#include "timer/timer.h"
#include "RIT/RIT.h"
#include "joystick/joystick.h"
#include "GLCD/GLCD.h"
#include "functions.h"
#include "ADC/adc.h"
#include "TouchPanel/TouchPanel.h"


#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

/*	VARIABLES		*/

//AGE
int seconds = 0;
int minutes = 0;
int hours = 0;

//FOOD
int happiness = 100;
int satiety = 100;
int food_menu = 0;

//MOVEMENT
int centre = 120;
int direction = LEFT;
int animation = 0;

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/

int main (void) {
  	
	SystemInit();  												/* System Initialization (i.e., PLL)  */
	LCD_Initialization();									/* LCD Inizialization									*/
	TP_Init();														/* Touch Panel Inizialization					*/	
	TouchPanel_Calibrate();								/* Touch Panel Calibration						*/
	LCD_Clear(White);
	ADC_init();														/* ADC Inizialization								  */


	/*	TIMERS	*/
	init_RIT(0x004C4B40);									/* RIT Initialization 50 msec       	*/
	
	init_timer(0, 0x02FAF080);						// Basic animation of the pet
	LPC_TIM0->MR1 = 0x017D7840;						// MR1 of Timer 0 = 1 sec

	init_timer(1, 0x017D7840);						// Init timer 1 to 1 sec (age of the pet)

  init_timer(3, 0x00055730);					

	basicMooncake();
	drawStaticMenu();

	enable_RIT();													/* RIT enabled												*/
	enable_timer(0);
	enable_timer(1);
	
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);						
		
	LPC_PINCON->PINSEL1 |= (1<<21);
	LPC_PINCON->PINSEL1 &= ~(1<<20);
	LPC_GPIO0->FIODIR |= (1<<26);
	
  while (1) {                           /* Loop forever                       */	
		__ASM("wfi");
  }

}


/******************************************************************************
**                            End Of File
******************************************************************************/
