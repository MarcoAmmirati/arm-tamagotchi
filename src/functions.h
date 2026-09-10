#define MEAL 1
#define SNACK 2
#define RIGHT 3
#define LEFT 4
#define UP 5
#define DOWN 6
#define LEAVE 7
#define CUDDLES 8
#define FOOD 9
#define N 10

#include <stdio.h>


void drawStaticMenu(void);
void basicMooncake(void);
void basicAnimation(void);
void backTo(void);
int move(int, int);

void meal(void);
void snack(void);
void basic_face(void);
void crying(void);
void almost_crying(void);
void mooncake_profile(void);
int leaving(int centre);

void set_happiness(int);
void set_satiety(int);

void switch_to_snack(int);
void switch_to_meal(int);

void cuddle1(void);
void cuddle2(void);
void cuddle3(void);
