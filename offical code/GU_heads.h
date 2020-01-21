#include<stdio.h>
#include<stdbool.h>

#define QUIT 4

#define GAME 1

#define INTRODUCE 2

#define CHANGECOLOR 3

#define TOOMUCH "too much wrong input"

#define TYPEAINT "please type a proper int like 1 or 2"

#define COMPUTER 0

#define PLAYER 1

int getChoice(char* toomuch,char* typeaint,int game,int introduce,int changeColor,int quit);

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

