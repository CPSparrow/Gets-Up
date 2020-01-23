#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include<stdlib.h>

#define QUIT 4

#define GAME 1

#define INTRODUCE 2

#define CHANGE_COLOR 3

#define TOO_MUCH "too much wrong input"

#define TYPE_A_INT "please type a proper int like 1 or 2"

#define COMPUTER 0

#define PLAYER 1

#define DATA_CHANGED 1

#define WRONG_INPUT 2

int getChoice(void);

void gameBody(void);

void putInfo(void);

void changeColor(void);

void putSup(void);

void ending(void);

void beginingSet(void);

int choose(void);

void putOptions(void);

int getOptions(int who);

void act(int option,int who);

void putMenu(void);

int isAlive(void);

void putMenu(void);

void accident(void);

void clean(void);
