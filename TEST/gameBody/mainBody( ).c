//  mainBody.c
//  copyright @ Handsome Coder Studio, 2020

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<time.h>
#include"definations.h"

void clean(void) {
	while(getchar()!='\n') {
		continue;
	}
}

#define COMPUTER 0

#define PLAYER 1

#define TYPE_A_INT "ÇëÊäÈëÒ»¸öÔÚÑ¡Ôñ·¶Î§ÄÚµÄÕûÊý"
//which is done

#define PRESS_TO_EXIT "Çë°´ÈÎÒâ¼üÒÔÍË³ö\n"

void accident(const char* kind) {
	puts(kind);
	printf(PRESS_TO_EXIT);
	getchar();
	exit(EXIT_FAILURE);
}


struct model {
	unsigned short has;
	unsigned short loca;
	unsigned short situ;
	bool aim;
	bool warm;
} man[NUM_PLAYERS];

const char *action[NUM_MAX_OPTIONS]= {
	ACTION_KNIFE,ACTION_SHOOT,ACTION_CRUSH,ACTION_FIRE,ACTION_HIDE,ACTION_MOVE,ACTION_CHANGE,ACTION_OUT_OF_TANK,ACTION_SLEEP,ACTION_HIT,ACTION_TRAP,ACTION_WAKE,ACTION_OUT_OF_TRAP
};



bool isAction[NUM_PLAYERS][NUM_MAX_OPTIONS];

void beginningSet(void);

int maxOptions(const bool who);

void putOptions(void);

int getOption(const bool person);

void act(const int option,const bool person);

int main(void) {
	beginningSet();
	puts("ï¿½ï¿½Ó­ï¿½ï¿½ï¿½ï¿½ gets-up ,ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Òªï¿½Ë³ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½q\n");
	do {
		bool who;
		unsigned int option;
		srand(time(NULL));
		who=rand()%NUM_PLAYERS;
		if(who) {
			putOptions();
		}
		//puts("this is getOptions");
		//getchar();
		option=getOption(who);
		printf("option = %d\n",option);
		act(option,who);
	} while(man[COMPUTER].situ!=false&&man[PLAYER].situ!=false);
}

void beginningSet(void) {
	man[COMPUTER].aim=man[PLAYER].aim = man[COMPUTER].has=man[PLAYER].has = man[COMPUTER].warm=man[PLAYER].warm=false;
	man[COMPUTER].loca=LOCA_COMPUTER;
	man[PLAYER].loca=LOCA_PLAYER;
	man[COMPUTER].situ=man[PLAYER].situ=1;

	int a,b;
	for(a=0; a<2; a++) {
		for(b=0; b<16; b++) {
			isAction[a][b]=0;
		}
	}
	isAction[PLAYER][14]=isAction[COMPUTER][14]=1;
}

void putOptions(void) {
	int j,k;
	puts("ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä»Øºï¿½ï¿½Ë£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ñ¡ï¿½ï¿½Ö®ï¿½ï¿½Ø³ï¿½\n");
	puts("ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ñ¡ï¿½Ä²ï¿½ï¿½ï¿½:\n");
	for(j=0,k=0; j<16; j++) {
		if(isAction[PLAYER][j]) {
			k++;
			printf("%d.%-15s",k,action[j]);
			if(k%3==0) {
				putchar('\n');
			}
		}
		if(k%3!=0) {
			putchar('\n');
		}
	}
}

int maxOptions(const bool who) {
	int index,count;
	for(index=0,count=0; index<16; index++) {
		if(isAction[who][index]) {
			count++;
		}
	}
	return count;
}

int getOption(const bool person) {
	//PLAYER
	if(person) {
		unsigned short times=0;
		while(1) {
			if(10==times) {
				accident("WRONG_INPUT\n");
			} else if(0<=times&&10>times) {
				times++;
				const char first = getchar();

				if('\n' == first) {
					times--;
					continue;
				} else {
					unsigned short option;
					int max = maxOptions(person);

					if(first>='1'&&first<='9') {
						const char second = getchar();
						if(second>='1'&&second<='9') {
							const char third = getchar();
							if(third=='\n') {
								option=10*(first-'0')+second-'0';
								if(option>=10&&option<=max) {
									return option;
								} else {
									puts("ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½Ñ¡ï¿½ï¿½Î§ï¿½Úµï¿½ï¿½ï¿½ï¿½ï¿½");
									continue;
								}
							} else {
								puts(TYPE_A_INT);
								clean();
								continue;
							}
						} else if(second=='\n') {
							option=first-'0';
							if(option<=max) {
								return option;
							} else {
								puts("ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò»ï¿½ï¿½ï¿½Ú·ï¿½Î§ï¿½Úµï¿½ï¿½ï¿½ï¿½ï¿½\n");
								continue;
							}
						} else {
							puts(TYPE_A_INT);
							clean();
							continue;
						}
					} else {
						puts(TYPE_A_INT);
						clean();
						continue;
					}
				}
			} else {
				accident("DATA_CHANGED\n");
			}
		}
	} else {
		//random algorithm
		int max = maxOptions(person);
		srand(time(NULL));
		int options = rand()%max+1;
		return options;
	}
}

int preProcessing(const int option,const bool who){
	unsigned short index;
	unsigned short check = 0;
	for(index = 0; index<16; index++) {
		if(isAction[who][index]) {
			check++;
		}
		if(check == option) {
			break;
		}
	}
	index++;
	return index;
}

void act(const int option,const bool who) {
	//unsigned short choice=preProcessing(option,who);
	puts("act\n");
}

