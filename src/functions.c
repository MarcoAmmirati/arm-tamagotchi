#define MEAL 1
#define SNACK 2
#define RIGHT 3
#define LEFT 4
#define UP 5
#define DOWN 6

#include <stdio.h>

#include "LPC17xx.H"                    /* LPC17xx definitions                */
#include "timer/timer.h"
#include "RIT/RIT.h"
#include "joystick/joystick.h"
#include "GLCD/GLCD.h"

void drawStaticMenu(){
	
	LCD_DrawThickRectangle(1, 255, 237, 63, Black);
	LCD_DrawBiggerLine(120, 255, 120, 319, Black);
	//LCD_DrawThickRectangle(1, 255, 119, 63, Red);
	//LCD_DrawThickRectangle(120, 255, 118, 63, Red);
	GUI_Text(43, 278, (uint8_t*) "Meal", Black, White);
	GUI_Text(155, 278, (uint8_t*) "Snack", Black, White);
	GUI_Text(70, 10, (uint8_t*) "Age: ", Black, White);
	GUI_Text(30, 30, (uint8_t*) "Happiness", Black, White);
	GUI_Text(150, 30, (uint8_t*) "Satiety", Black, White);
	
	//BATTERIES
	LCD_DrawRectangle(43, 57, 7, 15, Black);
	LCD_DrawRectangle(53, 57, 7, 15, Black);
	LCD_DrawRectangle(63, 57, 7, 15, Black);
	LCD_DrawRectangle(73, 57, 7, 15, Black);
	
	//UP
	LCD_DrawLine(38, 51, 84, 51, Black);
	LCD_DrawLine(38, 52, 84, 52, Black);
	LCD_DrawLine(38, 53, 84, 53, Black);
	LCD_DrawLine(38, 54, 84, 54, Black);
	
	//DOWN
	LCD_DrawLine(38, 74, 84, 74, Black);
	LCD_DrawLine(38, 75, 84, 75, Black);
	LCD_DrawLine(38, 76, 84, 76, Black);
	LCD_DrawLine(38, 77, 84, 77, Black);
	
	//LEFT
	LCD_DrawLine(37, 52, 37, 76, Black);
	LCD_DrawLine(38, 52, 38, 76, Black);
	LCD_DrawLine(39, 52, 39, 76, Black);
	LCD_DrawLine(40, 52, 40, 76, Black);

	//RIGHT
	LCD_DrawLine(82, 52, 82, 76, Black);
	LCD_DrawLine(83, 52, 83, 76, Black);
	LCD_DrawLine(84, 52, 84, 76, Black);
	LCD_DrawLine(85, 52, 85, 76, Black);
	
	LCD_DrawRectangle(87, 61, 3, 7, Black); 
	
	/*---------------------*/
	
	LCD_DrawRectangle(158, 57, 7, 15, Black);
	LCD_DrawRectangle(168, 57, 7, 15, Black);
	LCD_DrawRectangle(178, 57, 7, 15, Black);
	LCD_DrawRectangle(188, 57, 7, 15, Black);
	
	//UP
	LCD_DrawLine(153, 51, 199, 51, Black);
	LCD_DrawLine(153, 52, 199, 52, Black);
	LCD_DrawLine(153, 53, 199, 53, Black);
	LCD_DrawLine(153, 54, 199, 54, Black);
	//LCD_DrawLine(35, 58, 81, 58, Black);
	
	//DOWN
	//LCD_DrawLine(35, 76, 81, 76, Black);
	LCD_DrawLine(153, 74, 199, 74, Black);
	LCD_DrawLine(153, 75, 199, 75, Black);
	LCD_DrawLine(153, 76, 199, 76, Black);
	LCD_DrawLine(153, 77, 199, 77, Black);
	
	//LEFT
	LCD_DrawLine(152, 52, 152, 76, Black);
	LCD_DrawLine(153, 52, 153, 76, Black);
	LCD_DrawLine(154, 52, 154, 76, Black);
	LCD_DrawLine(155, 52, 155, 76, Black);
	//LCD_DrawLine(38, 55, 38, 79, Black);

	//RIGHT
	//LCD_DrawLine(78, 55, 78, 79, Black);
	LCD_DrawLine(197, 52, 197, 76, Black);
	LCD_DrawLine(198, 52, 198, 76, Black);
	LCD_DrawLine(199, 52, 199, 76, Black);
	LCD_DrawLine(200, 52, 200, 76, Black);
	
	LCD_DrawRectangle(202, 61, 3, 7, Black);
	
		//ICONA
	LCD_DrawRectangle(7, 10, 15, 20, Black);
	
	LCD_DrawLine(7, 10, 21, 10, White);
	LCD_DrawLine(7, 11, 20, 11, White);
	LCD_DrawLine(7, 12, 19, 12, White);
	LCD_DrawLine(7, 13, 18, 13, White);
	LCD_DrawLine(7, 14, 17, 14, White);
	LCD_DrawLine(7, 15, 16, 15, White);
	
	LCD_DrawLine(7, 29, 21, 29, White);
	LCD_DrawLine(7, 28, 20, 28, White);
	LCD_DrawLine(7, 27, 19, 27, White);
	LCD_DrawLine(7, 26, 18, 26, White);
	LCD_DrawLine(7, 25, 17, 25, White);
	LCD_DrawLine(7, 24, 16, 24, White);

	LCD_DrawRectangle(7, 10, 4, 15, White);
	
}

void basicMooncake(){
	
	// CORPO
	LCD_DrawFilledCircle(119, 160, 40, Green);
	LCD_DrawFilledCircle(121, 160, 40, Green);
	LCD_DrawFilledCircle(120, 160, 40, Green);
		
	// OCCHI
	LCD_DrawFilledCircle(100, 150, 10, White);
	LCD_DrawFilledCircle(101, 150, 10, White);
	LCD_DrawFilledCircle(140, 150, 10, White);
	LCD_DrawFilledCircle(139, 150, 10, White);
	
	LCD_DrawFilledCircle(100, 150, 4, Black);
	LCD_DrawFilledCircle(101, 150, 4, Black);
	LCD_DrawFilledCircle(140, 150, 4, Black);
	LCD_DrawFilledCircle(139, 150, 4, Black);
	
	// ZAMPE
	LCD_DrawFilledCircle(100, 208, 10, Green);
	LCD_DrawFilledCircle(101, 208, 10, Green);
	LCD_DrawFilledCircle(140, 208, 10, Green);
	LCD_DrawFilledCircle(139, 208, 10, Green);

	// ANTENNE
	LCD_DrawRectangle(100, 104, 4, 20, Green);
	LCD_DrawRectangle(135, 104, 4, 20, Green);
	LCD_DrawFilledCircle(101, 100, 3, Green);
	LCD_DrawFilledCircle(102, 100, 3, Green);
	LCD_DrawFilledCircle(136, 100, 3, Green);
	LCD_DrawFilledCircle(137, 100, 3, Green);
	
	// BOCCA
	
	LCD_DrawHalfCircle(120, 174, 13, Black, DOWN);
	LCD_DrawHalfCircle(120, 175, 13, Black, DOWN);
	
}
void basicAnimation(){
	
	// OCCHI
	LCD_DrawCircle(100, 150, 10, Black);
	LCD_DrawCircle(100, 151, 10, Black);
	LCD_DrawCircle(101, 150, 10, Black);
	LCD_DrawCircle(101, 151, 10, Black);
	
	LCD_DrawCircle(140, 150, 10, Black);
	LCD_DrawCircle(140, 151, 10, Black);
	LCD_DrawCircle(139, 150, 10, Black);
	LCD_DrawCircle(139, 151, 10, Black);

	LCD_DrawFilledCircle(100, 152, 10, Green);
	LCD_DrawFilledCircle(100, 153, 10, Green);
	LCD_DrawFilledCircle(140, 152, 10, Green);
	LCD_DrawFilledCircle(140, 153, 10, Green);
	
	// BOCCA
	LCD_DrawFilledCircle(119, 175, 13, Black);
	LCD_DrawFilledCircle(120, 175, 13, Black);
	LCD_DrawFilledCircle(121, 175, 13, Black);
	
	LCD_DrawRectangle(105, 160, 30, 13, Green);
	LCD_DrawRectangle(106, 173, 29, 4, White);
	
}


void backTo(){
	
	// OCCHI
	LCD_DrawCircle(101, 151, 10, White);
	LCD_DrawCircle(139, 151, 10, White);
	
	LCD_DrawFilledCircle(100, 150, 10, White);
	LCD_DrawFilledCircle(101, 150, 10, White);
	LCD_DrawFilledCircle(140, 150, 10, White);
	LCD_DrawFilledCircle(139, 150, 10, White);
	
	LCD_DrawFilledCircle(100, 150, 4, Black);
	LCD_DrawFilledCircle(101, 150, 4, Black);
	LCD_DrawFilledCircle(140, 150, 4, Black);
	LCD_DrawFilledCircle(139, 150, 4, Black);
	
	// BOCCA
	LCD_DrawFilledCircle(119, 175, 13, Green);
	LCD_DrawFilledCircle(120, 175, 13, Green);
	LCD_DrawFilledCircle(121, 175, 13, Green);
	
	LCD_DrawHalfCircle(120, 174, 13, Black, DOWN);
	LCD_DrawHalfCircle(120, 175, 13, Black, DOWN);

}


int move(int centre, int direction){
	
	if(direction == LEFT){
		
		//CORPO
		LCD_DrawHalfCircle(centre + 1, 160, 40, White, RIGHT);
		LCD_DrawHalfCircle(centre - 2, 160, 40, Green, LEFT);
		
		//ORBITE
		LCD_DrawHalfCircle(centre - 19, 150, 10, Green, RIGHT);
		LCD_DrawHalfCircle(centre - 21, 150, 10, White, LEFT);
		LCD_DrawHalfCircle(centre + 20, 150, 10, Green, RIGHT);
		LCD_DrawHalfCircle(centre + 18, 150, 10, White, LEFT);
		
		//PUPILLE
		LCD_DrawHalfCircle(centre - 22, 155, 4, White, RIGHT);
		LCD_DrawHalfCircle(centre - 24, 155, 4, Black, LEFT); 
		LCD_DrawHalfCircle(centre + 17, 155, 4, White, RIGHT);
		LCD_DrawHalfCircle(centre + 15, 155, 4, Black, LEFT);
		
		//BOCCA
		LCD_DrawHalfCircle(centre - 19, 180, 9, Green, RIGHT);
		LCD_DrawHalfCircle(centre - 21, 180, 9, Black, LEFT);
		
		//ZAMPE
		LCD_DrawHalfCircle(centre - 19, 208, 10, White, RIGHT);
		LCD_DrawHalfCircle(centre - 21, 208, 10, Green, LEFT);
		LCD_DrawHalfCircle(centre + 20, 208, 10, White, RIGHT);
		LCD_DrawHalfCircle(centre + 18, 208, 10, Green, LEFT);

		//ANTENNE
		LCD_DrawLine(centre - 17 , 104, centre - 17, 122, White);
		LCD_DrawHalfCircle(centre - 18, 100, 3, White, RIGHT);
		LCD_DrawLine(centre - 21 , 100, centre - 21, 124, Green);
		LCD_DrawHalfCircle(centre - 20, 100, 3, Green, LEFT);
		
		LCD_DrawLine(centre + 18 , 104, centre + 18, 124, White);
		LCD_DrawHalfCircle(centre + 17, 100, 3, White, RIGHT);
		LCD_DrawLine(centre + 14 , 100, centre + 14, 124, Green);
	  LCD_DrawHalfCircle(centre + 15, 100, 3, Green, LEFT);
		
		
		centre--;
		
	}
	
	else if(direction == RIGHT){
		
		//CORPO
		LCD_DrawHalfCircle(centre + 1, 160, 40, Green, RIGHT);
		LCD_DrawHalfCircle(centre - 2, 160, 40, White, LEFT);
		
		//PUPILLE
		LCD_DrawHalfCircle(centre - 24, 155, 4, White, LEFT);
		LCD_DrawHalfCircle(centre - 22, 155, 4, Black, RIGHT);
		LCD_DrawHalfCircle(centre + 15, 155, 4, White, LEFT);
		LCD_DrawHalfCircle(centre + 17, 155, 4, Black, RIGHT);

		
		//ORBITE
		LCD_DrawHalfCircle(centre - 19, 150, 10, White, RIGHT);
		LCD_DrawHalfCircle(centre - 21, 150, 10, Green, LEFT);
		LCD_DrawHalfCircle(centre + 20, 150, 10, White, RIGHT);
		LCD_DrawHalfCircle(centre + 18, 150, 10, Green, LEFT);
		

		//BOCCA
		LCD_DrawHalfCircle(centre - 19, 180, 9, Black, RIGHT);
		LCD_DrawHalfCircle(centre - 21, 180, 9, Green, LEFT);
		
		//ZAMPE
		LCD_DrawHalfCircle(centre - 19, 208, 10, Green, RIGHT);
		LCD_DrawHalfCircle(centre - 21, 208, 10, White, LEFT);
		LCD_DrawHalfCircle(centre + 20, 208, 10, Green, RIGHT);
		LCD_DrawHalfCircle(centre + 18, 208, 10, White, LEFT);

		//ANTENNE
		LCD_DrawLine(centre - 17 , 104, centre - 17, 124, Green);
		LCD_DrawHalfCircle(centre - 18, 100, 3, Green, RIGHT);
		LCD_DrawLine(centre - 21 , 104, centre - 21, 124, White);
		LCD_DrawHalfCircle(centre - 20, 100, 3, White, LEFT);
		
		LCD_DrawLine(centre + 18 , 104, centre + 18, 124, Green);
		LCD_DrawHalfCircle(centre + 17, 100, 3, Green, RIGHT);
		LCD_DrawLine(centre + 14 , 100, centre + 14, 120, White);
	  LCD_DrawHalfCircle(centre + 15, 100, 3, White, LEFT);
		
		centre++;
		
	}
	
	return centre;
}

void meal(){
	
	//MEAL
	LCD_DrawFilledCircle(32, 180, 20, Blue);
	LCD_DrawFilledCircle(33, 180, 20, Blue);
	
	LCD_DrawFilledCircle(30, 180, 10, Red);
	LCD_DrawFilledCircle(31, 180, 10, Red);
	LCD_DrawFilledCircle(32, 180, 10, Red);
	LCD_DrawFilledCircle(33, 180, 10, Red);
	LCD_DrawFilledCircle(34, 180, 10, Red);
	LCD_DrawFilledCircle(35, 180, 10, Red);
	LCD_DrawRectangle(20, 180, 26, 11, White);
	LCD_DrawLine(20, 180, 46, 180, Black);
	LCD_DrawRectangle(31, 170, 4, 21, Black);
	
	// MOONCAKE'S FACE
	LCD_DrawFilledCircle(100, 150, 10, White);
	LCD_DrawFilledCircle(101, 150, 10, White);
	LCD_DrawFilledCircle(140, 150, 10, White);
	LCD_DrawFilledCircle(139, 150, 10, White);
	
	LCD_DrawFilledCircle(97, 155, 4, Black);
	LCD_DrawFilledCircle(98, 155, 4, Black);
	LCD_DrawFilledCircle(136, 155, 4, Black);
	LCD_DrawFilledCircle(137, 155, 4, Black);
	
	LCD_DrawFilledCircle(119, 175, 13, Green);
	LCD_DrawFilledCircle(120, 175, 13, Green);
	LCD_DrawFilledCircle(121, 175, 13, Green);
	
	LCD_DrawFilledCircle(100, 180, 9, Black);
	LCD_DrawFilledCircle(101, 180, 9, Black);
	

}

void snack(){
	
	//SNACK
	
	LCD_DrawRectangle(15, 180, 20, 15, Red);
	LCD_DrawRectangle(15, 187, 3, 8, White);
	LCD_DrawRectangle(32, 187, 3, 8, White);
	
	LCD_DrawRectangle(15, 172, 4, 8, Black);
	LCD_DrawRectangle(16, 173, 2, 6, Yellow);
	
	LCD_DrawRectangle(19, 170, 4, 11, Black);
	LCD_DrawRectangle(20, 171, 2, 9, Yellow);
	
	LCD_DrawRectangle(23, 168, 4, 14, Black);
	LCD_DrawRectangle(24, 169, 2, 12, Yellow);
	
	LCD_DrawRectangle(27, 170, 4, 11, Black);
	LCD_DrawRectangle(28, 171, 2, 9, Yellow);
	
	LCD_DrawRectangle(31, 172, 4, 8, Black);
	LCD_DrawRectangle(32, 173, 2, 6, Yellow);
	
	// MOONCAKE'S FACE
	LCD_DrawFilledCircle(100, 150, 10, White);
	LCD_DrawFilledCircle(101, 150, 10, White);
	LCD_DrawFilledCircle(140, 150, 10, White);
	LCD_DrawFilledCircle(139, 150, 10, White);
	
	LCD_DrawFilledCircle(97, 155, 4, Black);
	LCD_DrawFilledCircle(98, 155, 4, Black);
	LCD_DrawFilledCircle(136, 155, 4, Black);
	LCD_DrawFilledCircle(137, 155, 4, Black);
	
	LCD_DrawFilledCircle(119, 175, 13, Green);
	LCD_DrawFilledCircle(120, 175, 13, Green);
	LCD_DrawFilledCircle(121, 175, 13, Green);
	
	LCD_DrawFilledCircle(100, 180, 9, Black);
	LCD_DrawFilledCircle(101, 180, 9, Black);
	
}

void basic_face(){
	
	//OCCHI
	LCD_DrawFilledCircle(100, 150, 10, White);
	LCD_DrawFilledCircle(101, 150, 10, White);
	LCD_DrawFilledCircle(140, 150, 10, White);
	LCD_DrawFilledCircle(139, 150, 10, White);
	
	LCD_DrawFilledCircle(100, 150, 4, Black);
	LCD_DrawFilledCircle(101, 150, 4, Black);
	LCD_DrawFilledCircle(140, 150, 4, Black);
	LCD_DrawFilledCircle(139, 150, 4, Black);
	
	//BOCCA
	LCD_DrawFilledCircle(119, 175, 13, Green);
	LCD_DrawFilledCircle(120, 175, 13, Green);
	LCD_DrawFilledCircle(121, 175, 13, Green);
	
	LCD_DrawLine(100, 180, 140, 180, Black);
	LCD_DrawLine(100, 181, 140, 181, Black);
}

void crying(){
	
	//OCCHI
	LCD_DrawFilledCircle(100, 150, 10, Green);
	LCD_DrawFilledCircle(101, 150, 10, Green);
	LCD_DrawFilledCircle(140, 150, 10, Green);
	LCD_DrawFilledCircle(139, 150, 10, Green);
	
	LCD_DrawHalfCircle(100, 150, 10, Black, UP);
	LCD_DrawHalfCircle(100, 151, 10, Black, UP);
	LCD_DrawHalfCircle(140, 150, 10, Black, UP);
	LCD_DrawHalfCircle(140, 151, 10, Black, UP);
	
	//LACRIME
	LCD_DrawFilledCircle(93, 152, 2, Cyan);
	LCD_DrawFilledCircle(94, 153, 2, Cyan);
	
	LCD_DrawFilledCircle(90, 157, 2, Cyan);
	LCD_DrawFilledCircle(91, 157, 2, Cyan);
	
	LCD_DrawFilledCircle(88, 165, 2, Cyan);
	LCD_DrawFilledCircle(89, 165, 2, Cyan);
	
	LCD_DrawFilledCircle(86, 173, 2, Cyan); 
	LCD_DrawFilledCircle(87, 173, 2, Cyan);
	
	LCD_DrawFilledCircle(143, 152, 2, Cyan);
	LCD_DrawFilledCircle(144, 153, 2, Cyan);
	
	LCD_DrawFilledCircle(150, 157, 2, Cyan);
	LCD_DrawFilledCircle(151, 157, 2, Cyan);
	
	LCD_DrawFilledCircle(153, 165, 2, Cyan);
	LCD_DrawFilledCircle(154, 165, 2, Cyan);
	
	LCD_DrawFilledCircle(156, 173, 2, Cyan);
	LCD_DrawFilledCircle(157, 173, 2, Cyan);
}

void almost_crying(){
	
	//OCCHI
	LCD_DrawFilledCircle(100, 150, 10, White);
	LCD_DrawFilledCircle(101, 150, 10, White);
	LCD_DrawFilledCircle(140, 150, 10, White);
	LCD_DrawFilledCircle(139, 150, 10, White);
	
	//PUPILLE
	LCD_DrawFilledCircle(100, 148, 4, Black);
	LCD_DrawFilledCircle(101, 148, 4, Black);
	LCD_DrawFilledCircle(140, 148, 4, Black);
	LCD_DrawFilledCircle(139, 148, 4, Black);
	
	//OCCHI
	LCD_DrawFilledCircle(100, 160, 10, Green);
	LCD_DrawFilledCircle(101, 160, 10, Green);
	LCD_DrawFilledCircle(140, 160, 10, Green);
	LCD_DrawFilledCircle(139, 160, 10, Green);
	
	//BOCCA
	LCD_DrawLine(100, 180, 140, 180, Green);
	LCD_DrawLine(100, 181, 140, 181, Green);
	
	LCD_DrawHalfCircle(120, 180, 13, Black, UP);
	LCD_DrawHalfCircle(120, 181, 13, Black, UP);
	
	//LACRIME
	LCD_DrawFilledCircle(90, 157, 2, Green);
	LCD_DrawFilledCircle(91, 157, 2, Green);
	
	LCD_DrawFilledCircle(88, 165, 2, Green);
	LCD_DrawFilledCircle(89, 165, 2, Green);
	
	LCD_DrawFilledCircle(86, 173, 2, Green); 
	LCD_DrawFilledCircle(87, 173, 2, Green);
	
	LCD_DrawFilledCircle(150, 157, 2, Green);
	LCD_DrawFilledCircle(151, 157, 2, Green);
	
	LCD_DrawFilledCircle(153, 165, 2, Green);
	LCD_DrawFilledCircle(154, 165, 2, Green);
	
	LCD_DrawFilledCircle(155, 173, 2, Green);
	LCD_DrawFilledCircle(156, 173, 2, Green);
}


void mooncake_profile(){
	
	/*CANCELLARE*/
	//OCCHIO SINISTRO
	LCD_DrawFilledCircle(99, 150, 10, Green);
	LCD_DrawFilledCircle(100, 150, 10, Green);
	LCD_DrawFilledCircle(101, 150, 10, Green);

	//BOCCA
	LCD_DrawHalfCircle(120, 180, 13, Green, UP);
	LCD_DrawHalfCircle(120, 181, 13, Green, UP);	
	
	//ZAMPE
	LCD_DrawHalfCircle(99, 208, 10, White, LEFT);
	LCD_DrawFilledCircle(100, 208, 10, White);
	LCD_DrawFilledCircle(101, 208, 10, White);
	LCD_DrawFilledCircle(140, 208, 10, White);
	LCD_DrawFilledCircle(139, 208, 10, White);
	LCD_DrawHalfCircle(138, 208, 10, White, LEFT);
	
	//LACRIME
	LCD_DrawFilledCircle(93, 152, 2, Green);
	LCD_DrawFilledCircle(94, 153, 2, Green);
	
	LCD_DrawFilledCircle(90, 157, 2, Green);
	LCD_DrawFilledCircle(91, 157, 2, Green);
	
	LCD_DrawFilledCircle(88, 165, 2, Green);
	LCD_DrawFilledCircle(89, 165, 2, Green);
	
	LCD_DrawFilledCircle(86, 173, 2, Green); 
	LCD_DrawFilledCircle(87, 173, 2, Green);
	
	LCD_DrawFilledCircle(143, 152, 2, Green);
	LCD_DrawFilledCircle(144, 153, 2, Green);
	
	LCD_DrawFilledCircle(150, 157, 2, Green);
	LCD_DrawFilledCircle(151, 157, 2, Green);
	
	LCD_DrawFilledCircle(153, 165, 2, Green);
	LCD_DrawFilledCircle(154, 165, 2, Green);
	
	LCD_DrawFilledCircle(155, 173, 2, Green);
	LCD_DrawFilledCircle(156, 173, 2, Green);
	
	//ANTENNA SINISTRA
	LCD_DrawRectangle(99, 104, 5, 20, White);
	LCD_DrawFilledCircle(99, 100, 3, White);
	LCD_DrawFilledCircle(101, 100, 3, White);
	LCD_DrawFilledCircle(102, 100, 3, White);

	/*DISEGNARE*/
	//OCCHIO
	LCD_DrawFilledCircle(140, 150, 10, White);
	LCD_DrawFilledCircle(139, 150, 10, White);

	LCD_DrawFilledCircle(143, 154, 4, Black);
	LCD_DrawFilledCircle(144, 154, 4, Black);
	
	LCD_DrawFilledCircle(120, 209, 10, Green);
	LCD_DrawFilledCircle(121, 209, 10, Green);
	
	LCD_DrawHalfCircle2(157, 185, 15, Black);
	LCD_DrawHalfCircle2(158, 185, 15, Black);

}

int leaving(int centre){
	
	//CORPO
		LCD_DrawHalfCircle(centre + 1, 160, 40, Green, RIGHT);
		LCD_DrawHalfCircle(centre - 2, 160, 40, White, LEFT);
	//ZAMPA
		LCD_DrawHalfCircle(centre + 2, 209, 10, Green, RIGHT);
	  LCD_DrawHalfCircle(centre, 209, 10, White, LEFT);
		
	//OCCHIO
		LCD_DrawHalfCircle(centre + 21, 150, 10, White, RIGHT);
		LCD_DrawHalfCircle(centre + 18, 150, 10, Green, LEFT);
	  LCD_DrawHalfCircle(centre + 19, 150, 10, Green, LEFT);
	
		LCD_DrawHalfCircle(centre + 25, 154, 4, Black, RIGHT);
	  LCD_DrawHalfCircle(centre + 23, 154, 4, White, LEFT);
	
	//BOCCA
		LCD_DrawHalfCircle2(centre + 37, 185, 15, Green);
	  LCD_DrawHalfCircle2(centre + 39, 185, 15, Black);
	
	//ANTENNA
	LCD_DrawLine(centre + 14 , 104, centre + 14, 120, White);
	LCD_DrawLine(centre + 18 , 100, centre + 18, 124, Green);
	
	LCD_DrawHalfCircle(centre + 17, 100, 3, Green, RIGHT);
	LCD_DrawHalfCircle(centre + 15, 100, 3, White, LEFT);
	
	centre++;
	return centre;
}

void set_happiness(int happiness){
	
			switch(happiness){
				case 0:
					LCD_DrawRectangle(43, 57, 7, 15, White);
					LCD_DrawRectangle(53, 57, 7, 15, White);
					LCD_DrawRectangle(63, 57, 7, 15, White);
					LCD_DrawRectangle(73, 57, 7, 15, White);
					break;
				case 25:
					LCD_DrawRectangle(43, 57, 7, 15, Black);
					LCD_DrawRectangle(53, 57, 7, 15, White);
					LCD_DrawRectangle(63, 57, 7, 15, White);
					LCD_DrawRectangle(73, 57, 7, 15, White);					
					break;
				case 50:
					LCD_DrawRectangle(43, 57, 7, 15, Black);
					LCD_DrawRectangle(53, 57, 7, 15, Black);
					LCD_DrawRectangle(63, 57, 7, 15, White);
					LCD_DrawRectangle(73, 57, 7, 15, White);					
					break;
				case 75:
					LCD_DrawRectangle(43, 57, 7, 15, Black);
					LCD_DrawRectangle(53, 57, 7, 15, Black);
					LCD_DrawRectangle(63, 57, 7, 15, Black);
					LCD_DrawRectangle(73, 57, 7, 15, White);					
					break;
				case 100:
					LCD_DrawRectangle(43, 57, 7, 15, Black);
					LCD_DrawRectangle(53, 57, 7, 15, Black);
					LCD_DrawRectangle(63, 57, 7, 15, Black);
					LCD_DrawRectangle(73, 57, 7, 15, Black);					
					break;
				default:
					break;
		}
}

void set_satiety(int satiety){
	
				switch(satiety){
				case 0:
					LCD_DrawRectangle(158, 57, 7, 15, White);
					LCD_DrawRectangle(168, 57, 7, 15, White);
					LCD_DrawRectangle(178, 57, 7, 15, White);
					LCD_DrawRectangle(188, 57, 7, 15, White);		
					break;
				case 25:
					LCD_DrawRectangle(158, 57, 7, 15, Black);
					LCD_DrawRectangle(168, 57, 7, 15, White);
					LCD_DrawRectangle(178, 57, 7, 15, White);
					LCD_DrawRectangle(188, 57, 7, 15, White);						
					break;
				case 50:
					LCD_DrawRectangle(158, 57, 7, 15, Black);
					LCD_DrawRectangle(168, 57, 7, 15, Black);
					LCD_DrawRectangle(178, 57, 7, 15, White);
					LCD_DrawRectangle(188, 57, 7, 15, White);		
					break;
				case 75:
					LCD_DrawRectangle(158, 57, 7, 15, Black);
					LCD_DrawRectangle(168, 57, 7, 15, Black);
					LCD_DrawRectangle(178, 57, 7, 15, Black);
					LCD_DrawRectangle(188, 57, 7, 15, White);				
					break;
				case 100:
					LCD_DrawRectangle(158, 57, 7, 15, Black);
					LCD_DrawRectangle(168, 57, 7, 15, Black);
					LCD_DrawRectangle(178, 57, 7, 15, Black);
					LCD_DrawRectangle(188, 57, 7, 15, Black);				
					break;
				default:
					break;
		}
}

void switch_to_snack(int selection){
	
	if(selection == 0){
		LCD_DrawThickRectangle(120, 255, 118, 63, Red);
	}
	else if(selection == MEAL){
		LCD_DrawThickRectangle(1, 255, 119, 63, Black);
		LCD_DrawThickRectangle(120, 255, 118, 63, Red);
	}
}

void switch_to_meal(int selection){
	
	if(selection == 0){
		LCD_DrawThickRectangle(1, 255, 119, 63, Red);
	}
	
	else if(selection == SNACK){
		LCD_DrawThickRectangle(120, 255, 118, 63, Black);
		LCD_DrawThickRectangle(1, 255, 119, 63, Red);
	}
}

void cuddle1(){

	//OCCHI
	LCD_DrawFilledCircle(100, 150, 10, White);
	LCD_DrawFilledCircle(101, 150, 10, White);
	LCD_DrawFilledCircle(140, 150, 10, White);
	LCD_DrawFilledCircle(139, 150, 10, White);
	
	//PUPILLE
	LCD_DrawFilledCircle(100, 148, 4, Black);
	LCD_DrawFilledCircle(101, 148, 4, Black);
	LCD_DrawFilledCircle(140, 148, 4, Black);
	LCD_DrawFilledCircle(139, 148, 4, Black);
	
	//OCCHI
	LCD_DrawFilledCircle(100, 160, 10, Green);
	LCD_DrawFilledCircle(101, 160, 10, Green);
	LCD_DrawFilledCircle(140, 160, 10, Green);
	LCD_DrawFilledCircle(139, 160, 10, Green);
	
	//LUCCICHII
	LCD_SetPixel(99, 147, White);
	LCD_SetPixel(138, 147, White);
	
	//GUANCE
	LCD_DrawFilledCircle(90, 165, 6, Red);
	LCD_DrawFilledCircle(91, 165, 6, Red);
	LCD_DrawFilledCircle(149, 165, 6, Red);
	LCD_DrawFilledCircle(150, 165, 6, Red);
	
	//BOCCA
	LCD_DrawFilledCircle(119, 175, 13, Green);
	LCD_DrawFilledCircle(120, 175, 13, Green);
	LCD_DrawFilledCircle(121, 175, 13, Green);
	
	LCD_DrawHalfCircle(120, 174, 13, Black, DOWN);
	LCD_DrawHalfCircle(120, 175, 13, Black, DOWN);

}

void cuddle2(){
	
	//OCCHI
	LCD_DrawFilledCircle(100, 150, 10, Green);
	LCD_DrawFilledCircle(101, 150, 10, Green);
	LCD_DrawFilledCircle(140, 150, 10, Green);
	LCD_DrawFilledCircle(139, 150, 10, Green);
	
	LCD_DrawHalfCircle(100, 150, 10, Black, UP);
	LCD_DrawHalfCircle(100, 151, 10, Black, UP);
	LCD_DrawHalfCircle(140, 150, 10, Black, UP);
	LCD_DrawHalfCircle(140, 151, 10, Black, UP);
	
	//BOCCA
	LCD_DrawFilledCircle(119, 175, 13, Black);
	LCD_DrawFilledCircle(120, 175, 13, Black);
	LCD_DrawFilledCircle(121, 175, 13, Black);
	
	LCD_DrawRectangle(105, 160, 30, 13, Green);
	LCD_DrawRectangle(106, 173, 29, 4, White);
	
	//CUORI
	heart(65, 145, Red);
	heart(165, 145, Red);
}

void cuddle3(){

	//OCCHI
	LCD_DrawFilledCircle(100, 150, 10, White);
	LCD_DrawFilledCircle(101, 150, 10, White);
	LCD_DrawFilledCircle(140, 150, 10, White);
	LCD_DrawFilledCircle(139, 150, 10, White);
	
	//PUPILLE
	LCD_DrawFilledCircle(100, 148, 4, Black);
	LCD_DrawFilledCircle(101, 148, 4, Black);
	LCD_DrawFilledCircle(140, 148, 4, Black);
	LCD_DrawFilledCircle(139, 148, 4, Black);
	
	//OCCHI
	LCD_DrawFilledCircle(100, 160, 10, Green);
	LCD_DrawFilledCircle(101, 160, 10, Green);
	LCD_DrawFilledCircle(140, 160, 10, Green);
	LCD_DrawFilledCircle(139, 160, 10, Green);
	
	//LUCCICHII
	LCD_SetPixel(99, 147, White);
	LCD_SetPixel(138, 147, White);
	
	//GUANCE
	LCD_DrawFilledCircle(90, 165, 6, Green);
	LCD_DrawFilledCircle(91, 165, 6, Green);
	LCD_DrawFilledCircle(149, 165, 6, Green);
	LCD_DrawFilledCircle(150, 165, 6, Green);
	
	//CUORI
	heart(65, 145, White);
	heart(165, 145, White);
	
	// BOCCA
	LCD_DrawFilledCircle(119, 175, 13, Green);
	LCD_DrawFilledCircle(120, 175, 13, Green);
	LCD_DrawFilledCircle(121, 175, 13, Green);
	
	LCD_DrawHalfCircle(120, 174, 13, Black, DOWN);
	LCD_DrawHalfCircle(120, 175, 13, Black, DOWN);

}
