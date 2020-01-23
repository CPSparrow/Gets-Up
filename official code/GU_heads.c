//the body of functions
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "GU_heads.h"

#define STARS "**************"

void clean(void){
	while(getchar()!='\n'){
        continue;
	}
}

void accident(int kind){
	switch(kind){
		case DATA_CHANGED:
			printf("data changed\n");
			break;
		case WRONG_INPUT:
			printf("too much input\n");
			break;
		default:
			printf("data changed\n");
			break;
	}
	printf("press to quit\n");
	getchar();
	exit(0);
}


int getchoice(void){
	unsigned short times=0;
	while(1){
		if(10==times){
			accident(WRONG_INPUT);
			return QUIT;
		}else if(0<=times&&10>times){
			times++;
			const char first = getchar();
			if('\n'==first){
				times--;
				continue;
			}
			const char second = getchar();
			if('\n'==second){
				switch(first){
					case '0'+GAME:
						return GAME;
					case '0'+INTRODUCE:
						return INTRODUCE;
					case 'C':
						return CHANGE_COLOR;
					case 'q':
					case 'Q':
						return QUIT;
					default:
						printf("%s\n",TYPE_A_INT);
						break;
				}
			}else{
				clean();
				printf("%s\n",TYPE_A_INT);
			}
		}else{
			accident(DATA_CHANGED);
		}
	}
}

int choose(int COMPUTER,int PLAYER){
    srand(time());
    if(COMPUTER==(rand()%2)){//or ^ | &
        return COMPUTER;
    }else{
        return PLAYER;
    }
}

void putMenu(void){
	printf("\n%s%s%s%s\n",STARS,STARS,STARS,STARS);
	printf("\nwhat do you want to do?\n");
	printf("1) play the game		2) get some introduction\n");
	printf("q) just quit  \n");
	printf("\n%s%s%s%s\n",STARS,STARS,STARS,STARS);
}

void gameBody(void){
    bool who;
    unsigned int option;
    beginingSet();
    while (isAlive())
    {
        who=choose();
        //who = 0 or 1
        //while who = 1
        //so player = 1
        if(who){
            putOptions();
        }
        option=getOptions(who);
        act(option,who);
    }
    
}

