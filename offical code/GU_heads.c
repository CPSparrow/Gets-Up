//the body of functions
#include<stdio.h>
#include<stdbool.h>
#include<windows.h>

#define STARS "**************"

int getChoice(char* toomuch,char* typeaint,int game,int introduce,int changeColor,int quit){
    unsigned short times;
    unsigned int choice,ch;
    times=choice=ch=0;
    while(1){
        if(times==10){
            printf("%s\n",toomuch);
            return quit;
        }else{
            times++;
            if((ch=scanf("%d",&choice))!=1){
                char hide;
                hide=getchar();
                if('C'==hide){
                    return changeColor;
                }else if('q'==hide||'Q'==hide){
                    return quit;
                }else{
                    printf("%s\n",typeaint);
                    continue;
                }
            }else{
            	//later here should be more
                if(game!=choice&&introduce!=choice){
                    printf("%s\n",typeaint);
                }else{
                    return choice;
                }
            }
        }
    }
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

void accident(void){
	printf("something dangerours happened just now\n");
	printf("and we are sorry to tell you this game have to stop in 3 seconds\n");
	Sleep(3000);
	long long int stop[100000000];
	printf("accident\n");
}

