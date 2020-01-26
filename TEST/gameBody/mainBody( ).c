//  mainBody.c
//  copyright @ Handsome Coder Studio, 2020

/*
situ=0: 没了
situ=1: 正常
situ=2: 打昏
situ=3: 绑住
situ=4: 打昏且绑住
*/

#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include<time.h>

#define COMPUTER 0

#define PLAYER 1

struct model{
	unsigned short has;
	unsigned short loca;
	unsigned short situ;
	bool aim;
	bool warm;
}man[2];

const char *action[16]={
	"fits","knif","shoot","powder","crush","fire","hide","move","change","out of tank","unclose","sleep","hit","trap","wake","out of trap"
	//0       1       2       3        4       5     6     7      8          9             10       11      12   13      14      15
};



bool isAction[2][16];

void beingingSet(void);

int choose();
void putOptions();
int getOptions(who);
void act(option,who);

int main(void){
    bool who;
    unsigned int option;
    beginingSet();
    do {
    	srand(time(NULL));
        who=rand()%2;
        //while who = 1
        //so player = 1
        if(who){
            putOptions();
        }
        option=getOptions(who);
        act(option,who);
    }while(0!=man[0].situ&&0!=man[1].situ);
}

void beingingSet(void){
	man[0].aim=man[1].aim = man[0].has=man[1].has = man[0].warm=man[1].warm=0;
	man[0].loca=0; man[1].loca=1;
	man[0].situ=man[1].situ=1;
	
	int a,b;
	for(a=0;a<2;a++){
		for(b=0;b<16;b++){
			isAction[a][b]=0;
		}
	}
	isAction[0][14]=isAction[1][14]=1;
}

void putOptions(){
	int j,k;
	printf("you can:\n");
	for(j=0;j<16;j++){
		if(isAction[j]){
			printf("%15s",action[j]);
		}
	}
}

