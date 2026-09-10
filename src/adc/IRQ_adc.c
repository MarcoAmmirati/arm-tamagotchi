/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_adc.c
** Last modified Date:  20184-12-30
** Last Version:        V1.00
** Descriptions:        functions to manage A/D interrupts
** Correlated files:    adc.h
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#include <math.h>
#include <stdlib.h>

#include "lpc17xx.h"
#include "adc.h"
#include "../led/led.h"
#include "../timer/timer.h"
#include "../GLCD/GLCD.h"
#include "../functions.h"

/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is ready (signal from ADC peripheral)
 *----------------------------------------------------------------------------*/
unsigned short AD_current;   
unsigned short AD_last = 0xFF;     /* Last converted value               */
unsigned short diff = 0;
void set_volume(unsigned short);
int freqs[8]={2120,1890,1684,1592,1417,1263,1125,1062};
float factor;

/*
262Hz	k=2120		c4
294Hz	k=1890		
330Hz	k=1684		
349Hz	k=1592		
392Hz	k=1417		
440Hz	k=1263		
494Hz	k=1125		
523Hz	k=1062		c5

*/

void ADC_IRQHandler(void) {
	
  AD_current = ((LPC_ADC->ADGDR>>4) & 0xFFF);/* Read Conversion Result             */
	diff = abs(AD_last - AD_current);
	
  if(diff > 200 && diff < 800){
		set_volume(AD_current);
		AD_last = AD_current;
  }	

}

void set_volume(unsigned short AD_current){
			
	
	if(AD_current < 820){
		
		LCD_DrawHalfCircle(24, 20, 3, White, RIGHT);
		LCD_DrawHalfCircle(28, 20, 5, White, RIGHT);
		LCD_DrawHalfCircle(32, 20, 7, White, RIGHT);
		LCD_DrawHalfCircle(36, 20, 9, White, RIGHT);
		factor = 800;
	}
	
	else if (AD_current >= 820 && AD_current < 1638){
		
		LCD_DrawHalfCircle(24, 20, 3, Black, RIGHT);
		LCD_DrawHalfCircle(28, 20, 5, White, RIGHT);
		LCD_DrawHalfCircle(32, 20, 7, White, RIGHT);
		LCD_DrawHalfCircle(36, 20, 9, White, RIGHT);
		factor = 2;
	}
	
	else if (AD_current >= 1638 && AD_current < 2458){
			
		LCD_DrawHalfCircle(24, 20, 3, Black, RIGHT);
		LCD_DrawHalfCircle(28, 20, 5, Black, RIGHT);
		LCD_DrawHalfCircle(32, 20, 7, White, RIGHT);
		LCD_DrawHalfCircle(36, 20, 9, White, RIGHT);
		factor = 3/2;
	}
	
	else if (AD_current >= 2458 && AD_current < 3277){
		
		LCD_DrawHalfCircle(24, 20, 3, Black, RIGHT);
		LCD_DrawHalfCircle(28, 20, 5, Black, RIGHT);
		LCD_DrawHalfCircle(32, 20, 7, Black, RIGHT);
		LCD_DrawHalfCircle(36, 20, 9, White, RIGHT);
		factor = 1;
	}
	
	else if (AD_current >= 3277){
		
		LCD_DrawHalfCircle(24, 20, 3, Black, RIGHT);
		LCD_DrawHalfCircle(28, 20, 5, Black, RIGHT);
		LCD_DrawHalfCircle(32, 20, 7, Black, RIGHT);
		LCD_DrawHalfCircle(36, 20, 9, Black, RIGHT);
		factor = 1/2;
	}
	
}
